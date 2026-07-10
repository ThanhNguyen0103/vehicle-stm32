/*
 * drivingmode.c
 *
 *  Created on: Jul 9, 2026
 *      Author: nguyz
 */

#include "drivingmode.h"
#include "button.h"
#include "ignition.h"
static Driving_Mode_t drivingMode;
static Button_t driving_button_mode;

Driving_Mode_t DrivingMode_GetState(void) {
	return drivingMode;
}

//Driving_Mode_t drivingMode_setState(Driving_Mode_t mode) {
//	drivingMode = mode;
//}

void DrivingMode_Init(void) {
	Button_Init(&driving_button_mode, GPIOB, GPIO_PIN_13);
	drivingMode = ECO_MODE; // phai get state button
}

void DrivingMode_Run(void) {

	if (Ignition_GetState() == IGNITION_OFF) {
		return;
	}
	if (Button_IsPressed(&driving_button_mode)) {
		drivingMode = (drivingMode == ECO_MODE) ? SPORT_MODE : ECO_MODE;

	}

}
