/*
 * Button.h
 *
 * Created: 3/20/2021 7:00:25 PM
 *  Author: Hatem
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"GIE_Interface.h"

#define on 1
#define NOT_on 0

#define DEBOUNCE_INTERVAL 100
#define PORT_B PORTB
#define PORT_B_DIR DDRB

#define ON_OFF_PIN 2
#define UP_PIN 1
#define DOWN_PIN 3

// Buttons Reading Functions
void Buttons_init(void);
void ON_OFF_EXTI(void);

unsigned char UP(void);
unsigned char DOWN(void);


#endif /* BUTTON_H_ */
