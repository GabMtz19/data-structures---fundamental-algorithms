#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

class HashQ {
    private:
        vector<string> table;
        int size;
        int qty;
        int hashing(string);
        vector<int> status;
        bool isFull();
        int quadTest(int);
    public:
        HashQ(int);
        HashQ(vector<string>);
        int findData(string);
        void addData(string);
        bool isEmpty();
        void deleteData(string);
        void print();
};

HashQ::HashQ(int size) {
    this->size = size;
    qty = 0;
    vector<string> tempTable(size);
    table = tempTable;
    vector<int> tempStatus(size,0);
    status = tempStatus;
}

HashQ::HashQ(vector<string> list) {
    size = list.size();
    qty = 0;
    vector<string> tempTable(size);
    table = tempTable;
    vector<int> tempStatus(size,0);
    status = tempStatus;
    for(auto data : list) {
        int index = hashing(data);
        int newIndex = quadTest(index);
        table[newIndex] = data;
        status[newIndex] = 1;
        qty++;
    }
}

int HashQ::quadTest(int index) {
    if(status[index] != 1) {
        return index;
    } 
    int cont = 1;
    int newIndex = index;
    while(status[newIndex] == 1) {
        newIndex = (index + cont * cont) % size;
        cont++;
    }
    return newIndex;
}

int HashQ::hashing(string data) {
    int key = 0;
    for(auto c : data) {
        key += int(c);
    }
    return key % size;
}

bool HashQ::isFull() {
    return size == qty;
}

void HashQ::print() {
    for(auto element : table) {
        cout << element << endl;
    }
    cout << endl;
}