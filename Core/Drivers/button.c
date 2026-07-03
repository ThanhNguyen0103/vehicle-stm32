/*
 * button.c
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */

#include "button.h"

bool Button_IsPressed(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {

	if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_RESET) {
		HAL_Delay(30);
		if (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_RESET) {
			while (HAL_GPIO_ReadPin(GPIOx, GPIO_Pin) == GPIO_PIN_RESET)
				;

			return true;
		}
	}
	return false;
}
