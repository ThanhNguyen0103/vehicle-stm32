/*
 * lcd.h
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */

#ifndef DRIVERS_LCD_H_
#define DRIVERS_LCD_H_

void Lcd_On(void);
void Lcd_Off(void);
void LCD_Clear(void);
void LCD_Print(uint8_t x, uint8_t y, char *text);

void LCD_Update(void);

#endif /* DRIVERS_LCD_H_ */
