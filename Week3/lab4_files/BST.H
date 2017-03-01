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
    char id;
    BinaryNode* left;
    BinaryNode* right;
    BinaryNode(int& v) : value(v), id('a'), left(NULL), right(NULL) {}
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
  void display( BinaryNode* t ) {
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
    
    if(t->left){
      out << "\tkey" << t->value << " -> key" << t->left->value << ";\n";
    }

    if(t->right){
      out << "\tkey" << t->value << " -> key" << t->right->value << ";\n";
    }

    if(t->left) dotty(t->left, out);
    if(t->right) dotty(t->right, out);
    
    
  }
  int get_max_depth(){
    cout << "MAX DEPTH IS " << get_max_depth(root);
    return get_max_depth(root);
  }
  int get_max_depth(BinaryNode* t){
    if(t == NULL){
      return 0;
    }
    else{
      int left_depth = get_max_depth(t->left);
      int right_depth = get_max_depth(t->right);

      if(left_depth > right_depth)
        return(left_depth+1);
      else 
        return(right_depth+1);
    }
  }
  void dotty_height_second(BinaryNode* t, ofstream &out){ 
    if(t->right){
      out << "\t" << t->id << " -> " <<  t->right->id << ";\n";
    }
    if(t->left){
      out << "\t" << t->id << " -> " << t->left->id << ";\n";
    }

    if(t->left) dotty_height_second(t->left, out);
    if(t->right) dotty_height_second(t->right, out);
  }

  void dotty_height(){
    ofstream out("output.dot");
      if(!out) {
        cout << "output.dot could not be opened." << endl;
        exit(1);
      }

    out << "digraph G {\n\n";
    dotty_height(root, out); 

    out << "\n\n";
    dotty_height_second(root, out);

    out << "\n}";
    out.close();
  }

  void dotty_height(BinaryNode* t, ofstream &out){
    static char var = 'a';
    static int max_depth = get_max_depth();
    static int current_depth = 0;
    current_depth++;
    int height = max_depth - current_depth;
    out << "\t" << t->id << " [color = lightblue, style = filled, label =\"key=" << t->value << ", h=" << height << "\"];\n";
    
    if(t->left){
      var++;
      t->left->id = var;
      dotty_height(t->left, out);
    }
    
    if(t->right){
      var++;
      t->right->id = var;
      dotty_height(t->right, out);
    }
    
  }

  void dotty_preorder(){
    ofstream out("output.dot");
      if(!out) {
        cout << "output.dot could not be opened." << endl;
        exit(1);
      }

    out << "digraph G {\n\n";
    dotty_preorder(root, out); 

    out << "\n\n";
    dotty_preorder_second(root, out);

    out << "\n}";
    out.close();
  }

  void dotty_preorder(BinaryNode* t, ofstream &out){
    static int pre = 0;
    static char var = 'a';
    pre++;
    out << "\t" << t->id << " [color = orange, peripheries=2, style = filled, label=\"key=" << t->value << ", pre =" << pre << "\"];\n";
  
    if(t->left){
      var++;
      t->left->id = var;
      dotty_preorder(t->left, out);
    }
    if(t->right){
      var++;
      t->right->id = var;
      dotty_preorder(t->right, out);
    }
  }
  void dotty_preorder_second(BinaryNode* t, ofstream &out){ 
   
    if(t->left){
      out << "\t" << t->id << " -> " << t->left->id << " [color=blue];\n";
    }
   if(t->right){
      out << "\t" << t->id << " -> " <<  t->right->id << " [color=blue];\n";
    }
    if(t->left) dotty_preorder_second(t->left, out);
    if(t->right) dotty_preorder_second(t->right, out);
    
    
  }

  void dotty_inorder(){
    ofstream out("output.dot");
      if(!out) {
        cout << "output.dot could not be opened." << endl;
        exit(1);
      }

    out << "digraph G {\n\n";
    dotty_inorder(root, out); 

    out << "\n\n";
    dotty_inorder_second(root, out);

    out << "\n}";
    out.close();
  }
  void dotty_inorder(BinaryNode* t, ofstream &out){
    static char var = 'a';
    static int in = 0;
    
  
    if(t->left){
      var++;
      t->left->id = var;
      dotty_inorder(t->left, out);
    }
    in++;
    out << "\t" << t->id << " [color = red, peripheries=2, style = filled, label=\"key=" << t->value << ", in =" << in << "\"];\n";
    if(t->right){
      var++;
      t->right->id = var;
      dotty_inorder(t->right, out);
    }
  }
  void dotty_inorder_second(BinaryNode* t, ofstream &out){
    if(t->left){
      out << "\t" << t->id << " -> " << t->left->id << ";\n";
    }
   if(t->right){
      out << "\t" << t->id << " -> " <<  t->right->id << ";\n";
    }
    if(t->left) dotty_inorder_second(t->left, out);
    if(t->right) dotty_inorder_second(t->right, out);
    
  }
  void dotty_postorder(){
    ofstream out("output.dot");
      if(!out) {
        cout << "output.dot could not be opened." << endl;
        exit(1);
      }

    out << "digraph G {\n\n";
    dotty_postorder(root, out); 

    out << "\n\n";
    dotty_postorder_second(root, out);

    out << "\n}";
    out.close();
  }
  void dotty_postorder(BinaryNode* t, ofstream &out){
    static char var = 'a';
    static int post = 0;
    if(t->left){
      var++;
      t->left->id = var;
      dotty_postorder(t->left, out);
    }
    if(t->right){
      var++;
      t->right->id = var;
      dotty_postorder(t->right, out);
    }
    post++;
    out << "\t" << t->id << " [color = yellow, peripheries=2, style = filled, label=\"key=" << t->value << ", post =" << post << "\"];\n";
  }
  void dotty_postorder_second(BinaryNode* t, ofstream &out){
    if(t->left){
      out << "\t" << t->id << " -> " << t->left->id << ";\n";
    }
   if(t->right){
      out << "\t" << t->id << " -> " <<  t->right->id << ";\n";
    }
    if(t->left) dotty_postorder_second(t->left, out);
    if(t->right) dotty_postorder_second(t->right, out);
  }
private:
  BinaryNode* root;
};

#endif

