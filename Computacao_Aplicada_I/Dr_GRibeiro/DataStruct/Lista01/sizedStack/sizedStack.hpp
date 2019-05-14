#ifndef __SIZEDSTACK_HPP__
#define __SIZEDSTACK_HPP__

// C++ Standard Library
#include <iostream>

class Stack{

private:
    int* num;
    int top;
    int capacity;

public:
    Stack(int);             //Constructor Padrão
    int push(int);
    int pop();
    int isEmpty();
    int isFull();
    void topo();
    ~Stack();                 //Destrutor
};



#endif // __SIZEDSTACK_HPP__
