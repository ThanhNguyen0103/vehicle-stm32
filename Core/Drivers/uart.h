/*
 * uart.h
 *
 *  Created on: Jul 18, 2026
 *      Author: nguyz
 */

#ifndef DRIVERS_UART_H_
#define DRIVERS_UART_H_
#include "stdint.h"

void UART_Init(void);
void UART_SendString(char *str);
void UART_SendBuffer(uint8_t *data, uint16_t len);

#endif /* DRIVERS_UART_H_ */
