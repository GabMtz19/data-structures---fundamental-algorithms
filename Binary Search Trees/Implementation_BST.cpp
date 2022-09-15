//Inclusion de librerias y clases necesarias
#include <chrono>
#include <time.h>
#include "BST.h"
using namespace std;


//Programa principal
//O(n)
int main() {
    //Se comienza a tomar el tiempo de ejecucion
    auto start = chrono::high_resolution_clock::now();

    //Se crea el objeto del arbol binario y se inicializan otras variables
    BST<int> binary_search_tree;
    int amount,element;

    //Se agrega el numero de elementos que el usuario desee
    cout << "Enter the number of elements you wish to insert into the tree: ";
    cin >> amount;
    srand(time(NULL));
    for(int c = 0;c < amount;c++) {
        element = rand() % 101;
        binary_search_tree.insert(element);
    }

    //Se despliega el arbol
    binary_search_tree.print();

    //Se elemina el numero de elementos que el usuario desee
    cout << "How many elements do you wish to delete? ";
    cin >> amount;
    for(int c = 0; c < amount;c++) {
        cout << "Element: ";
        cin >> element;
        try {
            binary_search_tree.deleteV(element);
        }
        catch(runtime_error error) {
            cout << error.what();
        }
    }
    binary_search_tree.print();

    //Se prueban los distintos metodos para recorrer el arbol
    try {
        cout << "Preorder: " << endl;
        binary_search_tree.visit(1);
        cout << endl;
        cout << "Inorder: " << endl;
        binary_search_tree.visit(2);
        cout << endl;
        cout << "Postorder: " << endl;
        binary_search_tree.visit(3);
        cout << endl;
        cout << "Level by level: " << endl;
        binary_search_tree.visit(4);
        cout << endl;
    }
    catch(runtime_error error) {
        cout << error.what();
    }
    cout << endl;

    //Obtenemos la altura del arbol
    try {
        cout << "Height of the binary tree: " << binary_search_tree.obtainHeight() << endl;
    }
    catch(runtime_error error) {
        cout << error.what();
    }
    cout << endl;

    //Obtenemos los ancestros del valor que introduzca el usuario
    cout << "Enter the data whom's ancestors you wish to obtain: ";
    cin >> element;
    try {
        cout << "Ancestors: \n";
        binary_search_tree.ancestors(element);
    }
    catch(runtime_error error) {
        cout << error.what();
    }
    cout << endl;

    //Se obtiene el nivel del valor que se solicita
    cout << "Enter a element whom's level you want to obtain: ";
    cin >> element;
    cout << "The level at which the element [" << element << "] is located is: " << binary_search_tree.whatLevelAmI(element) << endl;

    //Se termina de contar el tiempo de ejecucion
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> time = finish - start;
    cout << "Execution time: " << time.count() << endl;

    //Finaliza el programa
    cout << "Program has finished \n";
    return 0;
}