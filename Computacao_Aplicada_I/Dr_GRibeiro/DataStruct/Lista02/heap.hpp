#ifndef __HEAP__
#define __HEAP__

#include <iostream>

template<class T>
class Heap{

    T *harr;      // Pointer to array used in heap
    int capacity_;   // Max possible size of min heap
    int last_;  // Current nodes of min heap

    private:

    const int getParent(int i) const;                      // Parent of actual heap
    const int leftChild(int i) const;
    const int rightChild(int i) const;

    void fixUpHeap() const;                 // Moves i of ar
    void fixDownHeap() const;                 // Moves i of ar
    void swap(int x, int y) const;              // Function to swap two integers valu

    public:

    Heap(int capacity);
    void insert(T k);
    int maximum() const;
    int extract_max();
    void printHeap();
    ~Heap();                // Destructor
};

template<class T>
    Heap<T>::Heap(int cap){
    this->harr = new T[cap];
    this->capacity_ = cap;
    this->last_ = 0;
}

template<class T>
const int Heap<T>::getParent(int i) const{                     // Parent of actual heap implementation
    return ( i - 1 ) / 2;
}


template<class T>
const int Heap<T>::leftChild(int i) const{
    return 2*i + 1;
}

template<class T>
const int Heap<T>::rightChild(int i) const{
    return 2*i + 2;
}
template<class T>
void Heap<T>::fixUpHeap() const{
    int child = this->last_ - 1;
    int parent = getParent(child);

    while ( this->harr[child] > this->harr[parent] && child >=0 && parent >=0){
        swap(child, parent);
        child = parent;
        parent = getParent(child);
    }
}

template<class T>
void Heap<T>::fixDownHeap() const{
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

template<class T>
void Heap<T>::swap( int child, int parent) const{            // Function to swap elements
    int temp = this->harr[child];
    this->harr[child] = this->harr[parent];
    this->harr[parent] = temp;
}

template<class T>
void Heap<T>::insert(T k){
    if(this->last_+1 >= this->capacity_){
        std::cout << "\n Array is Overflow!\n";
        return;
    }
    this->harr[this->last_++] = k;
    this->fixUpHeap();
}

template<class T>
int Heap<T>::maximum() const{
    return harr[0];
}

template<class T>
int Heap<T>::extract_max(){
    int child = this->last_+1;

    this->harr[0] = this->harr[last_];
    int v = this->harr[last_--];

    this->fixDownHeap();
}

template<class T>
void Heap<T>::printHeap(){
    for(int i=0; i < this->last_; ++i){
        std::cout << (i>0 ? "|" : "") << this->harr[i];
    }
}

template<class T>
Heap<T>::~Heap(){
    delete[] this->harr;
}



#endif //__HEAP__