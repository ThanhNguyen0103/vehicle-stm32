/*
 * ignition.c
 *
 *  Created on: Jul 4, 2026
 *      Author: nguyz
 */

#include "ignition.h"
#include "button.h"
#include "led.h"
static IgnitionState_t ignitionState;
static Button_t button_ignition;
void Ignition_Init(void) {
	ignitionState = IGNITION_OFF;
	Button_Init(&button_ignition, GPIOB, GPIO_PIN_12);
}
IgnitionState_t Ignition_GetState(void) {
	return ignitionState;
}

void Ignition_Run(void) {

	if (Button_IsPressed(&button_ignition)) {
		Toggle_Led();
		ignitionState =
				(ignitionState == IGNITION_OFF) ? IGNITION_ON : IGNITION_OFF;

	}

}
