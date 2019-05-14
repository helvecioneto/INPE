#include "doubleLinkedList.hpp"
#include <iostream>


Node::Node(int value){                      //Criacao do no da Lista
    data = value;                           
    next = prev = NULL;                     //Inidicadores da Lista recebem valor NULL
}

DoublyLinkedList::DoublyLinkedList()            //Construtor da Lista
{
    head = tail = NULL;                         //Head e Tail recebem valor NULL
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList()           //Chamada do Dstrutor
{
}

void DoublyLinkedList::push_front(int value)        //Adiciona um Elemento no inicio da Lista
{
    Node* temp = new Node(value);                   //Cria objeto temporario para receber elemento

    if (head == NULL)                               //Verifica se lista esta vazia
        head = tail = temp;
    else{
        head->prev = temp;                          //Aponta Head para Inidicador prev
        temp->next = head;                          //Aponta temp para indicador next
        head = temp;                                //Head recebe objeto temp
    }
    size++;
}

void DoublyLinkedList::push_back(int value)         //Adiciona Elemento no final da Lista, Metodo similar ao push front, porem adiciona ao final
{
    Node* temp = new Node(value);

    if (tail == NULL)
        head = tail = temp;
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    size++;
}

int DoublyLinkedList::pop_front()               //Remove Elemento do começo da Lista
{
    if( !isEmpty())
    {
        Node* temp =head;
        if (head == tail)
        {
            tail = NULL;
        }
        int delValue = temp->data;
        head = head->next;


        delete temp;

        size--;

        return delValue;
    }return 0;
}

int DoublyLinkedList::pop_back()
{
    if (!isEmpty())
    {
        Node* temp = tail;
        if (head == tail)
        {
            head = NULL;
        }
        int delValue = temp->data;
        tail->next = NULL;
        tail = tail->prev;
        delete temp;
        return delValue;
    }return 0;
}

bool DoublyLinkedList::isEmpty()            //Verifica Se lista está vazia
{
    if ( size <= 0)
    {
        return true;
    }
    return false;
}

void DoublyLinkedList::back()           //Retorna elemento do final da lista
{
    if (!isEmpty())
    {
        Node* temp = tail;

        std::cout << "Back is is: " << temp->data << std::endl;
        return;
    }
        std::cout << "Empty!!" << std::endl;
}


void DoublyLinkedList::front()      //Retorna Elemento do começo da Lista
{
    if (!isEmpty())
    {
        Node* temp = head;

        std::cout << "Front is: " << temp->data << std::endl;
        return;
    }
        std::cout << "Empty!!" << std::endl;
}

int DoublyLinkedList::length()
{
    return size;
}
