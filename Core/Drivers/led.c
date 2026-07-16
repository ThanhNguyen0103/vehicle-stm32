/*
 * led.c
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */

#include "main.h"
#include "led.h"
void Toggle_Led() {

	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
	HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}

