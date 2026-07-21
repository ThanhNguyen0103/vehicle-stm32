/*
 * ignition.c
 *
 *  Created on: Jul 4, 2026
 *      Author: nguyz
 */

#include "ignition.h"
#include "button.h"
#include "led.h"
#include "can.h"
static IgnitionState_t ignitionState;
static Button_t ignitionButton;
void Ignition_Init(void) {
	ignitionState = IGNITION_OFF;
	Button_Init(&ignitionButton, GPIOB, GPIO_PIN_12);
}
IgnitionState_t Ignition_GetState(void) {
	return ignitionState;
}

void Ignition_Run(void) {
	CAN_Frame_t frame;
	if (Button_IsPressed(&ignitionButton)) {
		Toggle_Led();
		ignitionState =
				(ignitionState == IGNITION_OFF) ? IGNITION_ON : IGNITION_OFF;

		frame.id = CAN_ID_IGNITION;
		frame.dlc = 1;
		frame.data[0] = 'A';

		CAN_Send(&frame);
	}

}
