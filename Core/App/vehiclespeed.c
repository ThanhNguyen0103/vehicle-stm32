/*
 * vehiclespeed.c
 *
 *  Created on: Jul 12, 2026
 *      Author: nguyz
 */

#include "vehiclespeed.h"
#include "drivingmode.h"
#include "adc.h"
#include "ignition.h"
static uint32_t currentSpeed;

void VehicleSpeed_Init(void) {
	ADC_Init();
}

uint32_t VehicleSpeed_Run(void) {

	if (Ignition_GetState() == IGNITION_OFF) {
		if (currentSpeed > 0) {
			currentSpeed--;
		}
		return currentSpeed;
	}

	Driving_Mode_t mode = DrivingMode_GetState();

	const uint32_t maxSpeed = (mode == ECO_MODE) ? 45 : 70;
	uint32_t adc_value = ADC_ReadValue();

	uint32_t targetSpeed = (adc_value * maxSpeed) / 4095;

	if (currentSpeed < targetSpeed) {
		currentSpeed++;
	} else if (currentSpeed > targetSpeed) {
		currentSpeed--;
	}

	return currentSpeed;
}
uint32_t VehicleSpeed_GetSpeed(void) {
	return currentSpeed;
}
