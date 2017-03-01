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
#include <stdexcept>
#include "stack.h"

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cout << "argument is not 2. e.g. <file.out> <WORDFILE>\n";
		exit(-1);	}
	std::string file = argv[1];
	std::ifstream data(file.c_str());
	if(!data.is_open()){
		std::cerr << "file not found lol\n";
		exit(-1);	}
	try{
		Stack<int> stack1(10);
		std::string temp;
		while(data >> temp){
			if(temp == "+" || temp == "-" || temp == "*" || temp == "/"){ // if addition
				int second = stack1.top();
				stack1.pop();

				int first = stack1.top();
				stack1.pop();

				if(temp == "+"){stack1.push(first + second);}
				if(temp == "-"){stack1.push(first - second);}
				if(temp == "*"){stack1.push(first * second);}
				if(temp == "/"){stack1.push(first / second);}
			} else{ // if number
				int temp_int = atoi(temp.c_str());
				stack1.push(temp_int);	
			}
		}
		std::cout << "THE RESULT IS = " << stack1.top() << std::endl;
	}
	catch(std::underflow_error &e){
		std::cerr << e.what() << std::endl;
	}
	catch(std::overflow_error &e){
		std::cerr << e.what() << std::endl;
	}
	data.close();
	return 0;
}