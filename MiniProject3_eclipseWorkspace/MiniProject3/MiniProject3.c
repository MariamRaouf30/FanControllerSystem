/*
 * MiniProject3.c
 *
 *  Created on: Oct 6, 2022
 *      Author: dell
 */


#include "lcd.h"
#include "adc.h"
#include "dc_motor.h"
#include "lm35_sensor.h"


/* Description:
  * Main function of the project
  * Initialize motor, LCD and ADC
  * store temperature in variable temperature from sensor get temperature function
  * compare temperatures to control speed of the fan's motor
  * Show the temperature and state of the motor on the LCD
  */


int main(void){
	uint8 temperature;
	ADC_ConfigType config_type = {INT_VOLT, F_CPU_8};
	ADC_init(&config_type);

	LCD_init();
	DcMotor_Init();

	LCD_displayStringRowColumn(0,3,"FAN is ");
	LCD_displayStringRowColumn(1,3,"Temp=     C");
	while(1){
		temperature = LM35_sensor_getTemp();

		if(temperature < 30){
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
		}
		else if(temperature >= 30){
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			LCD_moveCursor(1,10);
			LCD_intgerToString(temperature);
		}

		if (temperature < 30){
			DcMotor_Rotate(STOP , 0);
		}
		else if(temperature >= 30 && temperature < 60){
			DcMotor_Rotate(CW , 25);
		}
		else if(temperature >= 60 && temperature < 90){
			DcMotor_Rotate(CW , 50);

		}
		else if(temperature >= 90 && temperature < 120){
			DcMotor_Rotate(CW , 75);

		}
		else if(temperature >= 120){
			DcMotor_Rotate(CW , 100);
		}

	}
}
