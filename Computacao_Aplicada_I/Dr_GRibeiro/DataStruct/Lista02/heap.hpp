#ifndef __HEAP__
#define __HEAP__

/**
 *      CAP-241- Computação Aplicada - Instituto Nacional de Pesquisas Espaciais - INPE
 *      
 * Estruturado de dados elementar - Heap
 * 
 * @based http://ads.dpi.inpe.br/lib/exe/fetch.php?media=wiki:turma2019:estruturas_dados_elementares_parte_04.pdf
 *  
 * @author Helvecio Neto    -     2019
 */

#include <iostream>

template<class T>
class Heap{

    T *harr;           // Ponteiro para o Array utilizado no Heap
    int capacity_;     // Capacidade máxima do Heap
    int last_;         // Ultimo Elemento do Heap

    private:

    const int getParent(int i) const;       // Retorna o valor do nó Pai
    const int leftChild(int i) const;       // Retorna o valor do filho a esquerda
    const int rightChild(int i) const;      // Retorna o valor do filho a direita

    void fixUpHeap() const;                 // Função recursiva para reajustar o Heap por cima
    void fixDownHeap() const;               // Função recursiva para reajustar o Heap por baixo
    void swap(int x, int y) const;          // Função para troca de elementos Pai e Filho

    public:

    Heap(int capacity);                     // Método Construtor
    void insert(T k);                       // Função de inserção de elemento no Heap
    int maximum() const;                    // Retorna o elemento do MaxHeap
    int extract_max();                      // Extrai o valor do MaxHeap
    void printHeap();                       // Função para exibir o Heap em seu estádo atual
    ~Heap();                                // Destructor
};

template<class T>
    Heap<T>::Heap(int cap){
    this->harr = new T[cap];                
    this->capacity_ = cap;
    this->last_ = 0;
}

template<class T>
const int Heap<T>::getParent(int i) const{
    return ( i - 1 ) / 2;
}


template<class T>
const int Heap<T>::leftChild(int i) const{
    return 2*i + 1;
}

template<class T>
const int Heap<T>::rightChild(int i) const{
    return 2*i + 2;
}
template<class T>
void Heap<T>::fixUpHeap() const{
    int child = this->last_ - 1;
    int parent = getParent(child);

    while ( this->harr[child] > this->harr[parent] && child >=0 && parent >=0){
        swap(child, parent);
        child = parent;
        parent = getParent(child);
    }
}

template<class T>
void Heap<T>::fixDownHeap() const{
    int parent = 0;

    while(true) {
        int l = leftChild(parent);
        int r = rightChild(parent);
        int len = this->last_;
        int largest = parent;

        if( l < len && this->harr[l] > this->harr[largest])
            largest = l;
        
        if( r < len && this->harr[r] > this->harr[largest])
            largest = r;

        if( largest != parent){
            swap(largest, parent);
            parent = largest;
        }else{
            break;
        }
    }
}

template<class T>
void Heap<T>::swap( int child, int parent) const{            // Function to swap elements
    int temp = this->harr[child];
    this->harr[child] = this->harr[parent];
    this->harr[parent] = temp;
}

template<class T>
void Heap<T>::insert(T k){
    if(this->last_+1 >= this->capacity_){
        std::cout << "\n Array is Overflow!\n";
        return;
    }
    this->harr[this->last_++] = k;
    this->fixUpHeap();
}

template<class T>
int Heap<T>::maximum() const{
    return harr[0];
}

template<class T>
int Heap<T>::extract_max(){
    int child = this->last_+1;

    this->harr[0] = this->harr[last_];
    int v = this->harr[last_--];

    this->fixDownHeap();
}

template<class T>
void Heap<T>::printHeap(){
    for(int i=0; i < this->last_; ++i){
        std::cout << (i>0 ? "|" : "") << this->harr[i];
    }
}

template<class T>
Heap<T>::~Heap(){
    delete[] this->harr;
}



#endif //__HEAP__