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
 * Filename : WordLadder.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include <iostream>
#include <list>
#include <fstream>
#include <cstdlib>

#include "stack.h"
#include "queue.h"
#include "WordLadder.h"

bool WordLadder::one_away(const std::string& stack_word, const std::string& word) const{
		int difference = 0;
	
		for(unsigned i = 0; i < stack_word.size(); i++)
			if(stack_word.at(i) != word.at(i))
				difference++;
		
	
		if(difference == 1) // amount of differences
			return true;
		else
			return false;
}

void WordLadder::print_ladder(stack<std::string> ladder) const{
	// reversing stack & printing the reversed stack
	// outputting stack in order
	stack <std::string> ladder_dupe;
	
	int orig_size = ladder.size();

	while(orig_size > 0){
		ladder_dupe.push(ladder.top());
		ladder.pop();
		orig_size--;
	}
	
	std::cout << ladder_dupe.top();
	ladder_dupe.pop();
	
	orig_size = ladder_dupe.size();

	while(orig_size > 0){
		std::cout << " " << ladder_dupe.top();
		ladder_dupe.pop();
		orig_size--;
	}
}

WordLadder::WordLadder(const std::string &listFile){
	file_name = listFile;	
}

void WordLadder::outputLadder(const std::string &start, const std::string &end){
	std::ifstream in_file;
	in_file.open(file_name.c_str());
	
	if(!in_file.is_open()){
			std::cerr << "couldn't open file.\n";
			exit(0);
	}
	std::list<std::string> word_list;
	std::string word;
	while(in_file >> word)
			word_list.push_back(word);
	in_file.close();

	if(start == end){ // case in which already finished
		std::cout << start << "\n";
		return;
	}

	stack <std::string> ladder; 
	ladder.push(start);

	queue <stack <std::string> > ladder_list;
	ladder_list.enqueue(ladder);

	std::list<std::string>::iterator itr;
	while(!ladder_list.empty()){
		for(itr = word_list.begin(); itr != word_list.end(); itr++){
			if(one_away(ladder_list.front().top(), *itr) && ladder_list.front().top() != *itr){
				if(end == *itr){ // reached end
					ladder_list.front().push(*itr);
					print_ladder(ladder_list.front());
					std::cout << std::endl;
					return; // finished word ladder
				}

				stack <std::string> ladder_dupe = ladder_list.front();
				ladder_dupe.push(*itr);
				ladder_list.enqueue(ladder_dupe);
				itr = word_list.erase(itr); //to stop back tracking, getting rid of used
				itr--;
			}
		}
		ladder_list.dequeue();
	}
	std::cout << "nonexistent wordladder for " << start << " and " << end << ".\n";
}