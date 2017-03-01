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
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include "BST.H"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {
  
  if(argc != 2) {
    cerr << "Usage error: expected <executable> <mode>" << endl;
    exit(1);
  }
  
  string cmd = "";
  int key = -1;
  BST t;
  string mode = argv[1];
  
  
  

  
  for(;;) {
    cin >> cmd;
    if(cmd == "insert") {
      cin >> key;
      t.insert(key);
    }
    else if(cmd == "remove") {
      cin >> key;
      t.remove(key);
    }
    else if(cmd == "dotty") {
      cout << "mode = " << mode << endl; 
      
      
      

      if (mode == "height") t.dotty_height();
      else if(mode == "preorder") t.dotty_preorder();
      else if(mode == "inorder") t.dotty_inorder();
      else if(mode == "postorder") t.dotty_postorder();
      else{
        cout << "cannot find mode, using default mode...\n";
        t.dotty();
      }
      
    }
    else if(cmd == "display") t.display();
    else if(cmd == "end") break;
    else
      cout << cmd << ", not found, try again." << endl;
  }
  
  cout << "Good bye!" << endl;
  return 0;
}
