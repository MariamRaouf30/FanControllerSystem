/*
 * dc_motor.c
 *
 *  Created on: Oct 8, 2022
 *      Author: dell
 */


#include "dc_motor.h"
#include <avr/io.h>
#include "gpio.h"
#include "pwm.h"

/* Description:
  * Initialize DC Motor Driver
  * Set PIN1 & PIN2 as OUTPUTS
  * Start with stop mode of motor
  */

void DcMotor_Init(void){
	GPIO_setupPinDirection(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_PORT_ID,DCMOTOR_PIN2_ID,PIN_OUTPUT);

	GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,LOGIC_LOW);
	GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,LOGIC_LOW);
}



/* Description:
  * Control the DC Motor direction using L293D H-bridge.
  * Control The DC Motor Speed using PWM from MC. connect the
  * PWM PIN of Timer0 OC0(PB3) to the enable of the Motor.
  * duty cycle 100% --> Maximum Speed
  * duty cycle 50%  --> Half Maximum Speed
  * duty cycle 0%   --> Motor Stop
  */

void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	uint8 duty_cycle = ((float)speed/100)*255;
	/*
	* duty cycle variable to adjust percentage of pwm then call PWM with the adjusted value
	*/
	PWM_Timer0_Start(duty_cycle);

	if(state == STOP){
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN2_ID,LOGIC_LOW);
	}
	else if(state == CW){
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,LOGIC_HIGH);
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN2_ID,LOGIC_LOW);
	}
	else if(state == A_CW){
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN1_ID,LOGIC_LOW);
		GPIO_writePin(DCMOTOR_PORT_ID,DCMOTOR_PIN2_ID,LOGIC_HIGH);
	}


}
