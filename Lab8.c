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
//#include "TExaS.h"
#include "ADC.h"
#include "Images.h"
#include "print.h"
#include "../inc/tm4c123gh6pm.h"
#include "Random.h"
#include "PLL.h"
#include "IO.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void Timer0A_Init(uint32_t period);
void Timer1A_Init(uint32_t period);
uint32_t xADC_In(void);
uint32_t yADC_In(void);
void SysTick_Init(void);
void PortF_Init(void);
uint32_t button(void);
void DrawBossAttack(void);
void DAC_Out(uint32_t data);
void ClearAttacks(void);


//********************************************************************************** 
// GAME STARTS HERE

// GLOBAL VARIABLES
uint32_t Data;        // 12-bit ADC
int32_t pos;    // 32-bit fixed-point 0.001 cm
int32_t xPosition, yPosition;
uint32_t piazza = 1;
int32_t ADCStatus=0; // 1 means new data available
int32_t xADCMail,yADCMail;

// struct to hold sprite data
struct State{
	int32_t x; // x position
	int32_t y; // y position
	const unsigned short *image; // ptr to image
	const unsigned short *dead; // ptr to image
	const int32_t width; // width
	const int32_t height; // height
	int32_t xvelocity;
	int32_t yvelocity;
	uint8_t moving;
	int8_t health;
};

typedef struct State StateType;
StateType sprite[2] = {
	{60,120, naruto,0, 14,16,0,0,0,15}, // Player s`prite
	{60, 32, guitar_small,blackSmallEnemy10pointA, guitarwidth,guitarheight,0,0,0,15}, // Boss Sprite
};

const uint32_t PlayerAttackStructSize = 15;
// MAX AMOUNT OF PLAYER ATTACKS = PlayerAttackStructSize
typedef struct State StateType;
StateType PlayerAttack[PlayerAttackStructSize] = {
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack 1
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack 2
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack ... etc.
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack     
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack 
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack 
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack 
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack 
	{0, 0, playerattack,deadplayerattack,playerattackwidth,playerattackheight,0,-1,0}, // Player attack 
};

const uint32_t StraightAttackStructSize = 5;
typedef struct State StateType;
StateType BossAttack[StraightAttackStructSize] = {
	{0, 0, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, // straight attacks
	{0, 0, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0},
	{0, 0, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0},
	{0, 0, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, 
	{0, 0, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0},                                        
};

const uint32_t WaveAttackStructSize = 10;
typedef struct State StateType;
StateType WaveAttackStruct[WaveAttackStructSize] = {
	{32, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, // WAVE attacks
	{28, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, 
	{24, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0},
	{28, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0},
	{32, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, 
	{36, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, 
	{40, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, 
	{36, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, 
	{32, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, 
	{28, 32, bossattack,blackbossattack, bossattackwidth,bossattackheight,0,1,0}, 
};




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
	if (r1_x <= r2_x + r2_width &&
   r1_x + r1_width >= r2_x&&
   r1_y <= r2_y + r2_height &&
   r1_y + r1_height >= r2_y) {
    // collision detected!
		 return 1;
	}
	 return 0;
}


uint32_t Convert(uint32_t input){
	// converts ADC value into a position output
	// starts 2000, right max = 4000, left max = 0. up max = 0, down max = 4000
	pos = ((input+200)/2000) - 1; 
  return pos; 
}

// ------- xRandom and yRandom Convert Random number generated into useable number
uint32_t xRandom(void){
	// x goes from 0-128, Random() goes from 0 to 255
	uint32_t ran = Random()*128/255;
	return ran;
}
uint32_t yRandom(void){
	// y goes from 0-160, Random() goes from 0 to 255
	uint32_t ran = Random()*160/255;
	return ran;
}
uint32_t BinaryRandom(void){
	// y goes from 0-160, Random() goes from 0 to 1
	uint32_t ran = Random()/(255/2);
	return ran;
}

//--- SYSTICK HANDLER SAMPLES THE ADC FOR PLAYER MOVEMENT
int32_t PlayerAttackFlag=0;
void SysTick_Handler(void){
	// SysTick_Handler samples the ADC
	IO_HeartBeat();
	xADCMail = yADC_In();
	yADCMail = xADC_In();
	ADCStatus = 1;
	
	if(button() == 1){
		PlayerAttackFlag++;
	}
}

//--- TIMER0A_HANDLER MAKES THE BOSS MOVE
uint8_t straightattackflag = 0;
uint8_t waveattackflag = 0;
void Timer0A_Handler(void){
  TIMER0_ICR_R = TIMER_ICR_TATOCINT;  // acknowledge timer0A timeout
	straightattackflag++;
	waveattackflag++;
}

void DAC_Init(void){
	// make PB0-PB5 outputs on DAC
	SYSCTL_RCGCGPIO_R |= 0x02; // turn on port B clock
	while((SYSCTL_RCGCGPIO_R & 0x2) != 0x2) {} // wait till it is set
	GPIO_PORTB_DIR_R |= 0x3F; // set output PB0-PB5
	GPIO_PORTB_DEN_R |= 0x3F; // enable PB0-PB5
	}

// **************DAC_Out*********************
// output to DAC
// Input: 4-bit data, 0 to 15 
// Input=n is converted to n*3.3V/15
// Output: none
void DAC_Out(uint32_t data){
	//data = data*3.3/15;
	GPIO_PORTB_DATA_R = data;
}


// TIMER1A_Handler makes the sound happen
int32_t Index=0;
void Timer1A_Handler(void){
  TIMER1_ICR_R = TIMER_ICR_TATOCINT;  // acknowledge timer0A timeout
//	DAC_Out(mystical_tiny[Index]);
	Index=(Index+1)%songlength;
	//DAC_Out(sniper_shot[Index]);
	//Index=(Index+1)%18925;
	
}


// -------Draw Player Sprite Function
void DrawPlayer(void){
	uint32_t i,speed=3;
	for(i=0;i<speed;i++){
		if((sprite[0].x - xPosition) < 0 || (sprite[0].x - xPosition +sprite[0].width - 2 > 128) || ((sprite[0].y - yPosition - sprite[0].height) < 0) || (sprite[0].y - yPosition > 160)){
			break;
		}
		sprite[0].x = sprite[0].x - xPosition;
		sprite[0].y = sprite[0].y - yPosition; // subtract because y is flipped on joystick for some reason
		ST7735_DrawBitmap(sprite[0].x, sprite[0].y, sprite[0].image, sprite[0].width,sprite[0].height);	
		if(CheckCollision(&sprite[1], &sprite[0]) == 1){
			sprite[0].health--; // if you collide with boss, lose hp
		}
	}
}

//-----Draw Boss Sprite Function
void DrawBoss(void){
	uint32_t i,speed=1;
	uint32_t flag = 0;
	if(Random() < 15){
		sprite[1].xvelocity = -1;
	}
	if(Random() > 245){
		sprite[1].xvelocity = 1;
	}
	
	for(i=0;i<speed;i++){
		if(((sprite[1].x + sprite[1].xvelocity) < 15  || (sprite[1].x +  sprite[1].xvelocity +sprite[1].width > 110))){
			sprite[1].xvelocity *= -1;
			flag = 1;
		}
		sprite[1].x = sprite[1].x + sprite[1].xvelocity;
		sprite[1].y = sprite[1].y + sprite[1].yvelocity;; 
		ST7735_DrawBitmap(sprite[1].x, sprite[1].y, sprite[1].image, sprite[1].width,sprite[1].height);	
	}
	sprite[1].xvelocity = 0;
}


//--------Draw Player Attack Function
uint32_t pa=0;
void DrawPlayerAttack(void){
	// Draws an attack to fly across screen
	// Arguement is which attack it is in the array
	uint32_t i=0,j,speed=4;
	
	if(PlayerAttackFlag > 10){ // check to see button held long enough
		if(PlayerAttack[pa].moving == 0){ // if not moving already
			PlayerAttack[pa].x = sprite[0].x+4; // put attack where player is
			PlayerAttack[pa].y = sprite[0].y-sprite[0].height; 
			ST7735_DrawBitmap(PlayerAttack[pa].x, PlayerAttack[pa].y, PlayerAttack[pa].image, PlayerAttack[pa].width,PlayerAttack[pa].height);
			PlayerAttack[pa].moving = 1; // set the attack to moving
			
			pa++; // increment the attacks
			PlayerAttackFlag = 0;
		}
	}
	for(i=0;i<PlayerAttackStructSize;i++){
		for(j=0;j<speed;j++){
			if(PlayerAttack[i].moving == 1){
				PlayerAttack[i].x = PlayerAttack[i].x + PlayerAttack[i].xvelocity; // move the attack
				PlayerAttack[i].y = PlayerAttack[i].y + PlayerAttack[i].yvelocity; 
				ST7735_DrawBitmap(PlayerAttack[i].x, PlayerAttack[i].y, PlayerAttack[i].image, PlayerAttack[i].width,PlayerAttack[i].height);	
				
				if(CheckCollision(&sprite[1], &PlayerAttack[i]) == 1){
					PlayerAttack[i].moving = 0; // the attack collides with the boss sprite, make it not move anymore
					ST7735_DrawBitmap(PlayerAttack[i].x, PlayerAttack[i].y, PlayerAttack[i].dead, PlayerAttack[i].width,PlayerAttack[i].height);
					sprite[1].health--;		
				}	
				if((PlayerAttack[i].x < 0) || (PlayerAttack[i].x > 128) || (PlayerAttack[i].y < 0) || (PlayerAttack[i].y > 160) ){
					PlayerAttack[i].moving = 0; // if the attack is offscreen, make it not move anymore
					ST7735_DrawBitmap(PlayerAttack[i].x, PlayerAttack[i].y, PlayerAttack[i].dead, PlayerAttack[i].width,PlayerAttack[i].height);
				}
			}
		}
	}
	if(pa > PlayerAttackStructSize){ // game can only hold a number of attacks equal to PlayerAttackStructSize
		pa = 0;
	}
}


// ---------------  BOSS ATTACKS START HERE -----------------
// --------- Straight shot attack
uint32_t straighti=0;
void StraightAttack(void){
	uint32_t i,j,speed=2;
	if(straightattackflag >= 2){ // use flag to time attacks
		if(BossAttack[straighti].moving == 0){ // if not moving already
				BossAttack[straighti].x = xRandom(); // place where attack starts
				BossAttack[straighti].y = sprite[1].y; 
				ST7735_DrawBitmap(BossAttack[straighti].x, BossAttack[straighti].y, BossAttack[straighti].image, BossAttack[straighti].width,BossAttack[straighti].height);
				BossAttack[straighti].moving = 1; // set the attack to moving
				straighti++;
				straightattackflag = 0;
		}
	}
	for(i=0;i<StraightAttackStructSize;i++){ // move attacks one by one
		for(j=0;j<speed;j++){
			if(BossAttack[i].moving == 1){
				BossAttack[i].x = BossAttack[i].x + BossAttack[i].xvelocity; // move the attack
				BossAttack[i].y = BossAttack[i].y + BossAttack[i].yvelocity; 
				ST7735_DrawBitmap(BossAttack[i].x, BossAttack[i].y, BossAttack[i].image, BossAttack[i].width,BossAttack[i].height);	
				if(CheckCollision(&sprite[0], &BossAttack[i]) == 1){
					BossAttack[i].moving = 0; // the attack collides with the player sprite, make it not move anymore
					ST7735_DrawBitmap(BossAttack[i].x, BossAttack[i].y, BossAttack[i].dead, BossAttack[i].width,BossAttack[i].height);	// when collides, disappear
					sprite[0].health--; // player takes damage
				}
				if((BossAttack[i].x < 0) || (BossAttack[i].x > 128) || (BossAttack[i].y < 0) || (BossAttack[i].y > 160) ){
					BossAttack[i].moving = 0; // if the attack is offscreen, make it not move anymore
					ST7735_DrawBitmap(BossAttack[i].x, BossAttack[i].y, BossAttack[i].dead, BossAttack[i].width,BossAttack[i].height);	// when collides, disappear
				}
			}
		}
	}
	if(straighti >= StraightAttackStructSize){ // game can only hold a number of attacks equal to StraightAttackStructSize
		straighti = 0;
	}
}

// --------- WAVE SHOT ATTACK----------------
int32_t waveinitx[WaveAttackStructSize] = {30,26,22,26,30,34,38,34,30,26};
int32_t waveinity[WaveAttackStructSize] = {32,32,32,32,32,32,32,32,32,32};
uint32_t wavei=0;
void WaveAttackInit(void){
	uint32_t i,x,y,xstart;
	x = xRandom();
	y = yRandom();
	if(BinaryRandom() == 1){ // THIS SHOOTS FROM TOP
		for(i=0;i<WaveAttackStructSize;i++){
			WaveAttackStruct[i].y = 30;
			WaveAttackStruct[i].xvelocity = 0;
			WaveAttackStruct[i].yvelocity = 1;
		}
		WaveAttackStruct[0].x = x;
		WaveAttackStruct[1].x = x-4;
		WaveAttackStruct[2].x = x-8;
		WaveAttackStruct[3].x = x-4;
		WaveAttackStruct[4].x = x;
		WaveAttackStruct[5].x = x+4;
		WaveAttackStruct[6].x = x+8;
		WaveAttackStruct[7].x = x+4;
		WaveAttackStruct[8].x = x;
		WaveAttackStruct[9].x = x-4;
	}else{ // THIS SHOOTS FROM SIDE
		if(BinaryRandom() == 1){
			xstart = 0;
		}else{
		xstart = 160;
		}
		for(i=0;i<WaveAttackStructSize;i++){
			WaveAttackStruct[i].x = xstart;
			WaveAttackStruct[i].xvelocity = 1;
			WaveAttackStruct[i].yvelocity = 0;
		}
		WaveAttackStruct[0].y = y;
		WaveAttackStruct[1].y = y-4;
		WaveAttackStruct[2].y = y-8;
		WaveAttackStruct[3].y = y-4;
		WaveAttackStruct[4].y = y;
		WaveAttackStruct[5].y = y+4;
		WaveAttackStruct[6].y = y+8;
		WaveAttackStruct[7].y = y+4;
		WaveAttackStruct[8].y = y;
		WaveAttackStruct[9].y = y-4;
	}
}


void WaveAttack(void){
	uint32_t i,j,speed=3;
	if(waveattackflag >= 1){ // use flag to time attacks
		if(WaveAttackStruct[wavei].moving == 0){ // if not moving already
				//WaveAttackStruct[wavei].x = sprite[1].x; // put attack where it starts
				//WaveAttackStruct[wavei].y = sprite[1].y; 
				ST7735_DrawBitmap(WaveAttackStruct[wavei].x, WaveAttackStruct[wavei].y, WaveAttackStruct[wavei].image, WaveAttackStruct[wavei].width,WaveAttackStruct[wavei].height);
				WaveAttackStruct[wavei].moving = 1; // set the attack to moving
				wavei++;
				waveattackflag = 0;
		}
	}
	for(i=0;i<WaveAttackStructSize;i++){
		for(j=0;j<speed;j++){
			if(WaveAttackStruct[i].moving == 1){
				WaveAttackStruct[i].x = WaveAttackStruct[i].x + WaveAttackStruct[i].xvelocity; // move the attack
				WaveAttackStruct[i].y = WaveAttackStruct[i].y + WaveAttackStruct[i].yvelocity; 
				ST7735_DrawBitmap(WaveAttackStruct[i].x, WaveAttackStruct[i].y, WaveAttackStruct[i].image, WaveAttackStruct[i].width,WaveAttackStruct[i].height);	
				
				if(CheckCollision(&sprite[0], &WaveAttackStruct[i]) == 1){
					WaveAttackStruct[i].moving = 0; // the attack collides with the player sprite, make it not move anymore
					ST7735_DrawBitmap(WaveAttackStruct[i].x, WaveAttackStruct[i].y, WaveAttackStruct[i].dead, WaveAttackStruct[i].width,WaveAttackStruct[i].height);	// when collides, disappear
					sprite[0].health--; // player takes damage
				}
				if((WaveAttackStruct[i].x < 0) || (WaveAttackStruct[i].x > 128) || (WaveAttackStruct[i].y < 0) || (WaveAttackStruct[i].y > 160) ){
					WaveAttackStruct[i].moving = 0; // if the attack is offscreen, make it not move anymore
					ST7735_DrawBitmap(WaveAttackStruct[i].x, WaveAttackStruct[i].y, WaveAttackStruct[i].dead, WaveAttackStruct[i].width,WaveAttackStruct[i].height);	// when collides, disappear		
				}
			}
		}
	}
	if((wavei >= WaveAttackStructSize) && (WaveAttackStruct[WaveAttackStructSize-1].moving == 0)){ // game can only hold a number of attacks equal to StraightAttackStructSize
		wavei = 0;
		WaveAttackInit();
		
	}
}

void CheckEnd(void){
		ST7735_SetCursor(0,0);
		ST7735_OutString("Your Health:");
		if(sprite[0].health < 10){
			LCD_OutDec(0);
		}
		LCD_OutDec(sprite[0].health);
		ST7735_SetCursor(0,1);
		ST7735_OutString("Boss Health:");
		if(sprite[1].health < 10){
			LCD_OutDec(0);
		}
		LCD_OutDec(sprite[1].health);
		
		if(sprite[0].health <= 0){ // if your health becomes 0
			ST7735_FillScreen(0x00);
			ST7735_SetCursor(0,5);
			ST7735_OutString("You Lose");
			while(1){}
		}
		if(sprite[1].health <= 0){ // if boss health becomes 0
			ST7735_FillScreen(0x00);
			ST7735_SetCursor(0,5);
			ST7735_OutString("You Win");
			while(1){}	
		}
}

void ClearAttacks(void){
	for(int i = 0; i<WaveAttackStructSize; i++){
		WaveAttackStruct[i].moving = 0; // the attack collides with the player sprite, make it not move anymore
		ST7735_DrawBitmap(WaveAttackStruct[i].x, WaveAttackStruct[i].y, WaveAttackStruct[i].dead, WaveAttackStruct[i].width,WaveAttackStruct[i].height);
	}
	for(int i = 0; i<StraightAttackStructSize; i++){
		BossAttack[i].moving = 0; // if the attack is offscreen, make it not move anymore
		ST7735_DrawBitmap(BossAttack[i].x, BossAttack[i].y, BossAttack[i].dead, BossAttack[i].width,BossAttack[i].height);
	}
	piazza--;
}

int main(void){
  DisableInterrupts();
	PLL_Init(10);       // Bus clock is 9000000 HZ at 10
  Output_Init();
	PortF_Init();
	ADC_Init();
 	DAC_Init();
	SysTick_Init();
	Timer0A_Init(0xFFFFFF);
	Timer1A_Init(2950); //11.025 kHz = 11025 = 9000000/x x=816
	Random_Init(NVIC_ST_CURRENT_R);
  EnableInterrupts();
	WaveAttackInit();
	//ST7735_InitR(INITR_REDTAB); 
  ST7735_FillScreen(0x00);            // set screen to black
	
	
	// TITLE SCREEN
		ST7735_SetCursor(0,5);
		ST7735_OutString("Welcome to Our Game!");
		ST7735_SetCursor(0,7);
		ST7735_OutString("Press button");
		ST7735_SetCursor(0,8);
		ST7735_OutString("to start");
		while(button() == 0){
		}
	ST7735_FillScreen(0x00);   
	
	
while(1){
		
	
		// ****SAMPLE ADC STARTS HERE
		//while(ADCStatus != 1){} // sample ADC
    xPosition = Convert(xADCMail); 
		ADCStatus = 0; // clear flag
	
		yPosition = Convert(yADCMail); 
		ADCStatus = 0; // clear flag
		// **** END OF SAMPLE ADC
	
		CheckEnd();
	
		
		if(button2() == 1){
			ST7735_SetCursor(5,10);
			ST7735_OutString("POWERUP");
			ClearAttacks();
		}
	
		// ** DRAWING SPRITES STARTS HERE
		DrawPlayer();
		DrawBoss();
		DrawPlayerAttack();
		StraightAttack();
		WaveAttack();
		// ** DRAWING SPRITES ENDS HERE
	
}
	
	
	
	
	
		// ***** NEXT PART IS FOR TESTING
		//x
		ST7735_SetCursor(0,4);
		ST7735_OutString(" x ADC Value:");
		
		ST7735_SetCursor(0,6);
    LCD_OutDec(xADCMail); // show adc value 
		
		//y
		ST7735_SetCursor(0,8);
		ST7735_OutString(" y ADC Value:");
		
		ST7735_SetCursor(0,10);
		LCD_OutDec(yADCMail);
		//-************* END OF TESTING PART*********
	
		
	}


