#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "stack.h"
#include "wordladder.h"

using namespace std;

int main(int argc, char* argv[]){
	if(argc != 4){
		cout << "argument is not 4. e.g. <file.out> <words5.dict> <START_WORD> <END_WORD>\n";
		exit(-1);	}


	const string file = argv[1];
	const string start = argv[2];
	const string end = argv[3];
	

	WordLadder word(file.c_str());

	word.outputLadder(start.c_str(), end.c_str());


	
	



	// data.close();
	return 0;
}