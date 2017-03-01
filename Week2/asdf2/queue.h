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
 * Filename : queue.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>
#include <list>

template<typename T>
class queue{
	private: 
		std::list<T> queue_list;
		
	public:
		queue(); //defautl 
		queue(const queue& dupe); //c constructor
		T& front(); // return front (head)
		const T& front() const;
		T& rear(); // return rear
		const T& rear() const;
		void enqueue(T item); //pushback
		void dequeue(); //popfront
		bool empty() const; //is it empty
		int size() const; //check size
};

template<typename T>
queue<T>::queue(){
}

template<typename T>
queue<T>::queue(const queue& dupe){
	queue_list = dupe.queue_list;
}

template<typename T>
T& queue<T>::front(){
	return queue_list.front();
}

template<typename T>
const T& queue<T>::front() const{
	return queue_list.front();
}

template<typename T>
T& queue<T>::rear(){
	return queue_list.back();
}

template<typename T>
const T& queue<T>::rear() const{
	return queue_list.back();
}

template<typename T>
void queue<T>::enqueue(T item) {
	queue_list.push_back(item);
}

template<typename T>
void queue<T>::dequeue(){
	queue_list.pop_front();
}

template<typename T>
bool queue<T>::empty() const{
	if(queue_list.size() == 0)
		return true;
	else
		return false;
}

template<typename T>
int queue<T>::size() const{
	return queue_list.size();
}

#endif