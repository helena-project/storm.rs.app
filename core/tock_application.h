/*
 * tock_application.h
 *
 *  Created on: Dec 22, 2014
 *      Author: lauril
 */

#ifndef CORE_TOCK_APPLICATION_H_
#define CORE_TOCK_APPLICATION_H_

#include "../sys/application_errors.h"
#include "../sys/resource_manager.h"

typedef struct ApplicationObj* Application;

//application object
struct ApplicationObj
{
    char* (*init)(OBJECT self, ResourceManager * rm);
    void (*onWakeUp)(OBJECT self, char* value);
    int (*onEnteringLP)(OBJECT self);
};

/// main application methods called from the core

APP_ERROR init(OBJECT self, ResourceManager * rm);
APP_ERROR onWakeUp(OBJECT self);
APP_ERROR onEnteringLP(OBJECT self);

Application NewApplication();

#endif /* CORE_TOCK_APPLICATION_H_ */
