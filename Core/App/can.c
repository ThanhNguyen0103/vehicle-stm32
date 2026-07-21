/*
 * can.c
 *
 *  Created on: Jul 18, 2026
 *      Author: nguyz
 */

#include "can.h"
#include "uart.h"
#include "stdio.h"
void CAN_Init() {
//
}

void CAN_Send(CAN_Frame_t *frame) {
	char data[64];
	sprintf(data, "ID:%03X DLC:%d DATA:\r\n", frame->id, frame->dlc);
	UART_SendString(data);
	for (int i = 0; i < frame->dlc; i++) {
		sprintf(data, "%d \r\n", frame->data[i]);
		UART_SendString(data);
	}

}
