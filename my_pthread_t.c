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
queue * queue;
ucontext_t * main_context;
ucontext_t * scheduler_context;
int init = 0;


int my_pthread_create(my_pthread_t *thread, my_pthread_attr_t *attr, void *(*function)(void*), void * arg){

	if (init == 0){
		// special case on the first iteration

		// Allocate memory for thread stack
		char * thread_stack = (char *)malloc(2048);

		// Create ucontext
		ucontext_t context;
		ucontext_t * main_context = &context;

		// Initialize ucontext
		if (getcontext(main_context) == -1) {
		return -1;
		}

		main_context->uc_stack.ss_sp = thread_stack;
		main_context->uc_stack.ss_size = sizeof(thread_stack);
		main_context->uc_link = sched_ctx;

		//not sure what to put here
		makecontext(main_context, (void (*)(void))function, 1, ******);

		/// Library: new thread initialized\n");

		// Add thread ucontext to queue
		enqueue(queue, main_context);

	} else {

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
	queue_node *node = malloc(sizeof(queue_node));
	node->priority = 1;
	node->thread = thread;
	queue = enqueue(1,thread,queue);
	
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
