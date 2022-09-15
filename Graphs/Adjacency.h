#ifndef Adjacency_h
#define Adjacency_h

#include "NodeG.h"
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
struct Adjacency {

        NodeG<T> origin;
        vector<NodeG<T>> destinations;

        Adjacency(NodeG<T>);
        void addDestination(NodeG<T>);
        void print();
        
};

template<class T>
Adjacency<T>::Adjacency(NodeG<T> origin) {

    this->origin = origin;

}

template<class T>
void Adjacency<T>::addDestination(NodeG<T> destination) {

    destinations.push_back(destination);

}

template<class T>
void Adjacency<T>::print() {

    cout << origin.data << ": ";
    for(auto node : destinations) {
        cout << node.data << " ";
    }
    cout << endl;

}

#endif