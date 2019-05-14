#ifndef __HEAP__
#define __HEAP__

#include <iostream>

class Heap{

    private:

    int *harr;      // Pointer to array used in heap
    int capacity;   // Max possible size of min heap
    int heap_size;  // Current nodes of min heap

    public:

    Heap(int capacity);
    void insert(int k);
    int parent(int i);                      // Parent of actual heap
    void swap(int *x, int *y);              // Function to swap two integers values
    int leftChild(int i);
    int rightChild(int i);
    void maxHeapify(int i);                 // Moves i of array
    int maximum();
    int extract_max();
    void printHeap();
};




#endif //__HEAP__