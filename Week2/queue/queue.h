
#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <iostream>
#include <cstdlib>

#include "node.h"

template<class T>
class Queue {
private:
	Node <T> *front_q;
	Node <T> *rear_q;
public:
	Queue();
  	void enqueue(T data); //push_back
  	void dequeue(); //pops front
  	T& front(); //returns front without popping
  	int size(); //returns size 
  	bool isEmpty(); //checks to see empty

};




#endif