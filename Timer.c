/*
 * Timer.c
 *
 * Created: 3/20/2021 5:16:25 PM
 *  Author: sa
 */ 


#include "Timer.h"



void timer1_init(){
	
	// Select CTC Mode
	SET_BIT(TCCR1B,WGM12);
	
	
	// Load Value in OCR1A
	OCR1AH = 0b00000000;
	OCR1AL = 0b01100010;
	/*
	// Load Value in OCR1B
	OCR1BH = 0b00000011;
	OCR1BL = 0b11010001;
	*/
	// Select Clock Prescaler (F_CPU / 1024)
	SET_BIT(TCCR1B,CS10);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS12);
	
	// Enable Global Interrupt bit
	GIE_voidEnable();

}



void timer0_init(){
	
	// choose mode
	SET_BIT(TCCR0,WGM01);
	
	// Load Value in OCR0
	OCR0 = 250;
	
	// Choose Prescaler
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// Enable Timer INT
	GIE_voidEnable();
	SET_BIT(TIMSK,OCIE0);
	
}

/*----------------------------------------------------------------------------*-
timer1_INT_disable() : to stop timer(1) from triggering INTERRUPTS.
-*----------------------------------------------------------------------------*/

void timer1_INT_disable(){
	

	CLR_BIT(TIMSK,OCIE1A);

}


void timer1_INT_enable(){
	

	SET_BIT(TIMSK,OCIE1A);

}
