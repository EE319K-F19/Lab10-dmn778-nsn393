// IO.c
// This software configures the switch and LED
// You are allowed to use any switch and any LED, 
// although the Lab suggests the SW1 switch PF4 and Red LED PF1
// Runs on LM4F120 or TM4C123
// Program written by: put your names here
// Date Created: March 30, 2018
// Last Modified:  change this or look silly
// Lab number: 7


#include "../inc/tm4c123gh6pm.h"
#include <stdint.h>
#include "ST7735.h"

void Delay1ms(uint32_t n);
void delay(void);

//------------IO_Init------------
// Initialize GPIO Port for a switch and an LED
// Input: none
// Output: none
void IO_Init(void) {
 // --UUU-- Code to initialize PF4 and PF2. Pf4 is a negative logic switch
	SYSCTL_RCGCGPIO_R |= 0x20; // port f clock
	while((SYSCTL_RCGCGPIO_R & 0x20) != 0x20){}
		GPIO_PORTF_DIR_R &= ~0x10; //pf4 input
		GPIO_PORTF_DIR_R |= 0x04; //pf2 heartbeat output
		GPIO_PORTF_DEN_R |= 0x14; //enable 
		GPIO_PORTF_PUR_R |= 0x10; //pull up resistor
	
}

//------------IO_HeartBeat------------
// Toggle the output state of the  LED.
// Input: none
// Output: none
void IO_HeartBeat(void) {
 // --UUU-- PF2 is heartbeat
	GPIO_PORTF_DATA_R ^=  0x04; //xor for heartbeat
}


//------------IO_Touch------------
// wait for release and press of the switch
// Delay to debounce the switch
// Input: none
// Output: none
void IO_Touch(void) {
 // --UUU-- wait for release; delay for 20ms; and then wait for press of PF4
	while((GPIO_PORTF_DATA_R & 0x10) == 0x10){}
	Delay1ms(30);
	while((GPIO_PORTF_DATA_R & 0x10) != 0x10){} // if released (negative logic)	
	}


void delay(void) {
	uint32_t counter =100000;
	while(counter > 0){
		counter--;
	}
}

