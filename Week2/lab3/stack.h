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
 * Filename : stack.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef __STACK_H_
#define __STACK_H_

template<typename T>
class Stack {
private:
  int topp;
  T capacity;
  T *location;

public:
  Stack(int cap);
  void push(const T& x);

  T& top();
  void pop();
  bool is_empty() const;

};

#endif