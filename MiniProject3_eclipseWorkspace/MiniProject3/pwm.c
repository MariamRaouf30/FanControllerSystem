/*
 * PWM.c
 *
 *  Created on: Oct 6, 2022
 *      Author: dell
 */

#include "pwm.h"
#include <avr/io.h>
#include <util/delay.h>

/*
 * Description:
 * Generate a PWM signal with frequency
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500 Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */
void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0 = 0;
	OCR0  = duty_cycle;
	DDRB |= (1 << PB3);
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1 << WGM01) | (1 << WGM00) | (1 << COM01) | (1 << CS01) ;
}
