/*
 * app.c
 *
 *  Created on: Jul 3, 2026
 *      Author: nguyz
 */

#include "app.h"
#include "ignition.h"
#include "dashboard.h"

void App_Init(void) {
	Ignition_Init();
}
void App_Run(void) {

	Ignition_Run();
	Dashboard_Run();
}
