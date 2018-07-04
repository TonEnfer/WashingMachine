/*
 * LimitSwitch.h
 *
 * Created: 18.01.2016 14:58:37
 *  Author: Anton
 */ 


#ifndef LIMITSWITCH_H_
#define LIMITSWITCH_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>

#define lsw1_DDR DDRD
#define lsw2_DDR DDRD
#define lsw3_DDR DDRD
#define lsw4_DDR DDRD
#define lsw5_DDR DDRD

#define lsw1_PORT PORTD
#define lsw2_PORT PORTD
#define lsw3_PORT PORTD
#define lsw4_PORT PORTD
#define lsw5_PORT PORTD

#define lsw_PINS PIND

#define lsw1_PIN PIND3
#define lsw2_PIN PIND4
#define lsw3_PIN PIND5
#define lsw4_PIN PIND6
#define lsw5_PIN PIND7

#define lsw_ISR_PCICR PCICR
#define lsw_ISR_PCIE PCIE3

#define lsw_ISR_PCMSK PCMSK3
#define lsw1_ISR_PCINT PCINT27
#define lsw2_ISR_PCINT PCINT28
#define lsw3_ISR_PCINT PCINT29
#define lsw4_ISR_PCINT PCINT30
#define lsw5_ISR_PCINT PCINT31

#define lsw1_is_set (bit_is_set(lsw_PINS,lsw1_PIN))

void LimitSwith_init(void);
ISR (PCINT3_vect);

#endif /* LIMITSWITCH_H_ */