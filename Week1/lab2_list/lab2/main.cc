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
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include "list.h"

using namespace std;

int
main ( ) {

  List first_list;
  List second_list;
  
  first_list.push_front(1);
  first_list.push_front(2);
  first_list.push_front(3);
  first_list.push_front(4);
  first_list.push_front(5);

  cout << "The first list is" << endl;
  first_list.print();

  second_list.push_front(10);
  second_list.push_front(9);
  second_list.push_front(8);
  second_list.push_front(7);
  second_list.push_front(6);
  
  cout << "The second list is" << endl;
  second_list.print();

  cout << "Making second equal to the first." << endl;
  second_list = first_list;
  
  cout << "The first list is" << endl;
  first_list.print();
  cout << "The second list is" << endl;
  second_list.print();
  
  cout << "Adding 100 to the front of the first, and " << endl;
  cout << "200 to the front of the second" << endl;
  first_list.push_front(100);
  second_list.push_front(200);
  
  first_list.push_back(3000);
  //second_list.push_back();
  cout << "The first list is" << endl;
  first_list.print();
  cout << "The second list is" << endl;
  second_list.print();

  cout << "Adding 1000 to the end of the first, and " << endl;
  cout << "2000 to the end of the second" << endl;
  first_list.push_back(1000);
  second_list.push_back(2000);  

  cout << "The first list is" << endl;
  first_list.print();
  cout << "The second list is" << endl;
  second_list.print();

  // add file I/O and merge testing here

  return 0;
}
