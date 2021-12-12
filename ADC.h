

#ifndef ADC_H_
#define ADC_H_


#include <avr/io.h>
#include"ADC_Private.h"
#include "STD_TYPES.h"
#include"BIT_MATH.h"

void ADC_Init(void);
u16 ADC_Read(void);


#endif /* ADC_H_ */
