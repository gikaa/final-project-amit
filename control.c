/*
 * Sys.c
 *
 * Created: 3/22/2021 10:05:58 AM
 *  Author: Hatem
 */ 

/*----------------------------------------------------------------------------*-
sys_init() : to initialize system by initializing all modules, and setting the
initial temperature to the EEPROM.
-*----------------------------------------------------------------------------*/

#include "control.h"

void sys_init(void)
{
	// Modules init
	GIE_voidEnable();
	ADC_Init();
	timer0_init();
	timer1_init();
	timer1_INT_enable();
	Buttons_init();
	cool_init();
	heat_init();
	led_init();
	SevenSegmenDisplay_init();
	Current_stat = OFF;
	

	if(EEPROM_read(0x0000) != 0xFF){
		desired_temp = EEPROM_read(0x0000);
	}
	else{
		desired_temp = INIT_DESIRED_TEMP;
	}
	
	temp_arr_init();
	EEPROM_write(0x0000,(u8) desired_temp);
	
}



void OFF_stat(void)
{
		SevenSegmenDisplay_turn_off();
		led_off();
		heat_stop();
		cool_stop();
		go_to_sleep();
}


void ON_stat(void)
{
	

		
	if (temp_measure_f == 1){
		actual_temp = (ADC_Read()*0.5);
		add_new_temp(temp_arr , actual_temp);
		avg_temp = calculate_avg_temp(temp_arr);
		temp_measure_f = 0;
	}
	
	SevenSegmenDisplay_write(actual_temp);

	
	change_temp();
	 

	
	if(UP()==on || DOWN()==on){

		SevenSegmenDisplay_disable();
		setting_counter = 0;
		Current_stat = SETTING;
			
	}
}


void SET_stat(void)
{
	heat_stop();
	cool_stop();
	led_off();
	

	
	if(toggle_f == 1){
		SevenSegmenDisplay_write(desired_temp);
	}
	else{
		SevenSegmenDisplay_turn_off();
	}
	

	
	if((UP() == on) && (desired_temp < MAX_TEMP)){
		desired_temp = desired_temp + 5;
		setting_counter = 0;
		SevenSegmenDisplay_write(desired_temp);
	}
	else if ((DOWN() == on) && (desired_temp > MIN_TEMP)){
		desired_temp = desired_temp - 5;
		setting_counter = 0;
		SevenSegmenDisplay_write(desired_temp);
	}
	
	EEPROM_write(0x0000,desired_temp);
	
}


void change_temp(void)
{
	if( (desired_temp < avg_temp + MARGIN_TEMP) && (desired_temp > avg_temp - MARGIN_TEMP) ){

		heat_stop();
		cool_stop();
		led_off();
	}
	else if(desired_temp < avg_temp + MARGIN_TEMP){

		
		heat_stop();
		cool_start();
		led_on();
	}
	else if (desired_temp > avg_temp - MARGIN_TEMP){

		
		heat_start();
		cool_stop();
		if (toggle_f == 1)
		{
			led_on();
		}
		else {
			led_off();
		}
	}
}

u16 calculate_avg_temp(u16 * arr)
{
	u16 sum = 0;
	u16 avg;

	for(u8 i=0; i<NUM_OF_TEMP_MEASURES; i++){
		sum = sum + arr[i];
	}
	avg = (u16) sum / NUM_OF_TEMP_MEASURES;
	return avg;
}

void temp_arr_init(void)
{
	u16 first_temp = ADC_Read()*0.5;
	
	for (u8 i = 0; i<NUM_OF_TEMP_MEASURES; i++){
		temp_arr[i]= first_temp;
	}
	
	avg_temp = calculate_avg_temp(temp_arr);
	arr_counter = 0;
}


void add_new_temp(u16 * arr , u16 new_val)
{
	arr[arr_counter] = new_val;
	arr_counter ++;
	
	if (arr_counter == 10){
		arr_counter = 0;
	}
}


void go_to_sleep(void)
{
	
	MCUCR&=~(1<<SM0);
	MCUCR&=~(1<<SM1);
	MCUCR&=~(1<<SM2);
	
	MCUCR|=(1<<SE);

}
