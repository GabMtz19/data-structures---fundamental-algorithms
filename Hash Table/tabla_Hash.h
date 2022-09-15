#include "linkedListHT.h"
#include <vector>
#include <math.h>
using namespace std;

class tabla_Hash {
    private:
        vector<linkedListHT<string>> table;
        int size;
        int hashing(string);
    public:
        tabla_Hash(int);
        tabla_Hash(vector<string>);
        void print();
};

int tabla_Hash::hashing(string data) {
    int key = 0;
    for(auto c : data) {
        key += int(c);
    }
    key = pow(key,2);
    string keyStr = to_string(key);
    while(keyStr.size() != 6) {
        keyStr.insert(0,1,'0');
    }
    string newKey = "";
    newKey += keyStr[2];
    newKey += keyStr[3];
    key = atoi(newKey.c_str());
    if(key >= size) {
        key = key % size;
    }
    return key;
}

tabla_Hash::tabla_Hash(int size) {
    this->size = size;
    for(int c = 0;c < size;c++) {
        linkedListHT<string> tempList;
        table.push_back(tempList);
    }
}

tabla_Hash::tabla_Hash(vector<string> list) {
    size = list.size();
    for(int c = 0;c < size;c++) {
        linkedListHT<string> tempList;
        table.push_back(tempList);
    }
    for(auto data : list) {
        int key = hashing(data);
        table[key].addColision(data,key);
    }
}

void tabla_Hash::print() {
    for(auto list : table) {
        list.print();
    }
    cout << endl;
}