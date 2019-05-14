// My Code
#include "sizedStack.hpp"

// C++ Standard Library
#include <iostream>

Stack::Stack(int size=4){   //Default Size of Stack     //Construtor
    top=-1;                 //Inicia o topo da Pilha com -1
    num = new int[size];    //Cria o Nó da pilha
}

int Stack::isEmpty(){       //Função que verifica se a pilha está vazia
    if(top == -1)           //Se o topo da pilha estiver vazio retorna TRUE
        return 1;
    else                    //Se não, retorne FALSE
        return 0;
}

int Stack::isFull(){        //Função para verificar se a pilha está cheia
    if(top==(capacity-1))   //Verifica a capacidade da pilha
        return 1;
    else
        return 0;
}

int Stack::push(int n){     //Método para inserir um elemnento na pilha
                            //Verifica se a pilha estiver cheia
    if(isFull()){           
        capacity *= 2;      //Tratamento na memória da pilha que dobra a capacidade inicial caso pilha cheia
        int* temp;
        temp = new int[capacity];       //Cria objeto temporário com nova capacidade
        temp = num;                     //Objeto temporário recebe pilha cheia
        delete[] num;                   //pilha cheia destruido
        num = new int[capacity];        //pilha original recebe nova capacidade
        num = temp;                     //Pilha original recebe temporária
        delete[] temp;                  //pilha temporaria destruida
    }
    ++top;                  //Encrementa topo da pilha fora do laço
    num[top]=n;             //Adiciona elemento no topo da pilha
    return n;         
}

int Stack::pop(){           //Função para remover objeto do topo
    int temp;               //Variavel temporária para receber objeto
                            //check for empty
    if(isEmpty())
        return 0;
    temp = num[top];        //Recebe pilha original
    --top;                  //Remove Elemento do Topo
    return temp;
}

void Stack::topo()             //Função que retorna o Topo da Pilha
{
    int temp;
    if(!isEmpty()){             //Verifica se pilha não está vázia
        temp = num[top];
        std::cout << " Top of the Stack: "<< temp;
        return;
    }else{
        std::cout << "Empty Stack" << std::endl;
    }

}

Stack::~Stack(){            //Destrutor
    delete[] num;
}
