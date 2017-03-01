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
#include <stdexcept>
#include <cstdlib>
template<class T>
Stack<T>::Stack(){
	topp = -1;
	capacity = 0;
	location = new T[capacity];
}

template<class T>
Stack<T>::Stack(unsigned cap){
	topp = -1;
	capacity = cap;
	location = new T[capacity];
}

template<class T>
void Stack<T>::push(const T& x){
	if(topp+1 >= capacity)
		throw std::overflow_error("overflow_error: The capacity of the stack is too small.\n");
	else{
		topp++;
		location[topp] = x;
	}
}

template<class T>
T& Stack<T>::top(){
	if(topp == -1)
		throw std::underflow_error("underflow_error: Stack is empty.");
	else
		return location[topp];
}

template<class T>
void Stack<T>::pop(){
	if(topp != -1)
		topp--;
	else
		throw std::underflow_error("underflow_error: The stack is empty.");
}

template<class T>
bool Stack<T>::is_empty() const{
	if(topp == - 1 )
		return true;
	else
		return false;
}

template class Stack<int>;
template class Stack<double>;