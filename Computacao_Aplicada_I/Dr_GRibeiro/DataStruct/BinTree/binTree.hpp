#ifndef __BINTREE_HPP__
#define __BINTREE_HPP__

// C++ Standard Library
#include<iostream>

class Node{
    private:
        int data;
        Node *left;
        Node *right;

    public:
        Node(int data){             //Constructor
            this->data = data;
            left = NULL;
            right = NULL;
        }

        int getData(){
            return data;
        }

        Node* getLeft(){
            return left;
        }

        Node* getRight(){
            return right;
        }

        void setLeft(Node* node){
            left = node;
        }

        void setRight(Node* node){
            right = node;
        }
};

class Tree{
    private:
        Node* root;
    
    public:
        Tree(){     //TreeConstructors
            root = NULL;
        }

        void insert(int data){
            if(root == NULL)
                root = new Node(data);
            else
                insertAux(root, data);
        }

        void insertAux(Node *node, int data){
            //Se for menor, inserir a esquerda
            if(data < node->getData()){

                //Verificar esquerda esta NULL
                if(node->getLeft() == NULL){
                    Node *new_node = new Node(data);
                    node->setLeft(new_node);            //Set new node in left
                }
                else //Se nao, continua percorrendo recursivamente
                {
                    insertAux(node->getLeft(),data);
                }
                
            }
            //Se for maior, inserir a direita
            else if (data > node->getData())
            {
                //Verificar direita esta NULL
                if(node->getRight() == NULL){
                    Node *new_node = new Node(data);
                    node->setRight(new_node);           //Set new node in right
                }
                else
                {
                    //Se nao, continua recurisivamente
                    insertAux(node->getRight(),data);
                }
                
            }
            // Se for igual nao inserir, nao podem existir elementos iguais
        }

        Node* getRoot(){
            //std::cout << "Root is: " << root;
            return root;
        }

        void inOrder(Node* node){
            if(node == NULL)
            return;
                inOrder(node->getLeft());
                std::cout << node->getData() << " ";
                inOrder(node->getRight());
        }

        void postOrder(Node* node){
            if(node == NULL)
            return;
            //Primeiro elemento subarvore esquerda, recursivamente
            postOrder(node->getLeft());

            // Recursivamente Direita
            postOrder(node->getRight());

            std::cout << node->getData() << " ";
        }

        void preOrder(Node* node){
            if(node == NULL)
            return;
            std::cout << node->getData() << " ";
            preOrder(node->getLeft());
            preOrder(node->getRight());
        }



};

#endif // __BINTREE_HPP__