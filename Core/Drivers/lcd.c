/*
 * lcd.c
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */
#include "ssd1306.h"
#include "ssd1306_fonts.h"

void LCD_On(void) {

	ssd1306_Fill(Black);
	ssd1306_SetCursor(0, 0);

	ssd1306_WriteString("Hello STM32", Font_7x10, White);

	ssd1306_SetCursor(0, 20);

	ssd1306_WriteString("SSD1306 SPI", Font_7x10, White);
	ssd1306_UpdateScreen();
}

void LCD_Off(void) {
	ssd1306_Fill(Black);
	ssd1306_UpdateScreen();

}
