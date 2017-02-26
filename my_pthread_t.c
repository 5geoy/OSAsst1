/* Assignment 1 - Scheduler
 * Members: Lawrence Maceren, Swapneel Chalageri, George Elia
 * ilab machine tested on: XXXXX.cs.rutgers.edu
 * This file is the implementation of the pthreads.
 */
#include <stdlib.h>
#include "my_pthread_t.h"
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <ucontext.h>
#include "queue.c"
#include <string.h>

#define STACKSIZE = 1000000

// Global variables
int thread_counter = 1;
int initial_thread = 1;
queue * q;
ucontext_t * main_context; 
ucontext_t * scheduler_context;

int my_pthread_create(my_pthread_t *thread, my_pthread_attr_t *attr, void *(*function)(void*), void * arg){

	// Initialize thread
	thread = (my_pthread_t *) malloc(sizeof(my_pthread_t));
	thread->context = (ucontext_t *) malloc(sizeof(ucontext_t));

	// Get context
	if (getcontext(thread->context) == -1)
		{
		// Error
		return -1;
		}

	// Set thread id, stack
	thread->thread_id = thread_counter++;
	(thread->context)->uc_stack.ss_pp = malloc(STACK_SIZE);
	(thread->context)->uc_stack.ss_size = STACK_SIZE;
	(thread->context)->uc_link = NULL;

	// Make context with function
	makecontext(thread->context, (void(*)()) function, 1, arg);

	// Add to priority queue

	// Do stuff needed if this is the first thread made
	if (initial_thread == 1)
		{
		initial_thread = 0;
		}

	return 0;
}

void my_pthread_yield(){
}

void my_pthread_exit(void *value_ptr){
}

int my_pthread_join(my_pthread_t thread, void **value_ptr){
}

int my_pthread_mutex_init(my_pthread_mutex_t *mutex, const my_pthread_mutexattr_t *mutexattr){
}

int my_pthread_mutex_lock(my_pthread_mutex_t *mutex){
}

int my_pthread_mutex_unlock(my_pthread_mutex_t *mutex){
}

int my_pthread_mutex_destroy(my_pthread_mutex_t *mutex){
}
