#ifndef __HEAP_H__
#define __HEAP_H__

#include <iostream>

class Heap
{

private:
    int *data_;         // Pointer to array of elements
    std::size_t size_;  // Max possible size of min heap
    std::size_t count_; // Current Number of Elements in min Heap

public:
    //Heap(int A[], int n);
    Heap(int A[], int n);
    void FixUpHeap(int A[], int v, int pos);
    void FixDownHeap(int A[], int v, int pos);
    void ExtraiHeap(int A[], int n);
    void Heapify(int A[], int n);
    void Sort(int A[], int n);

    void swap(int *i, int *j);
};

#endif //__HEAP_H__