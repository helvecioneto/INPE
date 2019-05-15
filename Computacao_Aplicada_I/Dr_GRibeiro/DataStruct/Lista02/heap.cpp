#include "heap.hpp"
#include <iostream>

Heap::Heap(int cap){
    this->harr = new int[cap];
    this->capacity_ = cap;
    this->last_ = 0;
}

//OK    =  i = child
const int Heap::getParent(int i) const{                     // Parent of actual heap implementation
    return ( i - 1 ) / 2;
}

//OK
const int Heap::leftChild(int i) const{
    return 2*i + 1;
}

//OK
const int Heap::rightChild(int i) const{
    return 2*i + 2;
}

void Heap::fixUpHeap() const{
    int child = this->last_ - 1;
    int parent = getParent(child);

    while ( this->harr[child] > this->harr[parent] && child >=0 && parent >=0){
        swap(child, parent);
        child = parent;
        parent = getParent(child);
    }
}

void Heap::fixDownHeap() const{
    int parent = 0;

    while(true) {
        int l = leftChild(parent);
        int r = rightChild(parent);
        int len = this->last_;
        int largest = parent;

        if( l < len && this->harr[l] > this->harr[largest])
            largest = l;
        
        if( r < len && this->harr[r] > this->harr[largest])
            largest = r;

        if( largest != parent){
            swap(largest, parent);
            parent = largest;
        }else{
            break;
        }
    }
}


//OK
void Heap::swap( int child, int parent) const{            // Function to swap elements
    int temp = this->harr[child];
    this->harr[child] = this->harr[parent];
    this->harr[parent] = temp;
}

//OK
void Heap::insert(int k){
    if(this->last_+1 >= this->capacity_){
        std::cout << "\n Array is Overflow!\n";
        return;
    }

    this->harr[this->last_++] = k;
    this->fixUpHeap();
}

//OK
int Heap::maximum() const{
    return harr[0];
}

//OK
int Heap::extract_max(){
    int child = this->last_+1;
    swap(this->harr[child], this->harr[0]);

    int v = this->harr[last_--];

    this->fixDownHeap();
}

void Heap::printHeap(){
    for(int i=0; i < this->last_; ++i){
        std::cout << (i>0 ? "|" : "") << this->harr[i];
    }
}

Heap::~Heap(){
    delete[] this->harr;
}
