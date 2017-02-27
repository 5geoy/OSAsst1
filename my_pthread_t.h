#ifndef MY_PTHREAD_T_H
#define MY_PTHREAD_T_H

typedef struct my_pthread_t {

	int thread_id;
	ucontext_t * context;
	char * string;
	my_pthread_state state;
	void* return_value;

}my_pthread_t;


typedef struct queue_node {
	int priority;
	my_pthread_t* thread;
	struct queue_node *next;
	int waiting_id;
	void **join_value;
}queue_node;


typedef struct my_pthread_attr_t {
	//fill in as needed
}my_pthread_attr_t;

typedef struct my_pthread_mutex_t {
	//fill in as needed
}my_pthread_mutex_t;

typedef struct my_pthread_mutexattr_t {
	//fill in as needed
}my_pthread_mutexattr_t;

int my_pthread_create(my_pthread_t * thread, my_pthread_attr_t * attr, void *(*function)(void*), void * arg);

void my_pthread_yield();

void my_pthread_exit(void *value_ptr);

int my_pthread_join(my_pthread_t thread, void **value_ptr);

int my_pthread_mutex_init(my_pthread_mutex_t *mutex, const my_pthread_mutexattr_t *mutexattr);

int my_pthread_mutex_lock(my_pthread_mutex_t *mutex);

int my_pthread_mutex_unlock(my_pthread_mutex_t *mutex);

int my_pthread_mutex_destroy(my_pthread_mutex_t *mutex);

queue_node* enqueue(queue_node *new_node, queue_node *last_node,int *queue_size);
	
queue_node* dequeue(queue_node ** last_node, int * queue_size);

queue_node* peek(queue_node * last_node);

void printQueue(queue_node *last_node);
#endif
