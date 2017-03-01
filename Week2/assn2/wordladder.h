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
 * Filename : stack.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef __WORDLADDER_H_
#define __WORDLADDER_H_

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>

class WordLadder {
private:

  std::string file_name;

public:
  WordLadder( const std::string &listFile);
  std::string get_file_name();
  void outputLadder( const std::string &start, const std::string &end );
  bool one_difference( const std::string& stack_word,const std::string& word);
  // void printLadder(Stack <std::string> ladder);
};

#endif