#include "NodeH.h"
using namespace std;

template<class T>
class linkedListHT {
    private:
        NodeH<T>* head;
        int size;
    public:
        linkedListHT();
        void addColision(T,int);
        T remove();
        void print();
};

template<class T>
linkedListHT<T>::linkedListHT() {
    size = 0;
    head = NULL;
}

template<class T>
void linkedListHT<T>::addColision(T data,int key) {
    if(size != 0) {
        head = new NodeH<T>(data,key,head);
    }
    else {
        head = new NodeH<T>(data,key);
    }
    size++;
}

template<class T>
T linkedListHT<T>::remove() {
    if(size != 0) {
        NodeH<T>* aux = head;
        T data = aux->data;
        head = head->next;
        delete aux;
        return data;
    }
    throw runtime_error("<<ERROR>>-->The linked list appears to be empty\n");
}

template<class T>
void linkedListHT<T>::print() {
    NodeH<T>* aux = head;
    while(aux != NULL) {
        cout << aux->data << " " << aux->key << " / ";
        aux = aux->next;
    }
    cout << endl;
}