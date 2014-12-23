/*
 * application.h
 *
 *  Created on: Dec 21, 2014
 *      Author: lauril
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

//mandatory application skeleton
#include "sys/application_errors.h"
#include "sys/resource_manager.h"
#include "core/tock_application.h"

APP_ERROR init(RESOURCE_MANAGER rm);
//sub-classing the application

typedef struct Water_Application* WaterApplication;

struct Water_Application
{
    Application base;

    char* (*init)(const void* self, RESOURCE_MANAGER rm);
    void (*onWakeUp)(const void* self, char* value);
    int (*onEnteringLP)(const void* self);
};

WaterApplication NewWaterApplication();



#endif /* APPLICATION_H_ */
