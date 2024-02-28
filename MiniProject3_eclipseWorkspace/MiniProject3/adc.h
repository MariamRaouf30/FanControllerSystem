/*
 * adc.h
 *
 *  Created on: Oct 8, 2022
 *      Author: dell
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT  2.56
#define REF_VOLT_BIT 6
#define ADC_ENABLE_BIT ADEN
#define ADC_Start_Conversion_bit ADSC
#define ADC_INTERRUPT_FLAG ADIF


typedef enum{
	F_CPU_,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;


typedef	enum{
	AREF,AVCC,RESERVED,INT_VOLT
}ADC_ReferenceVolatge;



typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;



void ADC_init(const ADC_ConfigType * Config_Ptr);
uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */
