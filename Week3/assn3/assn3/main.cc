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
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include "tree.h"

using namespace std;

void printOrders( Tree *tree ) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << "Inorder = ";
  tree->inOrder( );
  cout << "Postorder = ";
  tree->postOrder( );
}

int main( ) {

  Tree tree;

  cout << "Test 1: Testing simple insert" << endl;
  tree.insert( "hoppy" );
  tree.insert( "gadget" );
  printOrders( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 2: Search testing" << endl;
  if ( tree.search( "hoppy" ) )
    cout << "Passed" << endl;
  else
    cout << "Failed" << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 3: Smallest value in the tree is..." << endl;
  cout << tree.smallest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 4: Largest value in the tree is..." << endl;
  cout << tree.largest( ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 5: Testing subtree heights" << endl;
  cout << "Height of subtree rooted at \"hoppy\" = " 
       << tree.height( "hoppy" ) << endl;
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "Test 6: Remove testing" << endl;
  cout << "Removing \"hoppy\"" << endl;
  tree.remove( "hoppy" );
  printOrders( &tree );
  cout << "----------------------------------------------------------------" 
       << endl;
  cout << "THE HEIGHT OF 1 IS " << tree.height("1") << endl;

  return 1;
}