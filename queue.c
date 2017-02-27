
/*
  builds a queue_node and places at end of queue
  return last_node after new enqueue
	
*/


queue_node* enqueue(queue_node * new_node, queue_node *last_node,int * queue_size){

	if(last_node==NULL){
		new_node->next = NULL;
		(*queue_size)++;
		return new_node;
	}
	new_node->next = last_node;
	(*queue_size)++;
	return new_node;

}



/*
	dequeue(&queue)
  will remove first queue_node in queue
*/


queue_node* dequeue(queue_node ** last_node, int * queue_size){
	
	if((*last_node) == NULL)
		return NULL;
	queue_node *ptr = NULL;
	queue_node *prev = NULL;
	ptr = (*last_node);
	while(ptr->next){
		prev = ptr;
		ptr = ptr->next;
	}
	if(prev){
		prev->next = NULL;
	}else{
		(*last_node) = NULL;
	}
	(*queue_size)--;
	return ptr;
}

/*
	peek will look at the front queue_node
*/
queue_node* peek(queue_node * last_node){
	if(last_node == NULL){
		return NULL;
	}
	queue_node *ptr = NULL;
	ptr = last_node;
	while(ptr->next){
		ptr++;
	}
	return ptr;
}

/*
	print all values in the queue
*/


void printQueue(queue_node *last_node){
	queue_node *ptr = last_node;
	//printf("%s\n", iter->thread->string);
	while(ptr){
		printf("%s\n", ptr->thread->string);
		ptr++;
	}
}
