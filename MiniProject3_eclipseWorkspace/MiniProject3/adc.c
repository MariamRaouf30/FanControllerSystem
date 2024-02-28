/*
 * ADC.c
 *
 *  Created on: Oct 6, 2022
 *      Author: dell
 */

#include "avr/io.h"
#include "adc.h"
#include "common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


/* Description:
  * Initialize ADC
  */

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr-> ref_volt )<< REF_VOLT_BIT);
	ADCSRA = (1<<ADC_ENABLE_BIT) | ((Config_Ptr -> prescaler)&(0X07));
}


/* Description:
  * Store then Read the digital value from the data register
  */

uint16 ADC_readChannel(uint8 channel_num)
{
	 /* Input channel number must be from 0 --> 7 */
	 /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07); /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADC_Start_Conversion_bit); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADC_INTERRUPT_FLAG); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}

