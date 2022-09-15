#include <iostream>

template<class T>
struct Node {
        T data;
        Node<T>* next;
        Node();
        Node(T);
        Node(T,Node<T>* next);
};

template<class T>
Node<T>::Node() {
    
}

template<class T>
Node<T>::Node(T data) {
    this->data = data;
    next = NULL;
}

template<class T>
Node<T>::Node(T data,Node<T>* next) {
    this->data = data;
    this->next = next;
}