//Inclusion de las librerias y clases correspondientes
#include "Stacks.h"
#include <time.h>
using namespace std;

//Implementacion
int main() {

    //Creacion del objeto Stack
    Stacks<int> stack;

    //Se llena de elementos el objeto
    srand(time(NULL));
    for(int c = 0;c < 10;c++) {
        stack.push(rand() % 101);
    }

    //Se despliega el elemento Top
    cout << "Top: " << stack.getTop()->data << endl << endl;

    //Se imprimen todos los datos del objeto Stack
    cout << "Stack: " << endl;
    stack.print();

    //Se elimina la cantidad de elementos
    //deseados del Stack
    int number;
    cout << "Enter the number of elements you wish to erase \n"
    "Keep in mind that the length of the stack is " << stack.getSize() << endl <<
    "Number of elements: ";
    cin >> number;
    for (int c = 0;c < number;c++)
    {
        try {
            cout << "Element popped is: " << stack.pop() << endl;
        }
        catch(out_of_range& error) {
            cout << error.what() << '\n';
            break;
        }
    }

    //Se despliega el nuevo elemento Top
    cout << "Top: " << endl;
    try {
        cout << stack.getTop()->data << endl;
    }
    catch(out_of_range& error) {
        cout << error.what() << '\n';
    }
    
    //Se imprime el Stack y el Stack vacio
    if(stack.getSize() == 0) {
        for(int c = 0;c < 10;c++) {
            stack.push(rand() % 101);
        }
        cout << "New List: \n";
    }
    else {
        cout << "Remaining List: \n";
    }
    stack.print();
    cout << "Cleared List: \n";
    stack.clear();
    stack.print();
    return 0;
}