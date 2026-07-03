/*
 * lcd.h
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */

#ifndef DRIVERS_LCD_H_
#define DRIVERS_LCD_H_

void LCD_On(void);
void LCD_Off(void);

typedef enum {
	LCD_OFF = 0, LCD_ON
} LCD_State_t;

#endif /* DRIVERS_LCD_H_ */
