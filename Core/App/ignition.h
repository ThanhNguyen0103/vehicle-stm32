/*
 * ignition.h
 *
 *  Created on: Jul 4, 2026
 *      Author: nguyz
 */

#ifndef APP_IGNITION_H_
#define APP_IGNITION_H_

void Ignition_Run(void);
void Ignition_Init(void);

typedef enum {
	IGNITION_OFF, IGNITION_ON
} IgnitionState_t;

IgnitionState_t Ignition_GetState(void);

#endif /* APP_IGNITION_H_ */
