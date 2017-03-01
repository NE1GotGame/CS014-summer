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
 * Filename : BinaryHeap.H
 *
 * I hereby certify that the contents of this file represent
 * my own original individual work. Nowhere herein is there 
 * code from any outside resources such as another individual,
 * a website, or publishings unless specifically designated as
 * permissible by the instructor or TA.
 */ 

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cstdlib>

using namespace std;

template<class T>
class BinaryHeap
{
public:
    BinaryHeap( int capacity = 100 );
    BinaryHeap( const vector<T> & items )
    :  currentSize( items.size( ) ), array( items.size( ) + 10 ) {
        for( unsigned int i = 0; i < items.size( ); i++ )
            array[ i + 1 ] = items[ i ];
        buildHeap( );
        buildHeap();
    }
    
    bool isEmpty( ) const{         // returns 1 if empty FINISHED
        return(currentSize);
    }
    const int & findMin( ) const{  // Implement findMin here
        return array[0];
    }
    void insert( const T & x ){  // Implement insert here
        T temp = x;
        insert(temp);
    }
    
    /**
     * Prints the elements of the underlying array in the BinaryHeap
     */
    void print( ) const {
        for( int i = 1; i < currentSize + 1; i++ )
            cout << array[i] << " ";
        cout << endl;
    }
    
    /**
     * Remove the minimum item and place it in minItem.
     * Exits the program if empty.
     */
    void deleteMin( ) {
        
        if( isEmpty( ) ) {
            // throw UnderflowException( );
            cerr << "Heap is empty" << endl;
            exit(1);
        }
        array[ 1 ] = array[ currentSize-- ];
        percolateDown( 1 );
    }
    void makeEmpty( ){
        currentSize = 0;
    }

    void heapsort(BinaryHeap pq){
        int MAX_SIZE = currentSize;
        while(MAX_SIZE > 0){
            swap(array[1], array[MAX_SIZE]);
            MAX_SIZE--;
            for( int i = MAX_SIZE / 2; i > 0; i-- )
                percolateDown( i );    
        }
        
    }
    
private:
    int currentSize;   // Number of elements in heap
    vector<T> array; // The heap array
    
    void insert( T& newItem ){
        currentSize++;
        array[currentSize] = newItem;
        buildHeap();
    }
    void buildHeap( ) {
        for( int i = currentSize / 2; i > 0; i-- )
            percolateDown( i );
        for( int i = currentSize / 2; i > 0; i-- )
            percolateDown( i );
    }
    
    /**
     * Internal method to percolate down in the heap.
     * hole is the index at which the percolate begins.
     */
    void percolateDown( int hole ) {
        bool left_b = false;
        bool right_b = false;

        
        if (currentSize >= hole * 2){ //left child
    
            left_b = true;
        }
        else { return; } // no children

        if( currentSize >= (hole * 2) + 1){ //right child check
            right_b = true;
        }

        if(left_b && right_b){ // if theres a left and right child
            if(array[hole*2] < array[(hole*2) + 1]){ // if left is less than right
                if(array[hole*2] < array[hole]){ // AND left is less than parent
                    swap(array[hole], array[hole * 2]); //swap
                }
            }
            else{ // if right is less than left
                if(array[(hole*2) + 1] < array[hole]){ //if right is less than hole
                    swap(array[hole], array[(hole * 2) + 1]); //swap
                }
            }
        }

        else if(left_b){ // if there is only left
            if(array[hole*2] < array[hole]){
                swap(array[hole], array[hole*2]);
            }
        }
    }
};