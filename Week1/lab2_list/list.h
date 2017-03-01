/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: lab2
 * Filename : list.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#ifndef __LIST_H_
#define __LIST_H_

#include "node.h"

class List {
private:
  Node* head;

public:
  List ( );
  ~List ( );
  int size ( );
  void push_front ( int );
  void push_back ( int );
  void print ( );
  // Add new member function declarations here
  List(const List& x);
  List operator=(const List& x);
};

#endif

