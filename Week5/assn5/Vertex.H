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
 * Filename : Vertex.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef _VERTEX_H_
#define _VERTEX_H_

#include <vector>

using namespace std;

class Vertex{
	friend class Graph;
private:
	string label;
	int distance;
	int id;
	vector<int> neighbors;
	bool visited;
};

#endif // _VERTEX_H_