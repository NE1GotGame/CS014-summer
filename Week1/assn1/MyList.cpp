/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn1
 * Filename : MyList.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <string>
#include "MyList.h"
#include "node.h"

MyList::MyList(){
	head = 0;
}

MyList::MyList(const MyList& str){//done
	head = 0;

	Node *curr = str.head;
	while(curr){
		push_back(curr->value);
		curr = curr->next;
	}
}

MyList::MyList(const string& str){//done
	head = 0;
	for(unsigned i = 0; i < str.length(); i++){
		push_back(str.at(i));
	}
}

MyList::MyList(const char* str){//done
	head = 0;
	string stringo = string(str);
	for(unsigned i = 0; i < stringo.length(); i++){
		push_back(stringo.at(i));
	}
}

MyList::~MyList(){ //done
	cout << "Deleting.... ";
	while(head)
	{
		Node* temp = head;
		head = head->next;
		cout << temp->value << ' ';
		delete temp;
	}
	cout << endl;
}

/* Mutators */
void MyList::push_front(char value){ //done
	Node *temp;
    temp = head;
    head = new Node;
    head->value = value;
    head->next = temp;
}

void MyList::push_back(char value){ //done

	if(!head){
		Node *temp = new Node;
		temp->value = value;
		temp->next = 0;
		head = temp;
	}
	else{

		Node *temp = head;
		while(temp->next){
			temp = temp->next;
		}
		Node *new_temp = new Node;
		new_temp->value = value;
		temp->next = new_temp;
		new_temp->next = 0;
	}
}

void MyList::pop_front(){ //done
	if(!head)
		return;
	else{
		Node *temp = head;
		head = temp->next;
		delete temp;
	}
}

void MyList::pop_back(){ //done
	if(!head)
		return;
	else{
		Node *temp = head;
		int counter = 0;
		while(temp->next){
			temp = temp->next;
			counter++;
		}
		delete temp;
		temp = head;
		for(int i = 0; i < counter - 1; i++){
			temp = temp->next;
		}
		temp->next = 0;
	}
}

void MyList::swap(int i, int j){
	if(i < 0){
		i = 0;
	}
	if(i > size() - 1){
		i = size() - 1;
	}
	if(j < 0){
		j = 0;
	}
	if(j > size() - 1){
		j = size() - 1;
	}

	if(i == j){
		return;
	}
	
	Node *curr1 = head;
	Node *curr2 = head;
	for(int k = 0; k < i; k++){
		curr1 = curr1->next;
	}
	char value1 = curr1->value;

	for(int k = 0; k < j; k++){
		curr2 = curr2->next;
	}
	char value2 = curr2->value;

	curr1->value = value2;
	curr2->value = value1;
}

void MyList::insert_at_pos(int i, char value){ //done
	if(!head){
		push_front(value);
		return;
	}
	Node* temp = new Node;
	temp->value = value;
	Node* curr = head;
	Node* prev_curr;
	int counter = 0;
	while(curr){
		curr = curr->next;
		counter++;
	}
	curr = head;

	if(i <= 0){
		push_front(value);
	}
	else if( i > counter){
		push_back(value);
	}
	else{
		for(int j = 0; j < i; j++){
			prev_curr = curr;
			curr = curr->next;
		}
		prev_curr->next = temp;
		temp->next = curr;
	}
}

void MyList::reverse(){ //done
	if(size() == 1)
		return;
	Node *curr = head;
	char arr[size()];
	for(int i = 0; i < size(); i++){
		arr[i] = curr->value;
		curr = curr->next;
	}
	curr = head;
	for(int i = size()-1; i >= 0; i--){
		curr->value = arr[i];
		curr = curr->next;
	}
}

//  Accessors 
int  MyList::size()const{ //done
	if(!head)
		return -1;
	int counter = 0;
	Node *curr = head;
	while(curr){
		curr = curr->next;
		counter++;
	}
	return counter;
}

void MyList::print()const{ //done
	Node *curr = head;
	while(curr){
		cout << curr->value << ", ";
		curr = curr->next;
	}
	cout << "\n";
}

int  MyList::find(char value)const{//done
	if(!head)
		return -1;
	int counter = 0;
	Node *curr = head;
	while(curr != 0){
		if(curr->value == value)
			return counter;
		counter++;
		curr = curr->next;
	}
	return -1;
}

int  MyList::find(MyList& query_str)const{ //done
	if(query_str.size() > size()){ //if the query is bigger
		return -1;
	}
	else{
		Node *curr = head;
		Node *curr_check;
		Node *q_curr = query_str.head;
		int cur_pos = 0;
		int q_count = 0;
		int q_length = query_str.size();
		while(curr){ // going through list
			
			if(curr->value == q_curr->value){ //if matches qhead
				curr_check = curr; //pointer
				while(curr_check){ // while it isnt the end of the list
					if(q_curr->value == curr_check->value){ //
						q_curr = q_curr->next;
						curr_check = curr_check->next;
						q_count++;
					}
					else{ //reset
						q_count = 0;
						q_curr = query_str.head;
						break;
					}

					if (q_count == q_length){ // if matching is complete
						return cur_pos;
					}

				}
			}
			cur_pos++;
			curr = curr->next;			
		}
	}
	return -1;
}

// /* Operator overloads */
MyList MyList::operator=(const MyList& str){//done
	if(this != &str){
		delete head;
		head = str.head;
	}
	return *this;
}

char& MyList::operator[](const int i){//done
	Node *curr = head;
	for(int j = 0; j < i; j++){
		curr = curr->next;
	}
	return curr->value;
}

MyList MyList::operator+(const MyList& str){ //join lists
	Node *str_curr = str.head;
	
	while(str_curr){

		this->push_back(str_curr->value);
		str_curr = str_curr->next;
	}
	return *this;
}