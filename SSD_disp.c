
#include "SSD_disp.h"

/*----------------------------------------------------------------------------*-
SSD_Init. : to initialize the Seven Segment by making its port OUTPUT.
-*----------------------------------------------------------------------------*/

// Array for Numbers' Values
u8 Nums[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void SevenSegmenDisplay_init(void){
	
	// setting Seven Segment Pins as output pins
	SSD_PORT_DIR = 0xFF;
	SET_BIT(SSD_ENABLE_PORT_DIR,SSD1_ENABLE_PIN);
	SET_BIT(SSD_ENABLE_PORT_DIR,SSD2_ENABLE_PIN);
	
	// Seven Segment initially OFF
	SevenSegmenDisplay_disable();
	
}
	

	
void SevenSegmenDisplay_send(u16 N){
	SSD_DATA = Nums[N];
}


void SevenSegmenDisplay_enable(u8 disp){
	if(disp == 1){
		SET_BIT(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
		CLR_BIT(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
	}
	else if (disp == 2){
		SET_BIT(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
		CLR_BIT(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	}
}

/*----------------------------------------------------------------------------*-
SSD_disable() : To disable the two seven segments for some special cases.
-*----------------------------------------------------------------------------*/

void SevenSegmenDisplay_disable(void){
	CLR_BIT(SSD_ENABLE_PORT,SSD1_ENABLE_PIN);
	CLR_BIT(SSD_ENABLE_PORT,SSD2_ENABLE_PIN);
}

/*----------------------------------------------------------------------------*-
SSD_turn_off() : To turn off the Seven Segment in the OFF STATE.
-*----------------------------------------------------------------------------*/

void SevenSegmenDisplay_turn_off(void){
	SSD_DATA = 0x00;
}

/*----------------------------------------------------------------------------*-
SSD_write() : To calculate what to write on each of the two SSDs, and send.
-*----------------------------------------------------------------------------*/

void SevenSegmenDisplay_write(u16 N){
	u8 units;
	u8 tens;
	
	units = N % 10;
	tens = (int) N / 10;
	
	SevenSegmenDisplay_enable(DISP1);
	SevenSegmenDisplay_send(units);
	_delay_ms(50);
	
	SevenSegmenDisplay_enable(DISP2);
	SevenSegmenDisplay_send(tens);
	_delay_ms(50);
}
