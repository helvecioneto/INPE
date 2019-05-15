#include <iostream>
#include "heap.hpp"

using namespace std;

int main(){
    Heap<int> t(12);

    t.insert(3);
    t.insert(2);
    t.insert(4);
    t.insert(1);

    cout << "Heap is: ";
    t.printHeap();
    cout << "Heap is: \n";
    t.printHeap();
    t.extract_max();
    cout << "\nMax is: [" << t.maximum()  << "]" << endl;
}