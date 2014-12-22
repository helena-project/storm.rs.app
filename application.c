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
