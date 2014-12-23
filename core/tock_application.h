/*
 * tock_application.h
 *
 *  Created on: Dec 22, 2014
 *      Author: lauril
 */

#ifndef CORE_TOCK_APPLICATION_H_
#define CORE_TOCK_APPLICATION_H_

#include "sys/application_errors.h"
#include "sys/resource_manager.h"

typedef struct ApplicationObj* Application;

//application object
struct ApplicationObj
{
    char* (*init)(const void* self, RESOURCE_MANAGER rm);
    void (*onWakeUp)(const void* self, char* value);
    int (*onEnteringLP)(const void* self);
};

/// main application methods called from the core

APP_ERROR init(const void* self, RESOURCE_MANAGER rm);
APP_ERROR onWakeUp(const void* self);
APP_ERROR onEnteringLP(const void* self);

Application NewApplication();

#endif /* CORE_TOCK_APPLICATION_H_ */
