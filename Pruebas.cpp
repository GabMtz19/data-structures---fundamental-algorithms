#include "Hash Table/linkedListH.h"
#include <vector>
#include <time.h>
#include <math.h>
using namespace std;

int main() {
    vector<linkedListH<string>> list;
    for(int c = 0;c < 50;c++) {
        linkedListH<string> something;
        list.push_back(something);
    }
    srand(time(NULL));
    for(int c = 0;c < list.size();c++) {
        string data = "";
        int key = 0;
        for(int i = 0;i < 4;i++) {
            char character;
            if(rand() % 2 == 0) {
                character = '0' + rand() % 10;
            } 
            else {
                character = 'a' + rand() % 26;
            }
            key += int(character);
            data += character;
        }
        cout << "Data: " << data << " Original key: " << key << " ";
        key = pow(key,2);
        cout << "Cuadratic Key: " << key << " ";
        string keyStr = to_string(key);
        cout << "String Key: " << keyStr << " ";
        while(keyStr.size() != 6) {
            keyStr.insert(0,1,'0');
        }
        cout << "Key with 0's: " << keyStr << " ";
        string newKey = "";
        newKey += keyStr[2];
        newKey += keyStr[3];
        key = atoi(newKey.c_str());
        cout << "Key before verification: " << key << " ";
        if(key >= list.size()) {
            key = key % list.size();
        }
        cout << "Key after verification: " << key << endl;
        list[key].addColision(data,key);
    }
    for(auto values : list) {
        values.print();
    }
    system("pause");
    return 0;
}