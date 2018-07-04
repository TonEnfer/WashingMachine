/*
 * LimitSwitch.cpp
 *
 * Created: 18.01.2016 14:58:23
 *  Author: Anton
 */ 

#include "LimitSwitch.h"

void LimitSwith_init(void)
{
	//Port init
	lsw1_DDR &= ~_BV(lsw1_PIN);
	lsw1_PORT |= _BV(lsw1_PIN);
	
	lsw2_DDR &= ~_BV(lsw2_PIN);
	lsw2_PORT |= _BV(lsw2_PIN);
	
	lsw3_DDR &= ~_BV(lsw3_PIN);
	lsw3_PORT |= _BV(lsw3_PIN);
	
	lsw4_DDR &= ~_BV(lsw4_PIN);
	lsw4_PORT |= _BV(lsw4_PIN);
	
	lsw5_DDR &= ~_BV(lsw5_PIN);
	lsw5_PORT |= _BV(lsw5_PIN);
	
	//Interrupt init
	lsw_ISR_PCICR |= _BV(lsw_ISR_PCIE);
	lsw_ISR_PCMSK |= _BV(lsw1_ISR_PCINT) | _BV(lsw2_ISR_PCINT) |
	_BV(lsw3_ISR_PCINT) | _BV(lsw4_ISR_PCINT) | _BV(lsw5_ISR_PCINT);
	
	DDRB = 0xFF;
	PORTB = 0x00;
}

ISR (PCINT3_vect)
{
	switch(lsw_PINS)
	{
		case 0b10000000:
		PORTB = 0b00000001; break;
		case 0b01000000:
		PORTB = 0b00000010; break;
		case 0b00100000:
		PORTB = 0b00000100; break;
		case 0b00010000:
		PORTB = 0b00001000; break;
		case 0b00001000:
		PORTB = 0b00010000; break;
		default:
		PORTB = rand(); break;
	}
}