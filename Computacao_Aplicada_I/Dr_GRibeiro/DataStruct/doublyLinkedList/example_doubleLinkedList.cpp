#include <iostream>
#include "doubleLinkedList.hpp"

using namespace std;

int main(){

    DoublyLinkedList d1 = DoublyLinkedList();

    d1.push_front(2);
    d1.push_front(9);

    d1.push_back(100);
    d1.push_back(101);

    d1.pop_front();
    d1.pop_back();

    d1.front();
    d1.back();

    return 0;
}
