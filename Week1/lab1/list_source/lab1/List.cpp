/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: lab1
 * Filename : List.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <cstdlib>
#include "List.h"
#include "Node.h"
#include "Iterator.h"

using namespace std;

/**
 * Constructor
 */
List::List()
{
	head = NULL;
	tail = NULL;
}

/**
 * Destructor
 */
List::~List()
{
	cout << "\nList Destructor called...\n";
	
	while(head)
	{
		Node* temp = head;
		head = head->get_next();
		cout << "Deleting.... " << temp->get_value() << endl;
		delete temp;
	}	
}

/**
 * push_back() inserts a new node at the tail
 * end of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_back(int value)
{
	Node* new_node = new Node(value);
	
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_prev(tail);
		tail->set_next(new_node);
		tail = new_node;
	}
}
/**
 * push_front() inserts a new node at the 
 * front of the list, with a given value
 * @param value an integer Node value
 * @return none
 */
void List::push_front(int value)
{
	Node* new_node = new Node(value);
		
	/* list is empty */
	if(!head)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->set_next(head);
		head->set_prev(new_node);
		head = new_node;			
	}
}

/**
 * print()const prints the contents of 
 * the list to the console, starting
 * at the head of the list
 * @param none
 * @return none
 */
void List::print()const
{
	cout << "\nList contents:\n";

	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos())
	{
		cout << iter.get_value() << ", ";
	}
	cout << "\n";
}

/**
 * get_head()const returns the head
 * Node pointer which points to the
 * first element in the list
 * @param none
 * @return List's head Node pointer
 */
Node* List::get_head()const
{
	return head;
}

/**
 * get_tail()const  returns the tail
 * Node pointer which points to the
 * last element in the list
 * @param none
 * @return List's tail Node pointer
 */
Node* List::get_tail()const
{
	return tail;
}

/**
 * begin()const gets beginning postion of the list
 * @param none
 * @return an Iterator pointing to the beginning of the list
 */
Iterator List::begin()const
{
	Iterator iter;
	iter.set_curr_pos(get_head());
	iter.set_last_pos(get_tail());
	return iter;
}

/**
 * end()const gets past-the-end postion of the list
 * @param none
 * @return an Iterator pointing just past the end of the list
 */
Iterator List::end()const
{
	Iterator iter;
	iter.set_curr_pos(NULL);
	iter.set_last_pos(get_tail());
	return iter;
}

void List::sorted_insert(int value){
	Node* temp = new Node(value);
	Node* curr = head;
	Node* prev_curr;
	if(!head){	//empty list
		push_front(value);
	}
	else if(value < head->get_value()){	//if value is less than head
		push_front(value);
	}
	else if(value > tail->get_value()){ //if value is more than tail
		push_back(value);
	}

	else{	//middle insert

		prev_curr = 0;
		while(curr != 0){
			if(curr->get_value() >= value){
				break;
			}

			else{
				prev_curr = curr;
				curr = curr->get_next();
			}
		}
		
		temp->set_next(curr);
		temp->set_prev(prev_curr);
		prev_curr->set_next(temp);
		curr->set_prev(temp);
	}
}



void List::print_reverse()const{
	cout << "\nList contents:\n";
	/* list is empty */
	if(!head)
	{
		cout << "empty\n";
		return;
	}
	Node* temp = tail;
	List tempo;
	while (temp){
		cout << temp->get_value() << ", ";
		temp = temp->get_prev();
	}
	cout << "\n";
	

}


void List::insertAfter(int i, int value){

	Node* temp = new Node(value);
	Node* curr = head;
	Node* prev_curr;

	int total_size = 0;
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()){
		total_size++;
	}

	if(!head){
		head = temp;
		tail = temp;
	}
	else if(i >= total_size)
		push_back(value);
	else if(i < 0)
		push_front(value);


	else{	//middle insert
		int counter = 0;
		prev_curr = 0;
		while(counter <= i){
			prev_curr = curr;
			curr = curr->get_next();
			counter++;
		}
		
		temp->set_next(curr);
		temp->set_prev(prev_curr);
		prev_curr->set_next(temp);
		curr->set_prev(temp);
	}
}

void List::insertBefore(int i, int value){
	Node* temp = new Node(value);
	Node* curr = head;
	Node* prev_curr;

	int total_size = 0;
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()){
		total_size++;
	}

	if(!head){
		head = temp;
		tail = temp;
	}
	else if(i > total_size)
		push_back(value);
	else if(i <= 0)
		push_front(value);


	else{	//middle insert
		int counter = 0;
		prev_curr = 0;
		while(counter < i){
			prev_curr = curr;
			curr = curr->get_next();
			counter++;
		}
		temp->set_next(curr);
		temp->set_prev(prev_curr);
		prev_curr->set_next(temp);
		curr->set_prev(temp);
	}
}

int List::count(int value)const{
	int count = 0;
	for(Iterator iter = begin(); !iter.is_equal(end()); iter.next_pos()){
		if(iter.get_value() == value){
			count++;
		}
	}
	return count;
}

















