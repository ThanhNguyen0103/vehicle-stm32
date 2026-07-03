/*
 * app.c
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */

#include "app.h"
#include "led.h"
#include "lcd.h"
#include "button.h"

static LCD_State_t lcdState;

void App_Init(void) {
	lcdState = LCD_OFF;
	LCD_Off();
}
void App_Run(void) {

	if (Button_IsPressed(GPIOB, GPIO_PIN_12)) {

		Toggle_Led();

		lcdState = (lcdState == LCD_OFF) ? LCD_ON : LCD_OFF;

		switch (lcdState) {
		case LCD_ON:
			LCD_On();
			break;

		case LCD_OFF:
			LCD_Off();
			break;

		}
	}

}
