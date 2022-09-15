#include "Node_BST.h"
using namespace std;

template<class T>
struct Queue_BST {
    Node<T>* head;
    Node<T>* tail;
    int size;
    Queue_BST();
    void enqueue(Node<T>*);
    Node<T>* dequeue();
};

template<class T>
Queue_BST<T>::Queue_BST() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
void Queue_BST<T>::enqueue(Node<T>* element) {
    if(size != 0) {
        tail->right = element; 
        tail = tail->right;
    }
    else {
        head = element;
        tail = head;
    }
    size++;
}

template<class T>
Node<T>* Queue_BST<T>::dequeue() {
    Node<T>* erased_element = head;
    head = head->right;
    size--;
    return erased_element;
}