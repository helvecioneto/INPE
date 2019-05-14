//My Code
#include "sizedStack.hpp"

//C++ Standard Library
#include <iostream>

using namespace std;

int main(){

    Stack s(4);

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();

    s.topo();

    return 0;
}
