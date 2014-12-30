/*
 * application.c
 *
 *  Created on: Dec 21, 2014
 *      Author: lauril
 */
#include <stdio.h>
#include <stdlib.h>
#include "application.h"
#include "sys/resource_manager.h"

RESOURCE_TYPE_UINT32T temp=0;

APP_ERROR init(OBJECT self, ResourceManager rs){
	((WaterApplication)self)->rsm = rs;
	((WaterApplication)self)->temperature = rs->getResource(rs, RESOURCE_SENSOR_TEMPERATURE);
	((WaterApplication)self)->temperature->setVar(self,RESOURCE_TYPE_UINT32T_T, (WRITEBACK) &temp);
	if( rs->schedulePeriodic(self, ((WaterApplication)self)->temperature) == RESOURCE_SCHEDULING_SUCCESS){
		printf("Init Successful\n");
	} else {
		//deal with scheduling issue (negotiation?)
		printf("scheduling error\n");
	}

	return INIT_SUCCESSFULL;
}


APP_ERROR onWakeUp(OBJECT self){

	return ON_WAKE_UP_SUCCESS;
}

APP_ERROR onEnteringLP(OBJECT self){

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

