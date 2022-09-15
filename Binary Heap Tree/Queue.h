#ifndef Queue_h
#define Queue_h

#include "NodeD.h"
using namespace std;

template<class T>
class Queue{
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;
public:
    Queue();
    void enqueue(T);
    T dequeue();
    T front();
    T back();
    int getSize();
    void clear();
    void print();
    bool isEmpty();
};

template<class T>
Queue<T>::Queue() {
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T>
void Queue<T>::enqueue(T data) {
    NodeD<T>* aux = new NodeD<T>(data);
    if (isEmpty()) {
        head = aux;
        tail = aux;
    } else {
        tail->next = aux;
        tail = aux;
    }
    size++;
}

template<class T>
T Queue<T>::dequeue() {
    T data;
    if (!isEmpty()) {
        NodeD<T>* aux = head;
        data = aux->data;
        head = aux->next;
        delete aux;
        size--;
        if (head == NULL) {
            tail = NULL;
        }
        return data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
T Queue<T>::front() {
    if (!isEmpty()) {
        return head->data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
T Queue<T>::back() {
    if (!isEmpty()) {
        return tail->data;
    }
    throw runtime_error("The Queue is empty");
}

template<class T>
int Queue<T>::getSize() {
    return size;
}

template<class T>
void Queue<T>::clear() {
    while (head != NULL) {
        NodeD<T>* aux = head;
        head = aux->next;
        delete aux;
    }
    size = 0;
    tail = NULL;
}

template<class T>
void Queue<T>::print() {
    NodeD<T>* aux = head;
    while (aux != NULL) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}


template<class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}
#endif