/*
 * temp_sensor.h
 *
 *  Created on: Oct 8, 2022
 *      Author: dell
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

#include "std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */

uint8 LM35_sensor_getTemp(void);

#endif /* LM35_SENSOR_H_ */
