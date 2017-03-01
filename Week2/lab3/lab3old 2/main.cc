/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: lab3
 * Filename : main.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "stack.h"
int main(int argc, char* argv[]){

	if(argc != 2){
		std::cout << "argument is not 2. e.g. <file.out> <WORDFILE>\n";
		exit(-1);
	}
	std::string file = argv[1];

	std::ifstream data(file.c_str());
	if(!data.is_open()){
		std::cerr << "file not found lol\n";
		exit(-1);
	}

	// std::string RPN;
	// std::getline(data,RPN);	//get the full RPN
	// std::cout << RPN << std::endl; //printing the RPN

	Stack stack1(100000);

	int result = 0;
	std::string temp;
	while(data >> temp){
		if(temp == "+"){ // if addition
			int first;
			int second;

			second = stack1.top();
			stack1.pop();

			first = stack1.top();
			stack1.pop();

			result = first + second;
			stack1.push(result);
		}
		else if(temp == "-"){ // if subtract
			int first;
			int second;

			second = stack1.top();
			stack1.pop();

			first = stack1.top();
			stack1.pop();

			result = first - second;
			stack1.push(result);
		}
		else if(temp == "*"){ // if multiply
			int first;
			int second;

			second = stack1.top();
			stack1.pop();

			first = stack1.top();
			stack1.pop();

			result = first * second;
			stack1.push(result);
		}		
		else if(temp == "/"){ // if divide
			int first;
			int second;

			second = stack1.top();
			stack1.pop();

			first = stack1.top();
			stack1.pop();

			result = first / second;
			stack1.push(result);
		}
		else{ // if number
			std::string hold = temp;
			// std::stringstream ss = hold;
			int temp_int = atoi(temp.c_str());
			stack1.push(temp_int);
		}
	}
	std::cout << "THE RESULT IS = " << result << std::endl;

	return 0;
}


// int main(int argc, char* argv[]){

// 	if(argc != 2){
// 		std::cout << "argument is not 2. e.g. <file.out> <WORDFILE>\n";
// 		exit(-1);
// 	}
// 	std::string file = argv[1];

// 	std::ifstream data(file.c_str());
// 	if(!data.is_open()){
// 		std::cerr << "file not found lol\n";
// 		exit(-1);
// 	}

// 	int number;
// 	int size = 1000;
// 	Stack stack1(size);

// 	std::cout << "INITIALIZING A STACK OF SIZE " << size << std::endl;
// 	while(data >> number){

// 		stack1.push(number);
// 		std::cout << "THE TOP OF THE STACK IS " << stack1.top() << std::endl;
// 	}

// 	// }
// 	return 0;
// }