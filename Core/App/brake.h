/*
 * brake.h
 *
 *  Created on: Jul 21, 2026
 *      Author: nguyz
 */

#ifndef APP_BRAKE_H_
#define APP_BRAKE_H_

typedef enum {
	BRAKE_ON, BRAKE_OFF
} Brake_State_t;

void Brake_Init(void);
void Brake_Run(void);
Brake_State_t Brake_GetState(void);

#endif /* APP_BRAKE_H_ */
