//Inclusion de las librerias y clases correspondientes
#include <iostream>
#include <time.h>
#include "Queue.h"
using namespace std;

//Implementacion de la clase Queue
int main() {

    //Se crea el objeto queue y se
    //inicializa otra variable
    Queue<int> queue_list;
    int number;

    //Se llena de datos el objeto
    srand(time(NULL));
    for(int c = 0;c < 10;c++) {
        number = rand() % 101;
        queue_list.enqueue(number);
    }

    //Se demuestran el primer y ultimo
    //agregado respectivamente
    cout << "Head: " << queue_list.front()->data << endl;
    cout << "Tail: " << queue_list.back()->data << endl << endl;

    //Se imprimen todos los datos del objeto
    cout << "Queue: \n";
    queue_list.print();

    //Se eliminan el numero de datos deseados del queue
    cout << "Enter the number of elements you wish to erase \n"
    "Consider the length of the queue is " << queue_list.getSize() << endl <<
    "Number of elements: ";
    cin >> number;
    cout << endl;
    for(int c = 0;c < number;c++) {
        try {
            cout << "Dequeued element: " << queue_list.dequeue() << endl;
        }
        catch(out_of_range& error) {
            cout << error.what();
            break;
        }
    }
    cout << endl;

    //Se despliegan los nuevos valores de head y tail
    cout << "Head: ";
    try {
        cout << queue_list.front()->data << endl;
    }
    catch(out_of_range& error) {
        cout << error.what() << endl;
    }
    cout << "Tail: ";
    try {
        cout << queue_list.back()->data << endl << endl;
    }
    catch(out_of_range& error) {
        cout << error.what() << endl;
    }   

    //Se imprime el queue y se borran todos los elementos del mismo
    if(queue_list.getSize() == 0) {
        for (int c = 0;c < 10;c++) {
            number = rand() % 101;
            queue_list.enqueue(number);
        }
    }
    cout << "Queue: " << endl;
    queue_list.print();
    cout << "Cleared Queue: " << endl;
    queue_list.clear();
    queue_list.print();
    return 0;
}