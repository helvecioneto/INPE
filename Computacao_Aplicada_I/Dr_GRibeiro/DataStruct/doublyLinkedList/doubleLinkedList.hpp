#ifndef __DOUBLE_LINKED_LIST__
#define __DOUBLE_LINKED_LIST__


struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int);
};


class DoublyLinkedList{
public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void front();
    void back();
    void push_front(int);
    void push_back(int);
    int pop_front();
    int pop_back();

    bool isEmpty();
    int length();

private:
    Node* head;
    Node* tail;
    int size;
};
#endif //__DOUBLE_LINKED_LIST__
