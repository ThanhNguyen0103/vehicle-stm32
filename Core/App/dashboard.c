/*
 * dashboard.c
 *
 *  Created on: Jul 4, 2026
 *      Author: nguyz
 */

#include "dashboard.h"
#include "ignition.h"
#include "drivingmode.h"
#include "ssd1306.h"
#include "ssd1306_fonts.h"
#include "vehiclespeed.h"

static IgnitionState_t preIgnition = IGNITION_OFF;
static Driving_Mode_t preMode = ECO_MODE;
static uint32_t preSpeed = 0;
void Dashboard_Init(void) {
	ssd1306_Init();
}

void Dashboard_Run(void) {

	IgnitionState_t ignition = Ignition_GetState();
	Driving_Mode_t mode = DrivingMode_GetState();
	uint32_t speed = VehicleSpeed_GetSpeed();

	if (ignition == preIgnition && mode == preMode && speed == preSpeed) {
		return;
	}
	preIgnition = ignition;
	preMode = mode;
	preSpeed = speed;
	char speedStr[16];

	snprintf(speedStr, sizeof(speedStr), "%lu km/h", speed);

	ssd1306_Fill(Black);

	ssd1306_SetCursor(0, 0);
	ssd1306_WriteString("IGNITION:", Font_7x10, White);

	ssd1306_SetCursor(80, 0);
	ssd1306_WriteString(ignition == IGNITION_ON ? "ON" : "OFF", Font_7x10,
			White);

	ssd1306_SetCursor(0, 20);
	ssd1306_WriteString("MODE:", Font_7x10, White);

	ssd1306_SetCursor(80, 20);
	if (ignition == IGNITION_OFF) {
		ssd1306_WriteString("---", Font_7x10, White);
	} else {
		ssd1306_WriteString(mode == ECO_MODE ? "ECO" : "SPORT", Font_7x10,
				White);
	}

	ssd1306_SetCursor(0, 40);
	ssd1306_WriteString("SPEED:", Font_7x10, White);

	ssd1306_SetCursor(80, 40);
	ssd1306_WriteString(speedStr, Font_7x10, White);
	ssd1306_UpdateScreen();

}
