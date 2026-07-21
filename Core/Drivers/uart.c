/*
 * uart.c
 *
 *  Created on: Jul 18, 2026
 *      Author: nguyz
 */

#include "uart.h"
#include"main.h"
#include "String.h"

extern UART_HandleTypeDef huart1;

void UART_Init(void) {
	//
}
void UART_SendString(char *str) {
	HAL_UART_Transmit(&huart1, (uint8_t*) str, strlen(str),
	HAL_MAX_DELAY);
}

void UART_SendBuffer(uint8_t *data, uint16_t len) {
	HAL_UART_Transmit(&huart1, data, len, HAL_MAX_DELAY);
}

