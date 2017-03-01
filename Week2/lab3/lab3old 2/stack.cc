/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: lab3
 * Filename : stack.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include "stack.h"
#include <iostream>
#include <cstdlib>

Stack::Stack(int cap){
	topp = -1;
	capacity = cap;
	location = new int[capacity];
}
void Stack::push(const int& x){
	if(topp + 1 < capacity ){
		topp++;
		location[topp] = x;
	}
	else{
		std::cout << "cannot push bc stack is full\n";
	}
}
int& Stack::top(){
	return location[topp];
}

void Stack::pop(){
	if (!is_empty()){
		topp--;
	}
}
bool Stack::is_empty() const{
	if(topp + 1 <= 0 ){
		return true;
	}
	else{
		return false;
	}
}


