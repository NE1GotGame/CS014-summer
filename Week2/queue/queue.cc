#include "queue.h"
#include "stack.h"

Queue::Queue(){
	front_q = NULL;
	rear_q = NULL;
}


void Queue::enqueue(Stack data){
	if(!front_q){
		Node *temp = new Node;

		temp->value = data;
		temp->next = NULL;

		front_q = temp;
		rear_q = temp;
	}
	else{
		
		Node *new_temp = new Node;
		new_temp->value = data;
		new_temp->next = NULL;

		rear_q->next = new_temp;
		
		rear_q = new_temp;
	}
	return;
}


void Queue::dequeue(){
	if(!front_q)
		return;
	else{
		Node *temp = front_q;
		front_q = temp->next;
		delete temp;
	}
}


Stack Queue::front(){
	//if (head)
		return front_q->value;
}

int Queue::size(){
	int counter = 0;
	if(!front_q)
		return -1;
	else{
		
		Node *temp = front_q;
		while(temp){
			temp = temp->next;
			counter++;
		}
	}
	return counter;
}


bool Queue::isEmpty(){
	if(front_q){
		return false;
	}
	else{
		return true;
	}
}



