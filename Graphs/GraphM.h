#include "Adjacency.h"
#include <algorithm>
using namespace std;

template<class T>
class GraphM {
    
    private:

        vector<vector<int>> edges;
        vector<T> nodes;
        int findNode(T);
        void printNodes();

    public:

        GraphM(vector<vector<T>>);
        void print();
        void bfs();
        void dfs();

};

template<class T>
GraphM<T>::GraphM(vector<vector<T>> list) {

    int origin = 0;
    int destination = 1;
    int weighing = 2;

    for(auto elements : list) {
        T originData = elements[origin];
        int positionO = findNode(originData);
        if(positionO < 0) {
            nodes.push_back(originData);
        }
        T destinationData = elements[destination];
        int positionD = findNode(destinationData);
        if(positionD < 0) {
            nodes.push_back(destinationData);
        }
    }

    sort(nodes.begin(),nodes.end());

    for(int c = 0;c < nodes.size();c++) {
        vector<int> temp(nodes.size(),-1);
        edges.push_back(temp);
    }

    for(auto elements : list) {
        int positionO = findNode(elements[origin]);
        int positionD = findNode(elements[destination]);
        edges[positionO][positionD] = elements[weighing];
    }

}

template<class T>
int GraphM<T>::findNode(T node) {

    typename vector<T>::iterator it;
    it = find(nodes.begin(),nodes.end(),node);
    if(it != nodes.end()) {
        return it - nodes.begin();
    }
    else {
        return -1;
    }

}

template<class T>
void GraphM<T>::print() {

    cout << " ";
    for(auto node : nodes) {
        cout << " " << node;
    }
    cout << endl;
    for(int c = 0;c < nodes.size();c++) {
        cout << nodes[c] << " ";
        for(int i = 0;i < nodes.size();i++) {
            int weighing = edges[c][i];
            if(weighing >= 0) {
                cout << weighing << " ";
            }
            else {
                cout << "-" << " ";
            }
        }
        cout << endl;
    }

}

template<class T>
void GraphM<T>::printNodes() {

    for(auto node : nodes) {
        cout << "[" << node << "] ";
    }
    cout << endl;

}

template<class T>
void GraphM<T>::bfs() {

    vector<bool> status(nodes.size(),false);
    queue<T> waitingList;
    T node;
    printNodes();
    cout << "Enter the node from where you wish to start: ";
    cin >> node;
    int position = findNode(node);
    waitingList.push(node);
    status[position] = true;
    while(! waitingList.empty()) {
        node = waitingList.front();
        waitingList.pop();
        position = findNode(node);
        cout << node << ":";
        for(int c = 0;c < nodes.size();c++) {
            if(edges[position][c] >= 0) {
                cout << " " << nodes[c];           
            }
            if(! status[c]) {
                waitingList.push(nodes[c]);
                status[c] = true;
            }
        }
        cout << endl;
    }

}

template<class T>
void GraphM<T>::dfs() {

    vector<bool> status(nodes.size(),false);
    stack<T> waitingList;
    T node;
    printNodes();
    cout << "Enter the node from where you wish to start: ";
    cin >> node;
    int position = findNode(node);
    waitingList.push(node);
    status[position] = true;
    while(! waitingList.empty()) {
        node = waitingList.top();
        waitingList.pop();
        position = findNode(node);
        cout << node << ":";
        for(int c = 0;c < nodes.size();c++) {
            if(edges[position][c] >= 0) {
                cout << " " << nodes[c];           
            }
            if(! status[c]) {
                waitingList.push(nodes[c]);
                status[c] = true;
            }
        }
        cout << endl;
    }

}