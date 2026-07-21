/*
 * brake.c
 *
 *  Created on: Jul 21, 2026
 *      Author: nguyz
 */

#include "button.h"
#include "brake.h"

static Button_t brakeButton;
static Brake_State_t brakeState;

void Brake_Init(void) {
	brakeState = BRAKE_OFF;
	Button_Init(&brakeButton, GPIOA, GPIO_PIN_12);
}
void Brake_Run(void) {
	if (Button_IsPressed(&brakeButton)) {
		brakeState = (brakeState == BRAKE_OFF) ? BRAKE_ON : BRAKE_OFF;
	}
}

Brake_State_t Brake_GetState(void) {
	return brakeState;
}

