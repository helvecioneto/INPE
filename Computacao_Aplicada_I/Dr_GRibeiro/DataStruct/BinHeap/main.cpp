#include <iostream>
#include "minHeap.hpp"

using namespace std;

int main(){
    MinHeap h(12);

    h.insertKey(2);
    h.insertKey(4);
    h.insertKey(3);
    h.insertKey(7);
    h.insertKey()

    cout << h.extractMin() << endl;
    cout << h.getMin() << endl;
}