/*
 * application.c
 *
 *  Created on: Dec 21, 2014
 *      Author: lauril
 */
#include <stdio.h>
#include <stdlib.h>
#include "application.h"

#define mGetResource(type, self, resource, resource_kind)\
	((type)self)->resource = ((ResourceManager)((type)self)->rsm)->getResource(((ResourceManager)((type)self)->rsm)->resource_kind)

#define foo(x,y,z,i) int a= x+y+z+i

APP_ERROR init(OBJECT self, ResourceManager*  rs){
	((WaterApplication)self)->rsm = rs;
	((WaterApplication)self)->temperature = ((ResourceManager*)rs)->getResource(rs, RESOURCE_SENSOR_TEMPERATURE);

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

