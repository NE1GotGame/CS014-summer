/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: lab7
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
#include <limits>

#include "Graph.H"


using namespace std;

int main(int argc, char* argv[]){
	if(argc != 2){
		cout << "argument is not 2. e.g. <file.out> <input>\n";
		exit(-1);	}


	string file = argv[1];

	ifstream hello(file.c_str());

	Graph graph;
	graph.build_graph(hello);

	string output = "output.dot";
	ofstream ofs(output.c_str());

	// graph.output_vertices();
	// graph.output_graph(ofs);
	// data.close();
	return 0;
}