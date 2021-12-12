/*
 * Timer.h
 *
 * Created: 3/20/2021 5:16:13 PM
 *  Author: sa
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include "GIE_Interface.H"
#include "BIT_MATH.h"

void timer1_init();
void timer0_init();
void timer1_INT_disable();
void timer1_INT_enable();

#endif /* TIMER_H_ */
