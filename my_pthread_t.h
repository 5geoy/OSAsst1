#ifndef MY_PTHREAD_T_H_
#define MY_PTHREAD_T_H_

typedef struct queue_node {
	int priority;
	my_pthread_t* thread;
	struct queue_node *next;
}queue_node;


typedef struct my_pthread_t {
	//fill in with rest needed
	int thread_id;
	ucontext_t * context;
	char * function_name;
}my_pthread_t;


int my_pthread_create( pthread_t * thread, pthread_attr_t * attr, void *(*function)(void*), void * arg);

void my_pthread_yield();

void pthread_exit(void *value_ptr);

int my_pthread_join(pthread_t thread, void **value_ptr);

int my_pthread_mutex_init(my_pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);

int my_pthread_mutex_lock(my_pthread_mutex_t *mutex);

int my_pthread_mutex_unlock(my_pthread_mutex_t *mutex);

int my_pthread_mutex_destroy(my_pthread_mutex_t *mutex);
#endif
