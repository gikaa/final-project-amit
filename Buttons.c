

#include "Buttons.h"

/*----------------------------------------------------------------------------*-
Buttons_init() : to initialize Buttons by making their pins as INPUT pins,
enabling the internal pull-up resistor, and enabling the external interrupt
for the ON/OFF button.
-*----------------------------------------------------------------------------*/

void Buttons_init(void){
	// Setting the pins as INPUT pins
	CLR_BIT(PORT_B_DIR,ON_OFF_PIN);
	CLR_BIT(PORT_B_DIR,UP_PIN);
	CLR_BIT(PORT_B_DIR,DOWN_PIN);
	
	// Enable internal Pull-Up Resistor
	
	SET_BIT(PORT_B,ON_OFF_PIN);
	SET_BIT(PORT_B,UP_PIN);
	SET_BIT(PORT_B,DOWN_PIN);
	
	
	// This Following Section is for the external interrupt
	// assigned to the ON/OFF Button.
	
	// Enable Global Interrupt bit
	 GIE_voidEnable();
	
	// Trigger with Rising Edge
	SET_BIT(MCUCSR,ISC2);
	
	// Enable INT2 (External Interrupt)
	SET_BIT(GICR,INT2);
}




u8 DOWN(void){
	// Check if on for the first time
	if(!(read_bit(PINB,DOWN_PIN))){
		// wait for 50 ms to make sure it's on (debouncing solution)
		_delay_ms(DEBOUNCE_INTERVAL);

		// check one more time
		if (!(read_bit(PINB,DOWN_PIN))){
			return on;
		}
		else return NOT_on;
	}
	else return NOT_on;
}
u8 UP(void){
	// Check if on for the first time
	if(!(read_bit(PINB,UP_PIN))){
		// wait for 50 ms to make sure it's on (debouncing solution)
		_delay_ms(DEBOUNCE_INTERVAL);

		// check one more time
		if (!(read_bit(PINB,UP_PIN))){
			return on;
		}
		else return NOT_on;
	}
	else return NOT_on;
}
