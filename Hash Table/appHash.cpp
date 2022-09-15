#include "HashQ.h"
#include "tabla_hash.h"
#include <time.h>
using namespace std;

int main() 
{   
    vector<string> list;
    srand(time(NULL));
    for(int c = 0;c < 50;c++) {
        string data = "";
        for(int i = 0;i < 4;i++) {
            char character;
            if(rand() % 2 == 0) {
                character = '0' + rand() % 10;
            }
            else {
                character = 'a' + rand() % 26;
            }
            data += character;
        }
        list.push_back(data);
    }
    tabla_Hash hashTableE(list);
    HashQ hashTableL(list);
    hashTableE.print();
    cout << endl;
    hashTableL.print();
    system("pause");
    return 0;
}