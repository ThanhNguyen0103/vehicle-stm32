/*
 * app.c
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */

#include "app.h"
#include "ignition.h"
#include "dashboard.h"
#include"drivingmode.h"

void App_Init(void) {
	Dashboard_Init();
	Ignition_Init();
	DrivingMode_Init();
}
void App_Run(void) {
	Dashboard_Run();
	Ignition_Run();
	DrivingMode_Run();

}
