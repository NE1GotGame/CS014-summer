#include <iostream>
#include <fstream>
#include <cstdlib>
// #include <queue>
#include <vector>

#include "queue.h"
#include "wordladder.h"
#include "stack.h"

WordLadder::WordLadder( const std::string &listFile ){ 

	file_name = listFile;
}

void WordLadder::outputLadder( const std::string &start, const std::string &end ){
	
	std::vector<std::string> words;

	std::ifstream data(file_name); //putting all words in vector
	std::string temp;
	while(data >> temp){
		words.push_back(temp);
	}

	data.close();

	bool start_exists = false; //checking start word
	for(unsigned i = 0; i < words.size(); i++){
		if(start == words.at(i)){
			start_exists = true;
			break;
		}
	}

	bool end_exists = false; //checking end word
	for(unsigned i = 0; i < words.size(); i++){
		if(end == words.at(i)){
			end_exists = true;
			break;
		}
	}	

	if(!start_exists && end_exists){
		std::cout << "an error occurred. the start / end word does not exist\n";
		exit(0);
	}
	
	Stack <std::string> ladder(100);
	ladder.push(start);

	Queue ladder_list;
	ladder_list.enqueue(ladder);

	unsigned i;

	while(!ladder_list.isEmpty()){
		for(i = 0; i != words.size(); i++){
			if(ladder_list.front().top() != words.at(i)
				&& one_difference(ladder_list.front().top(), words.at(i))){
				if(words.at(i) == end){
					ladder_list.front().push(words.at(i));
					// printLadder(ladder_list.front());
					std::cout << std::endl;
					return;
				}
				Stack <std::string> copy = ladder_list.front();
				copy.push(words.at(i));
				ladder_list.enqueue(copy);
				words.erase(words.begin() + i);
				i--;
			}
		}
		ladder_list.dequeue();
	}
	std::cout << "there is no word ladder between " << start << " and " << end << std::endl;

	// Queue <Stack> q;

}

bool WordLadder::one_difference( const std::string& stack_word, const std::string& word){
	int difference = 0;

	if(stack_word.size() != word.size()){
		return false;
	}

	for(unsigned i = 0; i < stack_word.size(); i++){
		if(stack_word.at(i) != word.at(i)){
			difference++;
			if(difference > 1){
				return false;
			}
		}
	}
	if(difference == 1){
		return true;
	}
	else{
		return false;
	}
}

// void printLadder(Stack <std::string> ladder){
// 	Stack <std::string> copy;
// 	if(ladder.size() == 0)
// 		return;

// 	int original_size = ladder.size();

// 	while(original_size >= 1){
// 		copy.push(ladder.top());
// 		ladder.pop();
// 		original_size--;
// 	}

// 	std::cout << copy.top();
// 	copy.pop();
// 	original_size = copy.size();

// 	while(original_size > 0){
// 		std::cout << "\n" << copy.top();
// 		original_size--;
// 	}
	
// }
