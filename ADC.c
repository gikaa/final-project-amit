/*
 * ADC.c
 *
 * Created: 3/22/2021 9:29:36 AM
 *  Author: Hatem
 */ 
#include "STD_TYPES.H"
#include "ADC.h"

/*----------------------------------------------------------------------------*-
ADC_init() : to initialize the ADC to sense temperature from the sensor connected.
-*----------------------------------------------------------------------------*/

void ADC_Init(){
	
	// Choosing reference voltage
	// the AVCC pin.
	SET_BIT(ADMUX,REFS0);
	
	// Choosing Channel One (Single Ended In.) at A0 pin.
	CLR_BIT(ADMUX,MUX0);
	CLR_BIT(ADMUX,MUX1);
	CLR_BIT(ADMUX,MUX2);
	CLR_BIT(ADMUX,MUX3);
	CLR_BIT(ADMUX,MUX4);
	
	// Choosing the Data to be Right Adjusted in the Data Reg.
	CLR_BIT(ADMUX,ADLAR);
	
	// Choosing Prescaler for the ADC clock.
	// the following is choosing (2) as a Prescaler.
	SET_BIT(ADCSRA,ADPS0);
	CLR_BIT(ADCSRA,ADPS1);
	CLR_BIT(ADCSRA,ADPS2);
	
	// Enable the ADC
	SET_BIT(ADCSRA,ADEN);
	
}

/*----------------------------------------------------------------------------*-
ADC_read() : to read Data from the temperature sensor whenever it's called.
-*----------------------------------------------------------------------------*/

u16 ADC_Read(){
	
	u16 Data;
	
	// Start Conversion
	SET_BIT(ADCSRA,ADSC);
	
	// Wait for flag to be set.
	// Indication of finished conversion
	while(is_bit_clr(ADCSRA,ADIF));
	
	// Read Data from the ADC Data Register
	// Read the Low register first!
	Data = ADCL;
	Data |= (ADCH<<8);
	
	// Clear Flag (As we are not using the interrupt)
	// It won't be cleared automatically!
	SET_BIT(ADCSRA,ADIF);
	
	return Data;
}
