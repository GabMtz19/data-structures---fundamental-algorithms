#include "heap_Tree.h"
using namespace std;

template<class T>
void heapSort(DoublyLinkedList<T>& list) {
    char order;
    heap<T> heapAux(list);
    list.clear();
    cout << "Choose how you wish to acomodate you new list: \n"
    "Ascending: insert A \n"
    "Descending: insert D \n"
    "Option: ";
    cin >> order;
    while(!heapAux.isEmpty()) {
        if(order == 'A') {
            list.addFirst(heapAux.remove());
        }
        else {
            list.addLast(heapAux.remove());
        }
    }
}

int main() {
    DoublyLinkedList<int> list;
    list = {8,5,17,19,28,21};
    list.print();
    heap<int> heap_tree(list);
    heap_tree.print();
    heap_tree.insert(40);
    heap_tree.print();
    heapSort(list);
    list.print();
    return 0;
}