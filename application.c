/*
 * application.c
 *
 *  Created on: Dec 21, 2014
 *      Author: lauril
 */
#include <stdio.h>
#include <stdlib.h>
#include "application.h"


APP_ERROR init(const void * self, ResourceManager*  rs){
	((WaterApplication)self)->rsm = rs;
	((WaterApplication)self)->temperature = ((ResourceManager)((WaterApplication)self)->rsm)->
											getResource(((ResourceManager)((WaterApplication)self)->rsm),RESOURCE_SENSOR_TEMPERATURE);
	printf("Init Successful\n");
	return INIT_SUCCESSFULL;
}


APP_ERROR onWakeUp(const void* self){

	return ON_WAKE_UP_SUCCESS;
}

APP_ERROR onEnteringLP(const void* self){

	return ON_ENTERING_LPL_SUCCESS;
}

WaterApplication NewWaterApplication()
{
	WaterApplication self = (WaterApplication) malloc(sizeof(struct Water_Application));

    self->base = NewApplication();
    self->init = &init;
    self->onWakeUp = &onWakeUp;
    self->onEnteringLP = &onEnteringLP;

    return self;
}

