/*
 * Sys.h
 *
 * Created: 3/22/2021 10:06:13 AM
 *  Author: Hatem
 */ 


#ifndef CONTROL_H_
#define CONTROL_H_


//system parameters
#define MARGIN_TEMP 4
#define MAX_TEMP 75
#define MIN_TEMP 35
#define INIT_DESIRED_TEMP 45
#define NUM_OF_TEMP_MEASURES 10

// Including All Peripherals
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "ADC.h"
#include "Buttons.h"
#include "Cool_Heat_Elements.h"
#include "LED.h"
#include "SSD_disp.h"
#include "Timer.h"
#include "EEPROM.h"
#include "STD_TYPES.h"
#include "GIE_Interface.H"


#define OFF 0
#define ON 1
#define SETTING 2

/**************************************** 
*               Functions               *
****************************************/

void sys_init(void);
void ON_stat(void);
void OFF_stat(void);
void SET_stat(void);

void change_temp(void);
void add_new_temp(u16 * arr , u16 new_val);
u16 calculate_avg_temp(u16 * arr);
void temp_arr_init(void);
void go_to_sleep(void);

/****************************************
*               Variables               *
****************************************/

// will add as needed

u8 Current_stat;

u16 temp_arr[NUM_OF_TEMP_MEASURES];
u16 desired_temp;
u16 actual_temp;
u16 avg_temp;

u8 temp_measure_f;
u8 temp_measure_counter;
u8 setting_counter;

u16 toggle_f;
u8 arr_counter;
//



#endif /* CONTROL_H_ */
