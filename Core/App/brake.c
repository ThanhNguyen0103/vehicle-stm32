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
	Button_Init(&brakeButton, GPIOB, GPIO_PIN_15);
}
void Brake_Run(void) {
	Button_Update(&brakeButton);
	if (Button_IsHolding(&brakeButton)) {
		brakeState = BRAKE_ON;
	} else
		brakeState = BRAKE_OFF;
}

Brake_State_t Brake_GetState(void) {
	return brakeState;
}

