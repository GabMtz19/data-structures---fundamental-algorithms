#ifndef Node_h
#define Node_h

#include "Node_LL.h"
#include <vector>
using namespace std;

template<class T>
class LinkedList {
    private:   
        int size;
        Node<T>* head;
    public:
        LinkedList();
        Node<T>* getHead();
        int getSize();
        void addFirst(T);
        void addLast(T);
        void insertAt(int,T);
        bool UpdateAt(int,T);
        bool UpdateData(T,T);
        int findData(T);
        bool deleteData(T);
        void deleteAt(int);
        void sort(int);
        void duplicate();
        void removeDuplicates();
        void reverse();
        void clear();
        bool isEmpty();
        T operator[](int);
        void operator=(LinkedList<T>);
        void print();
};

template<class T>
LinkedList<T>::LinkedList() {
    head = NULL;
    size = 0;
}

template<class T>
Node<T>* LinkedList<T>::getHead() {
    return head;
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::addFirst(T data) {
    head = new Node<T>(data,head);
    size++;
}

template<class T>
void LinkedList<T>::addLast(T data) {
    if(! isEmpty()) {
        Node<T>* aux = head;
        while(aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
    }
    else {
        head = new Node<T>(data);
    }
    size++;
}

template<class T>
void LinkedList<T>::insertAt(int position,T element) {
    if(! isEmpty()) {
        if(position == 1) {
            addFirst(element);
        }
        else {
            if(position >= 1 && position <= size) {
                Node<T>* aux = head;
                Node<T>* previous = new Node<T>;
                for(int c = 1;c <= size;c++) {
                    if(c == position) {
                        Node<T>* new_element = new Node<T>(element,aux);
                        previous->next = new_element;
                        size++;
                        break;
                    }
                    else {
                        previous = aux;
                        aux = aux->next;
                    }
                }
            }
            else {
                throw out_of_range("Out_of_range element \n");
            }
        }
    }
}

template<class T>
bool LinkedList<T>::UpdateAt(int location,T value) {
    Node<T>* aux = head;
    for(int c = 0;c < size;c++) {
        if(location == c) {
            aux->data = value;
            break;
        }
        aux = aux->next;
    }
    if(aux->data != value) {
        throw out_of_range("Out_of_range \n");
    }
}

template<class T>
bool LinkedList<T>::UpdateData(T element,T value) {
    Node<T>* aux = head;
    for(int c = 0;c < size;c++) {
        if(aux->data == element) {
            aux->data = value;
            break;
        }
        aux = aux->next;
    }
    if(aux->data != value) {
        throw out_of_range("Element_not_found \n");
    }
}

template<class T>
int LinkedList<T>::findData(T element) {
    Node<T>* aux = head;
    for(int c = 0;c < size;c++) {
        if(aux->data == element) {
            return c;
        }
        aux = aux->next;
    }
    throw out_of_range("Element_not_found \n");
}

template<class T>
bool LinkedList<T>::deleteData(T element) {
    if(! isEmpty()) {
        Node<T>* aux = head;
        Node<T>* previous_node = aux;
        for(int c = 0;c < size;c++) {
            if(aux->data == element) {
                previous_node->next = aux->next;
                delete(aux);
                size--;
                return true;
            }
            else {
                previous_node = aux;
                aux = aux->next;
            }
        }
    }
    return false;
}

template<class T>
void LinkedList<T>::deleteAt(int position) {
    if(! isEmpty()) {
        Node<T>* aux = head;
        Node<T>* previous_node;
        for(int c = 1;c <= size;c++) {
            if(c == position) {
                previous_node->next = aux->next;
                delete(aux);
                size--;
            }
            else {
                previous_node = aux;
                aux = aux->next;
            }
        }
    }
}

template<class T>
void LinkedList<T>::sort(int times) {
    if(times != 0) {
        Node<T>* aux = head;
        for(int i = 1;i < size;i++) {
            if(aux->data > aux->next->data) {
                int high = aux->data;
                aux->data = aux->next->data;
                aux->next->data = high;
            }
            aux = aux->next;
        }
        times--;
        sort(times);
    }
}

template<class T>
void LinkedList<T>::duplicate() {
    Node<T>* aux = head;
    int counter = 1;
    while(aux != NULL) {
        insertAt(counter,aux->data);
        aux = aux->next;
        counter += 2;
    }
}

template<class T>
void LinkedList<T>::removeDuplicates() {
    Node<T>* aux = head->next;
    vector<T> elements = {head->data};
    while(aux != NULL) {
        bool repeated = false;
        for(int c = 0;c < elements.size();c++ ){
            if(elements[c] == aux->data) {
                repeated = true;
                break;
            }
        }
        if(!repeated) {
            elements.push_back(aux->data);
        }
        aux = aux->next;
    }
    clear();
    for(int c = 0;c < elements.size();c++) {
        addLast(elements[c]);
    }
}

template<class T>
void LinkedList<T>::reverse() {
    Node<T>* aux = head;
    vector<T> elements;
    while(aux != NULL) {
        elements.push_back(aux->data);
        aux = aux->next;
    }
    clear();
    for(int c = 0;c < elements.size();c++) {
        addFirst(elements[c]);
    }
}

template<class T>
void LinkedList<T>::clear() {
    Node<T>* aux = head;
    do {
        Node<T>* previous = aux;
        aux = aux->next;
        delete(previous);
    } while(aux != NULL);
    head = NULL;
    size = 0;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    return size == 0;
}

template<class T>
T LinkedList<T>::operator[](int position) {
    Node<T>* aux = head;
    for(int c = 1;c <= size;c++) {
        if(c == position) {
            return aux->data;
        }
        aux = aux->next;
    }
    throw out_of_range("Out_of_range \n");
}

template<class T>
void LinkedList<T>::operator=(LinkedList<T> list2) {
    clear();
    for(int c = 1;c <= list2.size;c++) {
        addLast(list2[c]);
    }
}

template<class T>
void LinkedList<T>::print() {
    Node<T>* aux = head;
    int counter = 1;
    while(aux != NULL) {
        cout << counter++ << ".- " << aux->data << endl;
        aux = aux->next;
    }
    cout << endl;
}

#endif