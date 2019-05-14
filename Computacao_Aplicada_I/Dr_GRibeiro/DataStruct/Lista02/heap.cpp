#include "heap.hpp"
#include <iostream>

Heap::Heap(int cap){
    this->harr = new int[cap];
    this->capacity = cap;
    this->heap_size = 0;
}

void Heap::insert(int k){
    if(heap_size == capacity){  
        std::cout << "\n Array is Overflow!\n";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;
    while ( i != 0 &&harr[parent(i)]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
    
}

int Heap::parent(int i){                     // Parent of actual heap implementation
    return ( i - 1 ) / 2;
}

void Heap::swap( int *x, int *y){            // Function to swap elements
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Heap::leftChild(int i){
    return 2*i + 1;
}

int Heap::rightChild(int i){
    return 2*i + 2;
}

void Heap::maxHeapify(int i){
    // Find Left Child
    int left = leftChild(i);
    
    // Find Right Child
    int right = rightChild(i);

    // Find the largest among 3 nodes
    int largest = i;

    // Check Left node is Larger than Current Node
    if ( left <= heap_size && harr[left] > harr[largest]){
        largest = left;
        std::cout << "Largest: " << largest;
    }

    // Check Right node is Larger than Current Node
    if ( right <= heap_size && harr[right] > harr[largest]){
        largest = right;
    }

    // swao the largest node with current node
    if ( largest != i ){
        int temp = harr[i];
        harr[i] = harr[largest];
        harr[largest] = temp;
        maxHeapify(largest);
    }
}

int Heap::maximum(){
    return harr[0];
}

int Heap::extract_max(){
    int maxItem = harr[0];
    // Replace max with last
    harr[0] = harr[heap_size - 1];
    heap_size = heap_size - 1;

    // Maintain Heap Property
    maxHeapify(0);
    return maxItem;
}

void Heap::printHeap(){
    for (int i = 0; i < heap_size; i++){
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}