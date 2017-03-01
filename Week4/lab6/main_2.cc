/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: Lab 6
 * Filename : main_2.cc
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 
#include "BinaryHeap_2.h"



int main() {
    
    vector<int> v;
    v.push_back(10);
    v.push_back(6);
    v.push_back(8);
    v.push_back(4);
    v.push_back(2);
    v.push_back(12);

    for(unsigned i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
    
    BinaryHeap <int> pq(v);

    pq.print( );

    pq.insert(1);
    pq.print();

    pq.insert(3);
    pq.print();

    pq.insert(5);
    pq.print();

    pq.insert(7);
    pq.print();

    pq.insert(9);
    pq.print();

    pq.insert(0);
    pq.print();
    
    // Add additional tests for new BinaryHeap functionality here
    // Add additional tests for heapsort here. You should use the
    // print function to view the heap at each step of the sort.
    
    return 0;
}