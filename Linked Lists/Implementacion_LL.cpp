#include "LinkedList.h"
#include <vector>
#include <iostream>
#include <time.h>
using namespace std;

int main() {
    cout << "First List: " << endl;
    LinkedList<int> list;
    for(int c = 1;c <= 10;c++) {
        int number = rand() % 101;
        list.addFirst(number);
    }
    list.print();
    cout << "Second List: " << endl;
    LinkedList<int> list2;
    for(int c = 1;c <= 10;c++) {
        int number = rand() % 101;
        list2.addFirst(number);
    }
    list2.print();
    cout << "Insert 21 at position 10: " << endl;
    list.insertAt(10,21);
    list.print();
    cout << "Clear List: " << endl;
    list.clear();
    list.print();
    cout << "New list: " << endl;
    for(int c = 1;c <= 10;c++) {
        int number = rand() % 101;
        list.addFirst(number);
    }
    list.print();   
    cout << "Sorted list: " << endl;
    list.sort(list.getSize());
    list.print();
    cout << "Duplicated list: " << endl;
    list.duplicate();
    list.print();
    cout << "Duplicates removed list: " << endl;
    list.removeDuplicates();
    list.print();
    cout << "Reversed list: " << endl;
    list.reverse();
    list.print();
    cout << "Equal operator list (list 1 = list 2): " << endl;
    list = list2;
    list.print();
    return 0;
}  