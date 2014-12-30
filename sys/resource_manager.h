/*
 * resource_manager.h
 *
 *  Created on: Dec 21, 2014
 *      Author: lauril
 */

#ifndef SYS_RESOURCE_MANAGER_H_
#define SYS_RESOURCE_MANAGER_H_

#define OBJECT const void*
#define WRITEBACK void *
#define RESOURCE_MANAGER int*
#define RESOURCE_TYPE int


#define RESOURCE_KIND				int
#define RESOURCE_SENSOR_TEMPERATURE 100
#define RESOURCE_SENSOR_FLOW		101
#define RESOURCE_STORAGE_FLASH		200
#define RESOURCE_SECURITY_ENCRYPT	300
#define RESOURCE_COMM_ANY			400
#define RESOURCE_COMM_BLE			401
#define RESOURCE_COMM_ZIGBEE		402


#define RESOURCE_TYPE_UINT8T		uint8_t
#define RESOURCE_TYPE_UINT16T		uint16_t
#define RESOURCE_TYPE_UINT32T		uint32_t
#define RESOURCE_TYPE_INT8T			int8_t
#define RESOURCE_TYPE_INT16T		int16_t
#define RESOURCE_TYPE_INT32T		int32_t
#define RESOURCE_TYPE_FLOAT			float

#define RESOURCE_TYPE				int
#define RESOURCE_TYPE_UINT8T_T		0
#define RESOURCE_TYPE_UINT16T_T		1
#define RESOURCE_TYPE_UINT32T_T		2
#define RESOURCE_TYPE_INT8T_T		3
#define RESOURCE_TYPE_INT16T_T		4
#define RESOURCE_TYPE_INT32T_T		5
#define RESOURCE_TYPE_FLOAT_T		6

#define RESOURCE_ERROR_TYPE_ERROR	1000 // var is of wrong type
#define RESOURCE_SCHEDULING_ERROR_T	int
#define RESOURCE_SCHEDULING_SUCCESS	1100 //
#define RESOURCE_SCHEDULING_ERROR	1101 //


typedef struct ResourceObj* Resource;

//Resource manger object
struct ResourceObj
{
	RESOURCE_TYPE resourcetype;
	void * resource;
    void * (*setVar)(OBJECT self, RESOURCE_TYPE type, WRITEBACK resource);
    RESOURCE_TYPE (*getType)(OBJECT self);

};

typedef struct ResourceManagerObj* ResourceManager;

//Resource manger object
struct ResourceManagerObj
{
	Resource  (*getResource)(OBJECT self, RESOURCE_KIND kind);
	RESOURCE_SCHEDULING_ERROR_T (*schedulePeriodic)(OBJECT self, Resource rsc);
	RESOURCE_SCHEDULING_ERROR_T (*scheduleOneShoot)(OBJECT self, Resource rsc);
};

Resource  (*getResource)(OBJECT self, RESOURCE_KIND kind);
RESOURCE_SCHEDULING_ERROR_T (*schedulePeriodic)(OBJECT self, Resource rsc);
RESOURCE_SCHEDULING_ERROR_T (*scheduleOneShoot)(OBJECT self, Resource rsc);

ResourceManager NewResourceManager();



#endif /* SYS_RESOURCE_MANAGER_H_ */
