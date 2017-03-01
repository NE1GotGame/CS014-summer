/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn2
 * Filename : stack.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <list>

template <class T>
class stack{
	private:
		std::list<T> stack_list; //using DL list
	public:
		stack(); // default constructor
		stack(const stack& rhs); // copy constructor
		T& top(); //peek at stack
		const T& top() const; //peek at stack
		void pop(); //take off stack
		void push(T item); //place on top fo stack
		bool empty() const; // if size = 0
		int size() const; //size 0-N
		stack operator=(const stack& rhs); //overloaded assn
};

template <class T>
stack<T>::stack(){}

template <class T>
stack<T>::stack(const stack& rhs){
	stack_list = rhs.stack_list;
}

template <class T>
T& stack<T>::top(){
	return stack_list.front();
}

template <class T>
const T& stack<T>::top() const{
	return stack_list.front();
}

template <class T>
void stack<T>::pop(){
	stack_list.pop_front();
}

template <class T>
void stack<T>::push(T item){
	stack_list.push_front(item);
}

template <class T>
bool stack<T>::empty() const{
	if(stack_list.size() == 0)
		return true;
	else
		return false;
}

template <class T>
int stack<T>::size() const{
	return stack_list.size();
}

template <class T>
stack<T> stack<T>::operator=(const stack& rhs){
	return rhs;
}

#endif