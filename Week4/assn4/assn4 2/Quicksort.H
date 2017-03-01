/**
 * Course: CS 14 Summer 2016
 *
 * First Name: Apollo
 * Last Name: Truong
 * Username: atruo017
 * email address: this must be your cs or UCR student email address
 *
 *
 * Assignment: assn 4
 * Filename : Quicksort.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */

 //random_qselect does not work
 // deterministic_qselect doesnt work either.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

template<class T>
int Partition_0(vector<T> &numbers, int i, int k) { //first, pivots at first position
	int l = 0;
	int h = 0;
	T pivot;
	bool done = false;

	pivot = numbers[i];

	l = i;
	h = k;

	while (!done) {
	  	// incrementing left side
		while (numbers[l] < pivot) {++l;}
	  
	  	// decrementing right side
	  	while (pivot < numbers[h]) {--h;}
	  
	  	// if left and right iterators are at the same spot
	  	if (l >= h) {done = true;}
	  	else {
	    // swap l and h values with each other
	    	swap(numbers[l], numbers[h]);
	   
	    	++l;
	    	--h;
	  	}
	}

	return h;
}

template<class T>
void Quicksort_0(vector<T> &numbers, int i, int k) {
   int j = 0;
   
   // if there is one or 0 elements
   	if (i >= k) {
      return;
   	}
   
   	// cutting the array into 2, j is the last position of the first half
   	j = Partition_0(numbers, i, k);
   
   	// using recursion for left and right hand side of the pivot
   	Quicksort_0(numbers, i, j);
   	Quicksort_0(numbers, j + 1, k);
   
   	return;
}

// refer to the comments on the previous for the rest of the sorts

template<class T>
int Partition_1(vector<T> &numbers, int i, int k) { //random pivot
	int l = 0;
	int h = 0;
	int midpoint = 0;
	T pivot;
	bool done = false;

	midpoint = (rand() % (k-i)) + i; //numbers between i and k
	pivot = numbers[midpoint];

	l = i;
	h = k;

	while (!done) {

	  	while (numbers[l] < pivot) {
			++l;
	  	}
	  
	  	while (pivot < numbers[h]) {
	    	--h;
	  	}

	  	if (l >= h) {
	    	done = true;
	 	}
	  	else {
	    	swap(numbers[l], numbers[h]);
	   
	    	++l;
	    	--h;
	  	}
	}

	return h;
}

template<class T>
void Quicksort_1(vector<T> &numbers, int i, int k) {
	int j = 0;
   
   	if (i >= k) {
    	return;
   	}
   
   	j = Partition_1(numbers, i, k);
   
   	Quicksort_1(numbers, i, j);
   	Quicksort_1(numbers, j + 1, k);
   
   	return;
}

template<class T>
int Partition_2(vector<T> &numbers, int i, int k) { //median_three
   	int l = 0;
   	int h = 0;
   	T pivot;
   	bool done = false;
   
   	// picking median of 3 random numbers
   	int a = (rand() % (k-i)) + i;
   	int b = (rand() % (k-i)) + i;
   	int c = (rand() % (k-i)) + i;
   	int median = max(min(a,b), min(max(a,b),c));
   	pivot = numbers[median];
   
   	l = i;
   	h = k;
   
   	while (!done) {
      
      	while (numbers[l] < pivot) {++l;}
      
      	while (pivot < numbers[h]) {--h;}
      
      	if (l >= h) {done = true;}
      	else {
        	swap(numbers[l], numbers[h]);
       
         	++l;
        	--h;
      	}
   }
   
   return h;
}

template<class T>
void Quicksort_2(vector<T> &numbers, int i, int k) {
   	int j = 0;
    
   	if (i >= k) {return;}
    
   	j = Partition_2(numbers, i, k);
   
   	Quicksort_2(numbers, i, j);
   	Quicksort_2(numbers, j + 1, k);
   
   return;
}




template<class T>
vector<T> quicksort(vector<T> &numbers, string pivot){
	vector<T> final;
	if(pivot == "first")	Quicksort_0(numbers, 0, numbers.size() - 1);
	if(pivot == "random")	Quicksort_1(numbers, 0, numbers.size() - 1);
	if(pivot == "median_three")	Quicksort_2(numbers, 0, numbers.size() - 1);
	if(pivot == "random_qselect")	Quicksort_2(numbers, 0, numbers.size() - 1); //unfinished
	if(pivot == "deterministic_qsort")	Quicksort_2(numbers, 0, numbers.size() -1); // unfinished
	for(unsigned i = 0; i < numbers.size(); i++){
		final.push_back(numbers.at(i));
	}
	return final;
}

