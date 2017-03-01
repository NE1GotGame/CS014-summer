/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn3
 * Filename : node.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef __NODE_H_
#define __NODE_H_

class Node {
  friend class Tree;
private:
  std::string value;
  int count;
  Node* left;
  Node* right;
};

#endif /* NODE_H_ */

