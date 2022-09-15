#include "Node_Q.h"
#include <iostream>
using namespace std;

template<class T>
class Queue {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size = 0;
    public:
        Queue();
        Node<T>* front();
        Node<T>* back();
        int getSize();
        void enqueue(T);
        T dequeue();
        void clear();
        void print();
};

template<class T>
Queue<T>::Queue() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
Node<T>* Queue<T>::front() {
    if(size != 0) {
        return head;
    }
    else {
        throw out_of_range("\nOut_of_range \nQueue is empty \n");
    }
}

template<class T>
Node<T>* Queue<T>::back() {
    if(size != 0) {
        return tail;
    }
    else {
        throw out_of_range("\nOut_of_range \nQueue is empty \n");
    }
}

template<class T>
int Queue<T>::getSize() {
    return size;
}

template<class T>
void Queue<T>::enqueue(T data) {
    if(size != 0) {
        tail->next = new Node<T>(data);
        tail = tail->next;
    }
    else {
        head = new Node<T>(data);
        tail = head;
    }
    size++;
}

template<class T>
T Queue<T>::dequeue() {
    if(size != 0) {
        T data = head->data;
        Node<T>* previous = head;
        head = head->next;
        delete previous;
        if(size == 1) {
            tail = NULL;
        }
        size--;
        return data;
    }
    else {
        throw out_of_range("Out_of_range \nQueue is empty \n");
    }
}

template<class T>
void Queue<T>::clear() {
    while (size != 0) {
        dequeue();
    }
}

template<class T>
void Queue<T>::print() {
    Node<T>* aux = head;
    for(int c = 0;c < size;c++) {
        cout << c << ".- [" << aux->data << "] \n";
        aux = aux->next;
    }
    cout << endl;
}