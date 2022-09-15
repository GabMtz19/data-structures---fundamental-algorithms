/*Inclusion de las 
librerias necesarias*/
#include <iostream>

/*Se inicia la
estructura como
template*/
template<class T>
struct Node {

        //Atributos
        T data;
        Node<T>* left;
        Node<T>* right;
        
        //Metodos
        Node();
        Node(T);
        Node(Node<T>*,T);
};

/*Metodo constructor
por default*/
template<class T>
Node<T>::Node() {
    
}

/*Metodo constructor
con un parametro de 
entrada*/
template<class T>
Node<T>::Node(T data) {
    this->data = data;
    left = NULL;
    right = NULL;
}

template<class T>
Node<T>::Node(Node<T>* previous,T data) {
    left = previous;
    this->data = data;
    right = NULL;
}