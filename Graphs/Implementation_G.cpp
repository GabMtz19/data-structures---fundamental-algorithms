#include "GraphL.h"
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));
    vector<NodeG<int>> nodes;
    for(int c = 0;c < 10;c++) {
        int weight = rand() % 101;
        NodeG<int> node(c,weight);
        nodes.push_back(node);
    }
    vector<vector<NodeG<int>>> list;
    for(int c = 0;c < 30;c++) {
        int origin = rand() % 10;
        int destination = rand() % 10;
        while(destination == origin) {
            destination = rand() % 10;
        }
        vector<NodeG<int>> edge = {nodes[origin],nodes[destination]};
        list.push_back(edge);
    }
    GraphL<int> graphList(list);

    cout << "List representation for graph: \n";
    graphList.print();
    cout << endl;
    cout << "BFS for list representation: \n";
    graphList.bfs();
    cout << endl;
    cout << "DFS for list representation: \n";
    graphList.dfs();
    cout << endl;

    system("pause");

    return 0;
}

/*//Inclusion de las librerias y clases
#include "GraphM.h"
#include "GraphL.h"
using namespace std;

//Valor global que sirve para la representacion del grafo
char representation = 'A';

//Funcion que despliega todas las tareas que realiza el programa
int menu() {

    //Se pide cual de las funciones desea realizar el usuario
    int option;
    cout << "Functions of the program \n"
    "Current representation of the graph: ";
    representation == 'A' ? cout << "Adjaceny list \n" : cout << "Matrix \n";
    cout << "1.- Change representation of the graph \n"
    "2.- Print the graph \n"
    "3.- Use BFS \n"
    "4.- Use DFS \n"
    "5.- Find shortest path \n"
    "0.- End program \n\n"
    "Option: ";
    cin >> option;
    return option;

}

//Funcion principal del programa
int main() {

    //Se crean los grafos y otras variables necesarias para el programa
    int option;
    vector<vector<int>> list = {{0,1,1},{0,2,2},{0,3,3},{1,0,1},{1,4,3},{3,2,1},{5,6,1}};
    GraphL<int> graphList(list);

    //Comienza la ejecucion principal del programa
    cout << "Welcome to the graph representation program \n";
    system("pause");

    //Mientras el usuario lo desee, se ejecutaran las funciones que el escoja
    do {

        //Se solicita cual de las funciones quiere realizar
        cout << endl << endl;
        option = menu();

        //Se ejecuta alguna de las funciones en caso de existir el numero que el usuario escogio
        switch (option) {
            //Se termina el programa
            case 0:
                cout << "Thanks for using Implementation_G.cpp \n";
                break;
            //Se cambia la representacion del grafo
            case 1:
                representation == 'A' ? representation = 'M' : representation = 'A';
                cout << "Representation successfully updated \n";
                break;
            //Se imprime el grafo
            case 2:
                representation == 'A' ? graphList.print() : graphMatrix.print();
                break;
            //Se recorre el grafo por medio de la anchura
            case 3:
                representation == 'A' ? graphList.bfs() : graphMatrix.bfs();
                break;
            //se recorre el grafo por medio de la profundidad
            case 4:
                representation == 'A' ? graphList.dfs() : graphMatrix.dfs();
                break;
            //En caso de no existir la funcion seleccionada, se le da a conocer esto al usuario
            case 5:
                representation == 'A' ? graphList.shortestPath() : graphMatrix.shortestPath();
                break;
            default:
                cout << "<<ERROR>> Invalid function \n";
                break;
        }

    } while(option != 0);   //Si el usuario no escoge la funcion de terminar el programa, el programa continua

    return 0;
} */