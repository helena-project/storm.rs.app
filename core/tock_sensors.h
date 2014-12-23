/*
 * tock_sensors.h
 *
 *  Created on: Dec 22, 2014
 *      Author: lauril
 */

#ifndef CORE_TOCK_SENSORS_H_
#define CORE_TOCK_SENSORS_H_
#include<pthread.h>

typedef struct SensorObj* GenericSensor;

//application object
struct SensorObj
{
	//pretty void pointer the application set the address to this pointer
	//sensor object writes to it
	void *ptr ;
	pthread_t id; //sensory thread
    void (*get)(const void* self, void *); //blocking
    void (*getPeriodic)(const void* self, void *, uint32_t t); //non blocking

};

#endif /* CORE_TOCK_SENSORS_H_ */
