/*
 * ssd.h
 *
 * Created: 3/20/2021 5:59:41 PM
 *  Author: Hatem
 */ 


#ifndef SSD_H_
#define SSD_H_


#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

	
// SSD Display Macros
#define DISP1 1
#define DISP2 2

#define SSD_ENABLE_PORT_DIR DDRB
#define SSD_ENABLE_PORT PORTB
#define SSD1_ENABLE_PIN 6 
#define SSD2_ENABLE_PIN 7
#define SSD_DATA PORTD
#define SSD_PORT_DIR DDRD

// SSD Control Functions
void SevenSegmenDisplay_init(void);
void SevenSegmenDisplay_send(u16 N);
void SevenSegmenDisplay_enable(u8 disp);
void SevenSegmenDisplay_disable(void);
void SevenSegmenDisplay_turn_off(void);
void SevenSegmenDisplay_write(u16 N);


#endif /* SSD_H_ */
