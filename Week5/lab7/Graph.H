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
 * Filename : Graph.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "Vertex.H"

using namespace std;

class Graph{
private:
	vector<Vertex> vertices;


public:
	Graph(){}
	void build_graph(ifstream& ifs){
		int num_nodes;
		ifs >> num_nodes; // get number of nodes line 1

		int num_edges;
		ifs >> num_edges; // get number of nodes line 2

		Vertex empty;
		for(int i = 0; i < num_nodes; i++){ //initialize vetrices with empty vertexes
			vertices.push_back(empty);
		}

		for(int i = 0; i < num_nodes; i++){ // take in all nodes
			string file_label;
			ifs >> file_label;
			int max = numeric_limits<int>::max();
			vertices.at(i).label = file_label;
			vertices.at(i).id = i;
			vertices.at(i).distance = max;
		}

		for(int i = 0; i < num_edges; i++){ //handle edges
			string source;
			string destination;

			ifs >> source;
			ifs >> destination;

			for(int j = 0; j < num_nodes; j++){ // check each node
				if(source == vertices.at(j).label){ // if the name matches with source
					for(int k = 0; k < num_nodes; k++){ // look for the destination
						if(vertices.at(k).label == destination){ // search nodes for destination
							vertices.at(j).neighbors.push_back((vertices.at(k).id)); // if matches, take id and push back that destination to the vertex
						}
					}
				}
			}
		}


		return;
	}
	void output_graph(ofstream &ofs){
		ofs << "digraph {\n";
		
		for(unsigned i = 0; i < vertices.size(); i++){//forevery vertex
			ofs << "\t" << i << " [label=\"" << vertices.at(i).label << ", distance = " << vertices.at(i).distance << "\"" << "];" << endl;
		}
		ofs << endl;

		for(unsigned i = 0; i < vertices.size(); i++){
			
			for(unsigned j = 0; j < vertices.at(i).neighbors.size(); j++){
				ofs << i << " -> " << vertices.at(i).neighbors.at(j) << endl;
			}
		}

		ofs << "\n}";
		return;
	}
	void bfs();

	void output_vertices(){
		for(unsigned i = 0; i < vertices.size(); i++){
			cout	<< "label: " << vertices[i].label << endl
					<< "distance: " << vertices[i].distance << endl
					<< "id: " << vertices[i].id << endl;
			for(unsigned j = 0; j < vertices.at(i).neighbors.size(); j++){
				cout << "neighbors: " << vertices.at(i).neighbors[j] << endl;
			}
			cout << endl;
		}
	}
	

};
#endif