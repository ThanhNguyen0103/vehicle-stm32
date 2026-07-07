/*
 * button.h
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */

#ifndef DRIVERS_BUTTON_H_
#define DRIVERS_BUTTON_H_

#include <stdbool.h>
#include "main.h"

typedef struct {
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
} Button_t;

bool Button_IsPressed(Button_t *button);
Button_t Button_Init(Button_t *button, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif /* DRIVERS_BUTTON_H_ */
