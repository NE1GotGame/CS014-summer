/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: Lab 5
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include <iostream>

#include "HashTable.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cout << "argument is not 2. e.g. <file.out> <WORDFILE>\n";
		exit(-1);
	}
	// used to set the capacity of HashTable
	int size = 313;
	// ----------------
	string file = argv[1];

	HashTable table(size);
	table.processFile(file);
	table.print();
	table.printStats();
	return 0;
}