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
 * Filename : WordLadder.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef __WORDLADDER_H__
#define __WORDLADDER_H__

#include <iostream>
#include <list>

#include "stack.h"
#include "queue.h"

class WordLadder{
	private:
		std::string file_name;
		bool one_away(const std::string& stack_word, const std::string& word) const;
		void print_ladder(stack<std::string> ladder) const;
	public:
		WordLadder(const std::string &listFile);
		void outputLadder(const std::string &start, const std::string &end);
};
#endif