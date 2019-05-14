#include "heap.hpp"
#include <iostream>

Heap::Heap(int A[], int n){
    std::cout << "Heap Criada" << std::endl;
    for (int i = 1; i <= n; ++i){
        std::cout << A[i] << std::endl;
        FixUpHeap(A, A[i], i);
 
    }
}

void Heap::FixUpHeap(int A[], int v, int pos){
    while((pos > 0) && (A[pos / 2]) < v){
        A[pos] = A[pos / 2];
        pos = pos / 2;
    }
    A[pos] = v;
}

void Heap::ExtraiHeap(int A[], int n){
    for(int i = 1; i <= n; ++i){
        int max = A[1];
        A[1] = A[n - i + 1];
        FixDownHeap(A, n - i, 1);
    }
}

void Heap::FixDownHeap(int A[], int n, int pos){
    int v = A[pos];
    int j = 2 * pos;

    while (j <= n){
        if((j < n) && (A[j] < A[j + 1]))
            ++j;
        if(v > A[j])
            break;

        A[j / 2] = A[j];
        j *= 2;
    }
    A[j / 2] = v;
}

void Heap::Heapify(int A[], int n){
    for(int k = n / 2; k > 0; --k)
        FixDownHeap(A, n, k);
}

/*void Heap::Sort(int A[], int n){
    for(int i = 2; i <= n; ++i)
        FixUpHeap(A, A[i], i);

    for(int i = n; i > 1; --i){
        swap(A[1], A[1]);
        FixDownHeap(A, i - 1, 1);
    }
}*/