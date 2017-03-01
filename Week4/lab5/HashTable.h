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
 * Filename : HashTable.h
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
 
#ifndef __HASHTABLE_
#define __HASHTABLE_

#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>
#include <fstream>
#include <cmath>

using namespace std;

class HashTable{

private:
	vector< list<string> > v; //vector of list<string>
	unsigned capacity; // v.size() typically

private: //helper functions
	int hashbrown_1(string word){ 
	//hash function #1
	//make all into ascii value and pushes
		int holder = 0;

		for(unsigned i = 0; i < word.length(); i++){
			char x = word.at(i);
			holder += (int) x;
		}
		return holder;
	}

	int hashbrown_2(string word){
	//hash function #3
	// some math thing
		int holder = word.at(0) + (27 * word.at(1)) + (729 * word.at(2));
		
		return holder;
	}

	int hashbrown_3(string word){
	//hash function #3
	// some math thing
		int holder = 0;
		for(unsigned i = 0; i < word.length(); i++){
			holder += word.at(word.length() - i - 1) * pow(37,i);
		}
		return holder;
	}

	int hashbrown_4(string word){
		int holder = 0;
		for(unsigned i = 0; i < word.length(); i++){
			holder += word.at(word.length() - i - 1);
		}
		return holder;
	}

public:
	HashTable(){}
	HashTable(unsigned i){
		v.resize(i);
		capacity = i;
	}
	
	void print(){
		for(int i = 0; i < v.size(); i++){
			cout << i << ":\t" ;
			for(list<string>::iterator itr = v.at(i).begin(), end = v.at(i).end(); itr != end; itr++){
				cout <<  *itr << ", ";
			}
			cout << "\n";
		}
	}

	void processFile( string filename ){
		ifstream fin(filename.c_str());

		if(!fin.is_open()){
			cerr << "file not found lolz.\n";
			exit(-1);
		}

		/* HASH FUNCTION IMPLEMENTATION
		 * ---------------------------------------
		 */
		string 	word;
		vector< list<string> >::iterator vitr;
		while(fin >> word){
			//change line below 
			// hashbrown_#,		# = 1, 2, 3, 4
			int word_ascii = hashbrown_3(word) % capacity;
			vitr = v.begin() + word_ascii;
			vitr->push_back(word);
		}


	}
	void printStats(){
		int collisions = 0;
		for(int i = 0; i < v.size(); i++){
			for(list<string>::iterator itr = v.at(i).begin(), end = v.at(i).end(); itr != end; itr++){
				if( v.at(i).begin() != itr)
					collisions++;
			}
		}

		cout << "NUMBER OF COLLISIONS = " << collisions << endl;

		int longest_size = 0;
		for(int i = 0; i < v.size(); i++){
			int curr_list = 0;
			for(list<string>::iterator itr = v.at(i).begin(), end = v.at(i).end(); itr != end; itr++){
				curr_list++;
			}
			if(curr_list > longest_size)
				longest_size = curr_list;	
		}
		cout << "LONGEST LIST IS = " << longest_size << endl;
	}

};

#endif