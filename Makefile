CC=gcc-4.9

RUNNER := runner
APP := application
APP_LIB := libapp.so

SRCS = APPLICATION.c RUNNER.c
OBJS := ${SRCS:.c=.o}



program_INCLUDE_DIRS := 
program_LIBRARY_DIRS :=
program_LIBRARIES := lib

CCFLAGSLIB =-c -Wall -Werror -fpic
CCSHARED = $(CC) -shared -o
COMP_LIB := $(CC) $(CCFLAGSLIB) 

.PHONY: all

all: 
	$(COMP_LIB) $(APP).c
	$(CCSHARED) $(APP_LIB) $(APP).o
	$(CC) $(RUNNER).c -o $(RUNNER)