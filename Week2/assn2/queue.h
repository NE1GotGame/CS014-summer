
#ifndef __QUEUE_H_
#define __QUEUE_H_

#include <iostream>
#include <cstdlib>

#include "node.h"
#include "stack.h"

class Queue {
private:
	Node *front_q;
	Node *rear_q;
public:
	Queue();
  	(Stack <std::string> data); //push_back
  	void dequeue(); //pops front
  	Stack <std::string> & front(); //returns front without popping
  	int size(); //returns size 
  	bool isEmpty(); //checks to see empty

};




#endif