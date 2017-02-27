/* Assignment 1 - Scheduler
 * Members: Lawrence Maceren, Swapneel Chalageri, George Elia
 * ilab machine tested on: cpp.cs.rutgers.edu
 * This file is the implementation of the pthreads.
 */
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
//#include "queue.c"
#include <ucontext.h>
#include <string.h>
#include <stdio.h>
#include "my_pthread_t.h"

// Global variables
int thread_counter = 1;
ucontext_t * main_context;
ucontext_t * scheduler_context;
queue_node * thread_queue_1 = NULL;
queue_node * thread_queue_2 = NULL;
queue_node * thread_queue_wait = NULL;
int init = 0;

my_pthread_t *current_thread = NULL;

//// --------------------- Thread stuff -----------------------------

int my_pthread_create(my_pthread_t * thread, my_pthread_attr_t * attr, void *(*function)(void*), void * arg){

	if (init == 0){
		my_pthread_t * init_thread = (my_pthread_t *) malloc(sizeof(my_pthread_t));
		init_thread->context = (ucontext_t *) malloc(sizeof(ucontext_t));
		
		// Initialize main
		init_thread->thread_id = 0;
		getcontext(init_thread->context);
		
		init = 1;
		
		//Add to queue?
		thread_queue_1 = enqueue(1,thread,thread_queue_1);
	}

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
	(thread->context)->uc_stack.ss_pp = malloc(100000);
	(thread->context)->uc_stack.ss_size = 100000;
	(thread->context)->uc_link = NULL;

	// Make context with function
	makecontext(thread->context, (void(*)()) function, 1, arg);

	// Add to priority queue
	queue_node * node = malloc(sizeof(queue_node));
	node->priority = 1;
	node->thread = thread;
	thread_queue_1 = enqueue(1,thread,thread_queue_1);
	
	}

	return 0;
}

void my_pthread_yield(){
	// Create timer
	
	
	
}

void my_pthread_exit(void *value_ptr){
	// Get top of each queue
	queue_node * node1 = peek(thread_queue_1);
	queue_node * node2 = peek(thread_queue_2);
	
	int infirst == 0;
	int node_id == -1;
	
	// Check each one to remove the thread
	if (node1 != NULL)
		{
		my_pthread_t * nodethread = node1->thread;
		
		if (current_thread->thread_id == nodethread->thread_id)
			{
				node1 = dequeue(&thread_queue_1));
				int node_id = (node1->thread)->thread_id;
				
				free(node1->thread);
				free(node1);
				
				infirst = 1;
			}
		}
		
	if (infirst == 0) 	// Use node2
		{
		my_pthread_t * nodethread = node2->thread;
		
		node2 = dequeue(&thread_queue_2));
		int node_id = (node1->thread)->thread_id;
		
		free(node2->thread);
		free(node2);
		}
	
	// Remove from waiting queue
	
	current_thread = NULL;
	my_pthread_yield();
	return;
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
