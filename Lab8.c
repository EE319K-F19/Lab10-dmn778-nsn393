// Lab8.c
// Runs on LM4F120 or TM4C123
// Student names: Neil Narvekar
// Last modification date: 11/10/2019
// Last Modified: 9/2/2019 

// Specifications:
// Measure distance using slide pot, sample at 60 Hz
// maximum distance can be any value from 1.5 to 2cm
// minimum distance is 0 cm
// Calculate distance in fixed point, 0.01cm
// Analog Input connected to PD2=ADC5
// displays distance on Sitronox ST7735
// PF3, PF2, PF1 are heartbeats (use them in creative ways)
// 

#include <stdint.h>

#include "ST7735.h"
#include "TExaS.h"
#include "ADC.h"
#include "Images.h"
#include "print.h"
#include "../inc/tm4c123gh6pm.h"

//*****the first three main programs are for debugging *****
// main1 tests just the ADC and slide pot, use debugger to see data
// main2 adds the LCD to the ADC and slide pot, ADC data is on ST7735
// main3 adds your convert function, position data is no ST7735

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
uint32_t xADC_In(void);
uint32_t yADC_In(void);
void SysTick_Init(void);

#define PF1       (*((volatile uint32_t *)0x40025008))
#define PF2       (*((volatile uint32_t *)0x40025010))
#define PF3       (*((volatile uint32_t *)0x40025020))

void PortF_Init(void){
	SYSCTL_RCGCGPIO_R |= 0x20; // port f clock
	while((SYSCTL_RCGCGPIO_R & 0x20) != 0x20){}
		GPIO_PORTF_DIR_R |= 0x0E; //pf1,pf2,pf3 heartbeat output
		GPIO_PORTF_DEN_R |= 0x0E; //enable 
		GPIO_PORTF_PUR_R |= 0x0E; //pull up resistor

}

//********************************************************************************** 
// GAME STARTS HERE

// GLOBAL VARIABLES
uint32_t Data;        // 12-bit ADC
int32_t pos;    // 32-bit fixed-point 0.001 cm
int32_t xPosition, yPosition;

int32_t ADCStatus=0; // 1 means new data available
int32_t xADCMail,yADCMail;;
int32_t x=40, y=20, move = 0;

// struct to hold sprite data
struct State{
	int32_t x; // x position
	int32_t y; // y position
	const unsigned short *image; // ptr to image
	uint32_t width; // width
	uint32_t height; // height
	int32_t xvelocity;
	int32_t yvelocity;
};

typedef struct State StateType;
StateType sprite[3] = {
	{0,10, naruto, 16, 18}, // Player sprite
	{30, 32, SmallEnemy10pointA, 16,10},
	{30, 32, SmallEnemy10pointA, 16,10,1,1}
};

uint32_t Convert(uint32_t input){
	// converts ADC value into a position output
	// starts 2000, right max = 4000, left max = 0. up max = 0, down max = 4000
	pos = ((input+100)/2000) - 1; 
  return pos; 
}

void SysTick_Handler(void){
	// SysTick_Handler samples the ADC
	GPIO_PORTF_DATA_R ^= 0x04;
	xADCMail = yADC_In();
	yADCMail = xADC_In();
	ADCStatus = 1;

}
void DrawPlayer(void){
	sprite[0].x = sprite[0].x - xPosition;
	sprite[0].y = sprite[0].y - yPosition; // subtract because y is flipped on joystick for some reason
	ST7735_DrawBitmap(sprite[0].x, sprite[0].y, sprite[0].image, sprite[0].width,sprite[0].height);	
}

void DrawBoss(void){
	sprite[1].x = sprite[1].x;
	sprite[1].y = sprite[1].y; 
	ST7735_DrawBitmap(sprite[1].x, sprite[1].y, sprite[1].image, sprite[1].width,sprite[1].height);	
}

void DrawAttack(num){
	sprite[num].x = sprite[num].x + sprite[num].xvelocity;
	sprite[num].y = sprite[num].y + sprite[num].yvelocity;; 
	ST7735_DrawBitmap(sprite[num].x, sprite[num].y, sprite[num].image, sprite[num].width,sprite[num].height);	
}


//check collision method
//returns 1 if collision between the two sprites is detected
//0 otherwise
int CheckCollision(struct State *rect1, struct State *rect2){
	int32_t r1_x = rect1->x + 2; //to account for 2 pixel wide black rectangle on each side of sprite
	int32_t r1_y = rect1->y + 1; // 1 pixel wide rectangle above and below
	int32_t r2_x = rect2->x + 2;
	int32_t r2_y = rect2->y + 1;
	uint32_t r1_width = rect1->width - 4;
	uint32_t r1_height = rect1->height - 2;
	uint32_t r2_width = rect2->width - 4;
	uint32_t r2_height = rect2->height - 2;
	if (r1_x < r2_x + r2_width &&
   r1_x + r1_width > r2_x&&
   r1_y < r2_y + r2_height &&
   r1_y + r1_height > r2_y) {
    // collision detected!
		 return 1;
	}
	 return 0;
}


int main(void){
  DisableInterrupts();
  //PLL_Init(Bus80MHz);       // Bus clock is 80 MHz 
  //Random_Init(1);
  Output_Init();
	PortF_Init();
	ADC_Init();
	SysTick_Init();
  EnableInterrupts();
	//ST7735_InitR(INITR_REDTAB); 
  ST7735_FillScreen(0x00);            // set screen to black

  ST7735_DrawBitmap(52, 159, ns, 18,8); // player ship middle bottom
  ST7735_DrawBitmap(53, 151, Bunker0, 18,5);

  //ST7735_DrawBitmap(0, 9, SmallEnemy10pointA, 16,10);
  //ST7735_DrawBitmap(40, 9, SmallEnemy20pointA, 16,10);
  //ST7735_DrawBitmap(100, 9, SmallEnemy30pointB, 16,10);
while(1){
	while(ADCStatus != 1){}
		
		// ***** NEXT PART IS FOR TESTING
		//x
    xPosition = Convert(xADCMail); 
		ADCStatus = 0; // clear flag
		
		ST7735_SetCursor(0,4);
		ST7735_OutString(" x ADC Value:");
		
		ST7735_SetCursor(0,6);
    LCD_OutDec(xADCMail); // show adc value 
		
		//y
		yPosition = Convert(yADCMail); 
		ADCStatus = 0; // clear flag
		
		ST7735_SetCursor(0,8);
		ST7735_OutString(" y ADC Value:");
		
		ST7735_SetCursor(0,10);
		LCD_OutDec(yADCMail);
		//************* END OF TESTING PART*********
		
		// ** DRAWING SPRITES STARTS HERE
		DrawPlayer();
		DrawBoss();
		DrawAttack(2);
		if(CheckCollision(&sprite[0], &sprite[1]) == 1){
			ST7735_SetCursor(2,1);
			ST7735_OutString("Collision!");
		}


	}
}

