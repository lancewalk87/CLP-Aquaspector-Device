/**
 * system.h
 * Aquaspector Device: Field 
 *
 * Created by Lance T. Walker on 11/4/2018 8:28:23 PM
 * Copyright ? 2018 CodeLife-Productions. All rights reserved.
 --------------------------------------------------------------------------------------------
  * AVR: [ATmega644P 20AU] I/O:
  * Counters				= Prescaler and Comparator x2
  * PWM Channels			= 6
  * ADC Channels			= 10-bit x8
  * General Purpose I/O		= 32
  * Ports					= 4 
  * Total Pins				= 44
--------------------------------------------------------------------------------------------
 * Categorical Prefixes:	| Port/Registers:		| Pins:
 * SPI				= SPI	| B = 0x24,0x25			| PB4, PB5, PB6, PB7
 * Charger			= CHG	| A = 0x20,0x22			| PA0
 * Battery			= BATT	| A = 0x20				| PA1, PA2, PA3
 * nRF24L01 SPI		= NRF	| A = 0x21,0x22			| PB4, PA4
 * KSZ8851SNL SPI	= ETH	| A = 0x21,0x22			| PA5
 * LEDs				= LED	| D = 0x2A,0x2B			| PD4, PD5, PD6
 * LCD_TFT			= LCD	| B = 0x24,0X25			| PB0, PB1, PB2, PB3, PB4
 * Buttons			= BTN	| C = 0x26,0x27,0x28	| PC3, PC4, PC4, PC6, PC7
 */ 


#ifndef SYSTEM_H_
#define SYSTEM_H_
/***************************************************************************************************/
#pragma mark - SPI
#ifdef debug
/* Pins */ 
#define SPI_DDR		DDRB	// | Offset = 0x24 | Reset = 0x00 | Address = 0x04 |
#define SPI_PORT	PORTB	// | Offset = 0x25 | Reset = 0x00 | Address = 0x05 |
#define SPI_SS		PB4		// | PCINT12 | SS   | OC0B |
#define SPI_MOSI	PB5		// | PCINT13 | MOSI |
#define SPI_MISO	PB6		// | PCINT14 | MISO |
#define SPI_SCK		PB7		// | PCINT15 | SCK  |
#endif 
/* Methods */
/***************************************************************************************************/
#pragma mark - Charger 
/* Pins */
#define CHG_PORT	PORTA	// | Offset = 0x22 | Reset = 0x00 | Address = 0x02 |
#define CHG_PIN		PINA	// | Offset = 0x20 | Reset = N/A  | Address = 0x00 |
#define CHG			PA0		// | PCINT0 | ADC0 |
/* Methods */
#define chg_init()	CHG_PORT |= _BV(CHG);
#define chg_read()	(!(CHG_PIN & _BV(CHG)));
/***************************************************************************************************/
#endif /* SYSTEM_H_ */