#include <iostream>
using namespace std;

template<class T>
struct NodeAVL {
    NodeAVL<T>* right;
    NodeAVL<T>* left;
    T data;
    NodeAVL();
    NodeAVL(T,NodeAVL<T>*,NodeAVL<T>*);
};

template<class T>
NodeAVL<T>::NodeAVL() {
    right = NULL;
    left = NULL;
}

template<class T>
NodeAVL<T>::NodeAVL(T data,NodeAVL<T>* right,NodeAVL<T>* left) {
    this->data = data;
    this->right = right;
    this->left = left;
}