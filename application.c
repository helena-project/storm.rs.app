/*
 * application.c
 *
 *  Created on: Dec 21, 2014
 *      Author: lauril
 */
#include <stdio.h>

#include "application.h"


APP_ERROR init(RESOURCE_MANAGER rs){
	printf("Init Successful %d\n", *rs);
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
	WaterApplication self = (WaterApplication)malloc(sizeof(struct Water_Application));

    self->base = ApplicationObj();
    self->init = init;
    self->onWakeUp = &onWakeUp;
    self->onEnteringLP = &onEnteringLP;

    return self;
}

