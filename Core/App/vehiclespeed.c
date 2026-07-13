/*
 * vehiclespeed.c
 *
 *  Created on: Jul 12, 2026
 *      Author: nguyz
 */

#include "vehiclespeed.h"
#include "drivingmode.h"
#include "adc.h"

static uint32_t speed;

void VehicleSpeed_Init(void) {
	ADC_Init();
}

uint32_t VehicleSpeed_Run(void) {
	Driving_Mode_t mode = DrivingMode_GetState();

	uint32_t maxSpeed = (mode == ECO_MODE) ? 45 : 70;
	uint32_t adc_value = ADC_ReadValue();

	speed = (adc_value * maxSpeed) / 4095;
	return speed;
}
uint32_t VehicleSpeed_GetSpeed(void) {
	return speed;
}
