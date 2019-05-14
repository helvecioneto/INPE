#include <iostream>
#include "heap.hpp"

using namespace std;

int main(){
    Heap t(12);

    t.insert(2);
    t.insert(1);
    t.insert(8);
    t.insert(11);
    t.insert(7);
    t.insert(5);
    t.insert(3);
    t.insert(9);
    t.insert(4);

    t.extract_max();
    t.maximum();

    t.printHeap();
}