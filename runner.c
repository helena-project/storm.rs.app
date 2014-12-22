/*
 * runner.c
 *
 *  Created on: Dec 22, 2014
 *      Author: lauril
 */


//just to run example without no logic
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include "sys/application_errors.h"
#include "sys/resource_manager.h"

int main( void ){
	void *handle;
	APP_ERROR (*init_app)(RESOURCE_MANAGER);
	char *error;
	int tmp = 100;
	int *resource_mng = &tmp;

	handle = dlopen ("libapp.so", RTLD_NOW);
	if (!handle) {
		fputs (dlerror(), stderr);
		printf ("\n");
		exit(1);
	}

	init_app = dlsym(handle, "init");
	if ((error = dlerror()) != NULL)  {
		fputs(error, stderr);
		printf ("\n");
		exit(1);
	}

	printf ("%d\n", (*init_app)(resource_mng));
	dlclose(handle);

	return 0;
}
