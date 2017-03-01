/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: lab4
 * Filename : BST.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#ifndef BST_H_
#define BST_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

class BST {

private:
  struct BinaryNode {

    int value;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(int& v) : value(v), left(NULL), right(NULL) {}
    static BinaryNode* insert(int v, BinaryNode* t) {
      if(t == NULL){
	t = new BinaryNode(v);
      }
      else if (v < t->value)
	t->left = insert(v, t->left);
      else if (v > t->value)
	t->right = insert(v, t->right);
      else
	t->value = v;
      return t;
    }
    
    static BinaryNode* remove(int v, BinaryNode* t) {
      if(t) {
	if(v < t->value)
	  t->left = remove(v, t->left);
	else if(t->value < v)
	  t->right = remove(v, t->right);
	else if(t->left != NULL && t->right != NULL) {
	  t->value = find_min(t->right)->value;
	  t->right = remove(t->value, t->right);
	}
	else {
	  BinaryNode* oldNode = t;
	  t = (t->left != NULL) ? t->left
	    : t->right;
	  delete oldNode;
	}
      }
      return t;
    }
    
    static BinaryNode* find_min(BinaryNode* t) {
      if(t == NULL)
	return NULL;
      if(t->left == NULL)
	return t;
      return find_min(t->left);
    }
  };

public:
  BST(): root(NULL) {}
  ~BST() {}
  void insert(int v) { root = BinaryNode::insert(v, root); }
  void remove(int v) { root = BinaryNode::remove(v, root); }
  void display() { display(root); }
  void dotty() { 
    ofstream out("output.dot");
      if(!out) {
        cout << "output.dot could not be opened." << endl;
        exit(1);
      }

    out << "digraph G {\n\n";
    dotty(root, out); 
    out << "\n}";
    out.close();
  }
  
  
  void dotty(BinaryNode* t, ofstream &out){ 
    
    if(t->right){
      out << "\tkey" << t->value << " -> key" << t->right->value << ";\n";
    }
    if(t->left){
      out << "\tkey" << t->value << " -> key" << t->left->value << ";\n";
    }

    if(t->left) dotty(t->left, out);
    if(t->right) dotty(t->right, out);
    
    
  }
  void display( BinaryNode* t ) {
    // in-order traversal with indented display.
    static int depth = 0;
    ++ depth;
    if ( t == NULL ) return;
    if ( t->right != NULL ) display(t->right);
    for( int i = 0; i != depth; ++i )
      cout << " ";
    cout << t->value << " " << endl;
    if ( t->left != NULL )
      display(t->left);
    --depth;
  }

private:
  BinaryNode* root;
};

#endif /* BST_H_ */

