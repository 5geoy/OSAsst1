#CC     =       cc
CC      =       gcc
ROOT    =       /OSAsst1
FLAGS   =       -g -Wall
COMPILE =       $(CC) $(FLAGS)

all:    my_pthreadlib libtest

my_pthreadlib:		my_pthread_t.c my_pthread_t.h
		$(COMPILE)  -c my_pthread_t.c
		
libtest:			my_pthread_t.o pthreadTest.c
		$(COMPILE) -o tester pthreadTest.c my_pthread_t.o
clean:
		rm -rf  tester my_pthread_t.o
