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

bool Button_IsPressed(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif /* DRIVERS_BUTTON_H_ */
