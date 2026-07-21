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
#include"can.h"
#include "brake.h"
static uint32_t currentSpeed = 0;

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

	const uint32_t adc_value = ADC_ReadValue();

	const uint32_t targetSpeed = (adc_value * maxSpeed) / 4095;
	if (Brake_getState() == BRAKE_ON) {
		if (currentSpeed > 0)
			currentSpeed--;
	} else {
		if (currentSpeed < targetSpeed) {
			currentSpeed++;
		} else if (currentSpeed > targetSpeed) {
			currentSpeed--;
		}
	}

//	CAN_Frame_t frame;
//	frame.id = CAN_ID_VEHICLE_SPEED;
//	frame.dlc = 1;
//	frame.data[0] = VehicleSpeed_GetSpeed();
//
//	CAN_Send(&frame);
	return currentSpeed;
}
uint32_t VehicleSpeed_GetSpeed(void) {
	return currentSpeed;
}
