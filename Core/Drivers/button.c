/*
 * button.c
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */

#include "button.h"

Button_t Button_Init(Button_t *button, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
	button->GPIO_Pin = GPIO_Pin;
	button->GPIOx = GPIOx;
}

bool Button_IsPressed(Button_t *button) {

	if (HAL_GPIO_ReadPin(button->GPIOx, button->GPIO_Pin) == GPIO_PIN_RESET) {
		HAL_Delay(30);
		if (HAL_GPIO_ReadPin(button->GPIOx, button->GPIO_Pin)
				== GPIO_PIN_RESET) {
			while (HAL_GPIO_ReadPin(button->GPIOx, button->GPIO_Pin)
					== GPIO_PIN_RESET)
				;
			return true;
		}
	}
	return false;
}

