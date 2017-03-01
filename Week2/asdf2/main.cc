/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn2
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 #include <iostream>

#include "stack.h"
#include "queue.h"
#include "WordLadder.h"

int main(int argc, char* argv[]){
	if(argc != 4){ // error wrong amt arguments
		std::cerr << "\nincorrect arguments,<a.out> <words5.dict> <start_word> <end word>\n";		
		return 0;
	}
	std::string input_dic = argv[1]; //first argument
	WordLadder ladder(input_dic); //constructing word ladder

	std::string starting_word = argv[2]; //second argument
	std::string ending_word = argv[3]; //third argument
	ladder.outputLadder(starting_word, ending_word);
	return 0;
}