/*Inclusion de las librerias y clases necesarias*/
#include "Queue_BST.h"
#include "vector"
using namespace std;

/*Se inica la estructura con template*/
template<class T>
class BST {
    
    /*Atributos y Metodos privados*/
    private:
        Node<T>* root;
        int howManyChilds(Node<T>*);
        void height(Node<T>*,int&);
        void preOrder(Node<T>*);
        void inOrder(Node<T>*);
        void postOrder(Node<T>*);
        void levelByLevel(Node<T>*,int);
        void printTree(Node<T>*,int);

    /*Metodos publicos*/
    public:
        BST();
        int obtainHeight();
        void insert(T);
        bool find(T);
        T deleteV(T);
        void visit(int);
        void ancestors(T);
        int whatLevelAmI(T);
        void print();
};

/*Metodo que obtiene el numero de hijos que tiene un nodo*/
template<class T>
int BST<T>::howManyChilds(Node<T>* element) {
    if(element->right != NULL && element->left != NULL) {
        return 2;
    }
    else if(element->left != NULL || element->right != NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

/*Metodo que recorre el arbol binario primero por el subarbol izquierdo y despues por el derecho*/
template<class T>
void BST<T>::preOrder(Node<T>* element) {
    if(element != NULL) {
        cout << element->data << endl;
        preOrder(element->left);
        preOrder(element->right);
    }
}

/*Metodo que recorre el arbol binario en orden*/
template<class T>
void BST<T>::inOrder(Node<T>* element) {
    if(element != NULL) {
        inOrder(element->left);
        cout << element->data << endl;
        inOrder(element->right);
    }
}

/*Metodo que recorre el arbol binario primero por el subarbol derecho y despues por el izquierdo*/
template<class T>
void BST<T>::postOrder(Node<T>* element) {
    if(element != NULL) {
        postOrder(element->left);
        postOrder(element->right);
        cout << element->data << endl;
    }
}

//Metodo que recorre el arbol por niveles
template<class T>
void BST<T>::levelByLevel(Node<T>* element,int level) {
    if(root != NULL) {
        
    }
}

/*Metodo privado que imprime los elementos del arbol binario*/
template<class T>
void BST<T>::printTree(Node<T>* aux,int level) {
    if(aux != NULL) {
        printTree(aux->right,level + 1);
        for(int c = 0;c < level;c++) {
            cout << "  ";
        }
        cout << aux->data << endl;
        printTree(aux->left,level + 1);
    }
}

//Metodo privado para obtener la altura del arbol binario
template<class T>
void BST<T>::height(Node<T>* element,int& level) {
    if(element->left != NULL) {
        height(element->left,++level);
    }
    if(element->right != NULL) {
        if(element->left != NULL) {
            height(element->right,level);
        }
        else {
            height(element->right,++level);
        }
    }
}

/*Metodo constructor por default*/
template<class T>
BST<T>::BST() {
    root = NULL;
}

//Metodo publico que manda a llamar al metodo que obtiene la altura del arbol binario
template<class T>
int BST<T>::obtainHeight() {
    if(root != NULL) {
        int level = 0;
        height(root,level);
        return level;
    }
    else {
        throw runtime_error("There are no values in the binary tree \n");
    }
}

/*Metodo que inserta un nuevo elemento en el arbol binario*/
template<class T>
void BST<T>::insert(T data) {
    if(root == NULL) {
        root = new Node<T>(data);
    }
    else {
        Node<T>* aux = root;
        while(aux != NULL) {
            if(data < aux->data) {
                if(aux->left == NULL ) {
                    aux->left = new Node<T>(data);
                    return;
                }
                else {
                    aux = aux->left;
                }
            }
            else {
                if(aux->right == NULL) {
                    aux->right = new Node<T>(data);
                    return;
                }
                else {
                    aux = aux->right;
                }
            }
        }
    }
}

/*Metodo que encuentra un elemento en el arbol binario*/
template<class T>
bool BST<T>::find(T data) {
    Node<T>* aux = root;
    while (aux != NULL) {
        if(aux->data != data) {
            if(data < aux->data) {
                aux = aux->left;
            }
            else {
                aux = aux->right;
            }
        }
        else {
            return true;
        }
    }
    return false;
}

/*Metodo que elimina un elemento del arbol binario*/
template<class T>
T BST<T>::deleteV(T data) {
    if(root != NULL) {
        Node<T>* father = root;
        Node<T>* aux = father;
        bool found = false;
        while(!found && aux != NULL) {
            if(data == aux->data) {
                found = true;
            }
            else {
                father = aux;
                data < aux->data ? aux = aux->left : aux = aux->right;
            }
        }
        if(found) { 
            switch (howManyChilds(aux)) {
            case 0:
                if(aux == root) {
                    delete aux;
                    root = NULL;
                }
                else {
                    data < father->data ? father->left = NULL : father->right = NULL;
                    delete aux;
                }
                break;
            case 1:
                if(aux == root) {
                    father->left != NULL ? root = root->left : root = root->right;
                }
                else {
                    if(data < father->data) {
                        aux->left != NULL ? father->left = aux->left : father->left = aux->right;
                    }
                    else {
                        aux->left != NULL ? father->right = aux->left : father->right = aux->right;
                    }
                }
                delete aux;
                break;
            case 2:
                Node<T>* father = aux;
                Node<T>* max = aux->left;
                if(max->right == NULL) {
                    aux->data = max->data;
                    father->left = max->left;
                    delete max;
                }
                else {
                    bool found = false;
                    while(!found) {
                        if(max->right == NULL) {
                            found = true;
                        }
                        else {
                            father = max;
                            max = max->right;
                        }
                    }
                    aux->data = max->data;
                    father->right = max->left;
                    delete max;   
                }
                break;
            }
        }
    }
    else {
        throw runtime_error("Element doesn't appear to exist \n");
    }
} 

/*Metodo por el cual se define como se va a recorrer el arbol*/
template<class T>
void BST<T>::visit(int order) {
    if(root != NULL) {
        switch (order) {
        case 1:
            preOrder(root);
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            postOrder(root);
            break;
        case 4:

            levelByLevel(root,0);
            break;
        }
    }
    else {
        throw runtime_error("There are no elements in the binary search tree \n");
    }
}

/*Metodo publico que manda a llamar el metodo para obtener los ancestros de un elemento*/
template<class T>
void BST<T>::ancestors(T data) {
    if(find(data)) {
        Node<T>* aux = root;
        while(aux != NULL) {
            if(aux->data != data) {
                if(data < aux->data) {
                    cout << aux->data << endl;
                    aux = aux->left;
                }
                else {
                    cout << aux->data << endl;
                    aux = aux->right;
                }
            }
            else {
                break;
            }
        }
    }
    else {
        throw runtime_error("Element doesn't appear to exist \n");
    }
}

/*Metodo que se encarga de encontrar en que nivel se encuentra el elemento insertado por el usuario*/
template<class T>
int BST<T>::whatLevelAmI(T data) {
    if(find(data)) {
        Node<T>* aux = root;
        int level = 0;
        while(aux != NULL) {
            if(aux->data != data) {
                if(data < aux->data) {
                    aux = aux->left;
                    level++;
                }
                else {
                    aux = aux->right;
                    level++;
                }
            }
            else {
                return level;
            }
        }
    }
    else {
        return -1;
    }
}

/*Metodo publico para comenzar con la impresion del arbol*/
template<class T>
void BST<T>::print() {
    int level = 0;
    cout << endl;
    printTree(root,level);
    cout << endl;
}