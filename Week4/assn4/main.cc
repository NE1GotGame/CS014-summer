/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn 4
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
#include <iostream>

#include "Quicksort.H"
#include "Mergesort.H"

using namespace std;

int main() {

	vector<string> v;

	v.push_back("ax");
	v.push_back("bz");
	v.push_back("m");
	v.push_back("b");
	v.push_back("v");
	v.push_back("z");
	v.push_back("x");
	v.push_back("c");
	v.push_back("b");
	v.push_back("g");
	v.push_back("f");
	v.push_back("e");
	v.push_back("d");
	v.push_back("c");
	v.push_back("b");
	v.push_back("a");

	cout << "UNSORTED: ";

	for(unsigned i = 0; i < v.size(); i++){
		cout << v[i] << ' ';
	}
	cout << endl;

	vector<string> a = quicksort(v, "random_qselect");
	// vector<string> a = mergesort(v);

	cout << "SORTED: ";
	for(unsigned i = 0; i < v.size(); i++){
		cout << v[i] << ' ';
	}
	cout << endl;

	return 0;
}
