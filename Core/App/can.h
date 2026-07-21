/*
 * can.h
 *
 *  Created on: Jul 18, 2026
 *      Author: nguyz
 */

#ifndef APP_CAN_H_
#define APP_CAN_H_
#include "stdint.h"

typedef enum {
	CAN_ID_IGNITION = 0x100,
	CAN_ID_DRIVING_MODE = 0x101,
	CAN_ID_VEHICLE_SPEED = 0x102
} CAN_ID_t;
typedef struct {
	uint16_t id;
	uint8_t dlc;
	uint8_t data[8];
} CAN_Frame_t;

void CAN_Init(void);
void CAN_Send(CAN_Frame_t *frame);

#endif /* APP_CAN_H_ */
