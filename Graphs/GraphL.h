#include "Adjacency.h"
#include <queue>
#include <stack>
using namespace std;

template<class T>
class GraphL {

    private:

        vector<Adjacency<NodeG<T>>> adjList;
        vector<NodeG<T>> nodes;
        int findNode(T);
        void printNodes();
        void restartStatus();

    public:

        GraphL(vector<vector<NodeG<T>>>);
        void print();
        void bfs();
        void dfs();

};

template<class T>
GraphL<T>::GraphL(vector<vector<NodeG<T>>> list) {

    int origin = 0;
    int destination = 1;

    for(auto elements : list) {
        NodeG<T> originData = elements[origin];
        int positionO = findNode(originData.data);
        if(positionO < 0) {
            nodes.push_back(originData);
        }
        NodeG<T> destinationData = elements[destination];
        int positionD = findNode(destinationData.data);
        if(positionD < 0) {
            nodes.push_back(destinationData);
        }
    }

    sort(nodes.begin(),nodes.end());

    for(auto node : nodes) {
        Adjacency<NodeG<T>> edge(node);
        adjList.push_back(edge);
    }

    for(auto elements : list) {
        NodeG<T> destinationData = elements[destination];
        int positionO = findNode(elements[origin].data);
        adjList[positionO].addDestination(destinationData);
    }

}

template<class T>
int GraphL<T>::findNode(T node) {

    for(int c = 0;c < nodes.size();c++) {
        if(nodes[c].data == node) {
            return c;
        }
    }

    return -1;

}

template<class T>
void GraphL<T>::print() {

    for(auto adj : adjList) {
        adj.print();
    }

}

template<class T>
void GraphL<T>::printNodes() {

    for(auto node : nodes) {
        cout << "[" << node.data << "] ";
    }
    cout << endl;

}

template<class T>
void GraphL<T>::restartStatus() {
    for(int c = 0;c < nodes.size();c++) {
        nodes[c].status = false;
    }
}

template<class T>
void GraphL<T>::bfs() {

    queue<T> waitingList;
    T node;
    printNodes();
    cout << "Enter the node form where you wish to start (Ex: 3): ";
    cin >> node;
    int position = findNode(node);
    nodes[position].status = true;
    waitingList.push(node);
    while(! waitingList.empty()) {
        node = waitingList.front();
        position = findNode(node);
        waitingList.pop();
        cout << node << ":";
        for(auto destination : adjList[position].destinations) {
            cout << " " << destination.data;
            int positionD = findNode(destination.data);
            if(! nodes[positionD].status) {
                waitingList.push(destination);
                nodes[positionD].status = true;
            }
        }
        cout << endl;
    }
    restartStatus();

}

template<class T>
void GraphL<T>::bfs() {

    queue<T> waitingList;
    T node;
    printNodes();
    cout << "Enter the node form where you wish to start (Ex: 3): ";
    cin >> node;
    int position = findNode(node);
    nodes[position].status = true;
    waitingList.push(node);
    while(! waitingList.empty()) {
        node = waitingList.front();
        position = findNode(node);
        waitingList.pop();
        cout << node << ":";
        for(auto destination : adjList[position].destinations) {
            cout << " " << destination.data;
            int positionD = findNode(destination.data);
            if(! nodes[positionD].status) {
                waitingList.push(destination);
                nodes[positionD].status = true;
            }
        }
        cout << endl;
    }
    restartStatus();

}