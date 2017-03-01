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
 * Filename : Mergesort.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */
#include <iostream>

using namespace std;

template<class T>
void merge(vector<T> &v, int i, int j, int k) {
   int merged_size = k - i + 1;                // size of merged partition
   int merged_position = 0;                          // position to insert merged
   int left = 0;                           // right position
   int right = 0;                          // left position
   T* merge_num = new T[merged_size];  // Dynamically allocates temporary array
   
   left = i;                               // left position start
   right = j + 1;                          // right position start
   
   // Add smallest element from left or right partition to merged v
   while(left <= j && right <= k){
      if(v[left] < v[right]){
         merge_num[merged_position] = v[left];
         ++left;
      }
      else {
         merge_num[merged_position] = v[right];
         ++right;
         
      }
      ++merged_position;
   }
   
   // If left partition is not empty, add remaining elements to merged v
   while (left <= j) {
      merge_num[merged_position] = v[left];
      ++left;
      ++merged_position;
   }
   
   // If right partition is not empty, add remaining elements to merged v
   while (right <= k) {
      merge_num[merged_position] = v[right];
      ++right;
      ++merged_position;
   }
   
   // Copy merge number back to v
   for (merged_position = 0; merged_position < merged_size; ++merged_position) {
      v[i + merged_position] = merge_num[merged_position];
   }
}

template<class T>
void merge_call(vector<T> &v, int i, int k) {
   int j = 0;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      merge_call(v, i, j);
      merge_call(v, j + 1, k);
      
      // Merge left and right partition in sorted order
      merge(v, i, j, k);
   }
}

template<class T>
vector<T> mergesort(vector<T> &v){
   merge_call(v, 0, v.size() - 1 );

   vector<T> b;
   for(unsigned i = 0; i < v.size(); i++){
      b.push_back(v[i]);
   }
   return b;
}