#ifndef NodeG_h
#define NodeG_h

#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
struct NodeG {

    T data;
    int weight;
    bool status;
    
    NodeG();
    NodeG(T,int);
    int operator-(NodeG<T>);
    bool operator==(NodeG<T>);

};

template<class T>
NodeG<T>::NodeG() {

    weight = 0;
    status = false;

}

template<class T>
NodeG<T>::NodeG(T data,int weight) {
    this->data = data;
    this->weight = weight;
    status = false;
}

template<class T>
int NodeG<T>::operator-(NodeG<T> node) {
    int distance = weight - node.weight;
    return abs(distance);
}

template<class T>
bool NodeG<T>::operator==(NodeG<T> node) {
    return data == node.data ? true : false;
}

#endif