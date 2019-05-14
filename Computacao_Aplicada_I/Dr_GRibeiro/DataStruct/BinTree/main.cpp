#include <iostream>
#include "binTree.hpp"

using namespace std;

int main()
{
    Tree t;

    //Insert Keys
    t.insert(10);
    t.insert(3);
    t.insert(12);
    t.insert(11);
    t.insert(9);
    t.insert(7);


    cout << "In Order: \n";
    t.inOrder(t.getRoot());

    cout << "\nPre Order: \n";
    t.preOrder(t.getRoot());

    cout << "\nPost Order: \n";
    t.postOrder(t.getRoot());
    
    return 0;
}
