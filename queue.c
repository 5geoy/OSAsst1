
/*
  buildss a queue_node and places at end of queue
  return last_node after new enqueue
*/

queue_node* enqueue(int priority, my_pthread_t * thread, queue_node *last_node){

	queue_node new_node = malloc(sizeof(queue_node));
	new_node->priority = priority;
	new_node->thread = thread;

	if (last_node == NULL){
		new_node->next = NULL;
	} else {
		new_node->next = last_node;
	}

	return new_node;
}

/*
	dequeue(&queue)
  will remove first queue_node in queue
*/


queue_node* dequeue(queue_node ** last_node){

	if((*last_node) == NULL){
		return NULL;
	}
	queue_node *ptr = NULL;
	queue_node *prev = NULL;

	for (queue_node *ptr = (*last_node); ptr->next != NULL; ptr++){
		prev = ptr;
	}

	if (prev != NULL){
		prev->next = NULL;
	} else {
		(*last_node) = NULL;
	}

	return ptr;

}

/*
	peek will look at the front queue_node
*/
queue_node* peek(queue_node * last_node){
	if(last_node == NULL){
		return NULL;
	}

	queue_node *ptr = last_node;

	while(ptr->next != NULL){
		ptr++;
	}
	return ptr;
}

/*
	print all values in the queue
*/

void printQueue(queue_node * last_node){
	queue_node *ptr = last_node;
	printf("%s\n", ptr->thread->function_name);
	while(ptr != NULL){
		printf("%s\n", ptr->thread->function_name);
		ptr++;
	}
}
