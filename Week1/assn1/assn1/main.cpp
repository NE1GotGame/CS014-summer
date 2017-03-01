/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn1
 * Filename : main.cpp
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include <iostream>
#include <cstdlib>
#include <cassert>
#include "MyList.h"
#include "node.h"

using namespace std;

int main(){
	cout << "LET THE TESTING BEGIN!\n=============================\n";

	string stringo = "HELLO";
	cout << "Constructing MyList from a variable...";
	
	MyList list1(stringo);
	cout << "Printing list1...\n";
	list1.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	cout << "Constructing from a literal...\n";
	MyList list2("LITERALLY");
	list2.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	cout << "Constructing from another MyList... (using previous list...)\n";
	MyList list3(list2);
	list3.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	cout << "Testing push_front('a') on an empty list\n";
	MyList list4;
	list4.push_front('a');
	list4.print();
	cout << endl;
	cout << "Testing push_front('z') on the same list\n";
	list4.push_front('z');
	list4.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

	cout << "Testing push_back('g') on the previous list...\n";
	list4.push_back('g');
	list4.print();
	cout << endl;
	cout << "Testing push_back('x') on an empty list...\n";
	MyList list5;
	list5.push_back('x');
	list5.print();

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Constructing list abcdefgh\n";
	MyList list6("abcdefgh");
	list6.print();
	cout << "pop_front() is called...\n";
	list6.pop_front();
	list6.print();
	cout << "pop_back() is called...\n";
	list6.pop_back();
	list6.print();
	cout << "Calling swap(1,2)\n";
	list6.swap(1,2);
	list6.print();
	cout << "Calling swap(-100,3) to check bounds...\n";
	cout << "Since -100 is less than 0, setting first parameter to 0\n";
	list6.swap(-100,3);
	list6.print();
	cout << "Calling swap(0,1000) to check bounds...\n";
	cout << "Since 1000 is more than the upper bound, setting to last index\n";
	list6.swap(0,1000);
	list6.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "inserting S at index 1\n";
	char S = 'S';
	cout << "Calling insert_at_pos(1,'S')\n";
	list6.insert_at_pos(1,'S');
	list6.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Calling insert_at_pos(0,'a') on an empty list...\n";
	MyList list7;
	list7.insert_at_pos(0,'a');
	list7.print();
	cout << "Calling insert_at_pos(-1000,'x')\n";
	list7.insert_at_pos(-1000,'x');
	list7.print();
	cout << "Calling insert_at_pos(1000,'y')\n";
	list7.insert_at_pos(1000,'y');
	list7.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Calling insert_at_pos(1,'g')\n";
	list7.insert_at_pos(1,'g');
	list7.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Constructing a list of characters 1 2 3 4 5\n";
	MyList list8("12345");
	list8.print();
	cout << "REVERSING THE LIST NOW!\n";
	list8.reverse();
	list8.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "The size of the list is ... using size()...\n";
	cout << list8.size() << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Calling find('3')" << "\n";
	cout << "It's at node index: " << list8.find('3') << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "Constructing a list a,b,c ..." << endl;
	MyList list9("abc");
	cout << "Constructing a list abasdfasdfabc\n";
	MyList list10("abasdfasdfabc");
	cout << "Calling list10.find(list9)\n";
	cout << "list9 = a, b, c\n";
	cout << "list10 = abasdfasdfabc\n";
	cout << "found list9 at index: " << list10.find(list9) << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "new list...\n";
	MyList list11("zxcv");
	list11.print();
	cout << "Trying to find abc in zxcv...\n";
	cout << "Position returned is: " << list11.find(list9);
	cout << "\nbecause the location doesnt exist... :(\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	MyList list14("abcabc");
	cout << "Testing out the assignment operator...\n";
	MyList list12("abc");
	cout << "first list will be\n";
	list12.print();
	cout << "the next list is empty.\n";
	MyList list13("abc");
	cout << "testing list13 = list12\n";
	cout << "list 13 is now...";
	list13.print();
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "now will try the overloaded + operator\n";
	cout << "list14 = list12 + list13\n";
	list14.print();
	

	cout << "\nDESTRUCTOR WORKING...\n\n";
	return 0;
}