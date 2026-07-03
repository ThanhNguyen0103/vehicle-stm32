/*
 * dashboard.c
 *
 *  Created on: Jul 4, 2026
 *      Author: nguyz
 */

#include "dashboard.h"
#include "ignition.h"
#include "lcd.h"

static IgnitionState_t oldState = IGNITION_OFF;

void Dashboard_Run(void) {

	IgnitionState_t newState = Ignition_GetState();

	if (newState != oldState) {

		oldState = newState;

		switch (newState) {
		case IGNITION_ON:
			Lcd_On();
			break;

		case IGNITION_OFF:
			Lcd_Off();
			break;

		}
	}

}
