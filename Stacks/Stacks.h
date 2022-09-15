#ifndef Stacks_h
#define Stacks_h

#include <iostream>
#include "Node_S.h"
using namespace std;

template<class T>
class Stacks {
    private:
        Node<T>* top;
        int size;
    public:
        Stacks();
        Node<T>* getTop();
        int getSize();
        void push(T);
        T pop();
        void clear();
        void print();
};

template<class T>
Stacks<T>::Stacks() {
    top = NULL;
    size = 0;
}

template<class T>
Node<T>* Stacks<T>::getTop() {
    if(size != 0) {
        return top;
    }
    else {
        throw out_of_range("Out_of_range \nStack is empty \n");
    }
}

template<class T>
int Stacks<T>::getSize() {
    return size;
}

template<class T>
void Stacks<T>::push(T data) {
    top = new Node<T>(data,top);
    size++;
}

template<class T>
T Stacks<T>::pop() {
    if(size != 0) {
        T data = top->data;
        Node<T>* previous = top;
        top = top->next;
        delete previous;
        size--;
        return data;
    }
    else {
        throw out_of_range("Out_of_range \nStack is empty \n");
    }
}

template<class T>
void Stacks<T>::clear() {
    delete top;
    top = NULL;
    size = 0;
}

template<class T>
void Stacks<T>::print() {
    Node<T>* aux = top;
    int counter = 1;
    while(aux != NULL) {
        cout << counter++ << ".- [" << aux->data << "] \n";
        aux = aux->next;
    }
    cout << endl;
}

#endif