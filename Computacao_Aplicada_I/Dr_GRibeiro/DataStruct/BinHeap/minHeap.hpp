#ifndef __MIN_HEAP__
#define __MIN_HEAP__

#include <iostream>

class MinHeap{
    int *harr;      // Pointer to array used in heap
    int capacity;   // Max possible size of min heap
    int heap_size;  // Current nodes of min heap

    public:
        
        MinHeap(int capacity);                  // Constructor
        void insertKey(int k);                  // Insert new key k
        void MinHeapify(int);                   // Heapify a subtree with the by root index
        int parent(int i);                      // Parent of actual heap
        int left(int i);                        // To get index of leaft child of actual node at index i 
        int right(int i);                       // To get index of right child of actual node at index i
        int extractMin();                       // To extract the root with min value
        void decreaseKey(int i, int new_val);   // Decrease value of key in index to new_val
        void swap(int *x, int *y);              // Function to swap two integers values
        int getMin();                           // Return min value from min heap in key root
        void deleteKey(int i);                  // Delete a key at index i


};

MinHeap::MinHeap(int cap){                      // Constructor implementation
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void MinHeap::MinHeapify(int i){                // Implementation of methor to heapify subtree with the parent at index value
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if ( l < heap_size && harr[l] < harr[i])
        smallest = 1;
    if ( r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if ( smallest != i){
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

int MinHeap::parent(int i){                     // Parent of actual heap implementation
    return ( i - 1 ) / 2;
}

int MinHeap::left(int i){                       // Return left child
    return ( 2 * i + 1 );
}

int MinHeap::right(int i){                      // Return right child
    return ( 2 * i + 2 );
}

int MinHeap::extractMin(){                      // To extract minimum element or root
    if (heap_size <= 0)
        return __INT_MAX__;
    if (heap_size == 1){
        heap_size--;
        return harr[0];
    }

    int root = harr[0];                         // Store min value at root and remove heap
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::decreaseKey(int i, int new_val){   // Decrease value of key and index to new value
    harr[i] = new_val;
    while ( i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::swap( int *x, int *y){            // Function to swap elements
    int temp = *x;
    *x = *y;
    *y = temp;
}

int MinHeap::getMin(){                          // Function to get min element at array in position [0]
    return harr[0];
}

void MinHeap::deleteKey(int i){                 // Function to delete keys at index i
    decreaseKey(i, __INT_MAX__);
    extractMin();
}

void MinHeap::insertKey(int k){                 // Function to insert new keys
    if (heap_size == capacity){
        std::cout << "\n Array is Overflow!\n";
        return;
    }
    
    heap_size++;                                // Increase heap size
    int i = heap_size - 1;                      
    harr[i] = k;                                // Insert key at array

    while ( i != 0 &&harr[parent(i)]){          // Property of min heap verification
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}


#endif // __MIN_HEAP__
