#include <iostream>
using namespace std;

template<class T>
struct NodeH {
    NodeH<T>* next;
    T data;
    int key;
    NodeH();
    NodeH(T,int);
    NodeH(T,int,NodeH<T>*);
};

template<class T>
NodeH<T>::NodeH() {
    key = 0;
    next = NULL;
}

template<class T>
NodeH<T>::NodeH(T data,int key) {
    this->data = data;
    this->key = key;
    next = NULL;
}

template<class T>
NodeH<T>::NodeH(T data,int key,NodeH<T>* next) {
    this->data = data;
    this->key = key;
    this->next = next;
}