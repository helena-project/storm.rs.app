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

//sub-classing the application

typedef struct Water_Application* WaterApplication;

struct Water_Application
{
    Application base;
    ResourceManager * rsm;
    Resource * temperature;
    Resource * flow;
    APP_ERROR (*init)(const void* self, ResourceManager * rm);
    APP_ERROR (*onWakeUp)(const void* self);
    APP_ERROR (*onEnteringLP)(const void* self);
};



WaterApplication NewWaterApplication();



#endif /* APPLICATION_H_ */
