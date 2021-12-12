/*
 * main.c
 *
 *  Created on: 5 Dec 2021
 *      Author: sa
 */


/*
 * main.c
 *
 * Created: 3/20/2021 5:13:23 PM
 *  Author: sa
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "control.h"





int main(void){

	sys_init();

	while(1){
		switch (Current_stat ){
			case ON:{
				ON_stat();
				break;
			}
			case OFF:{
				OFF_stat();
				break;
			}
			case SETTING:{
				SET_stat();
				break;
			}
		}
	}
	return 0;
}


/*----------------------------------------------------------------------------*-
ON/OFF_Button_INTERRUPT
-*----------------------------------------------------------------------------*/

void __vector_3 (void) __attribute__ ((signal,used, externally_visible)) ; \
    void __vector_3 (void)
{
	if(Current_stat ==OFF){
		Current_stat  = ON;
		desired_temp = EEPROM_read(0x0000);
	}
	else if (Current_stat ==ON || Current_stat ==SETTING){
		Current_stat  = OFF;
	}
}


//TRIGGERS EVERY 100MS

void __vector_7 (void) __attribute__ ((signal,used, externally_visible)) ; \
    void __vector_7 (void)
{
	temp_measure_f = 1;
}

//timer trriger

void __vector_10 (void) __attribute__ ((signal,used, externally_visible)) ; \
    void __vector_10 (void)
{
	if ((Current_stat==SETTING) || (Current_stat==ON)){
		setting_counter++;
		if(setting_counter % 4 == 0){
			toggle_f ^= 1;
		}
		if (setting_counter > 20){

			Current_stat = ON;
		}
	}
}

