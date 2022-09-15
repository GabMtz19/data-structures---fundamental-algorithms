#include "NodeAVL.h"
using namespace std;

template<class T>
struct AVLTree {

    NodeAVL<T>* root;
    int levelsRight,levelsLeft;

    AVLTree();
    void insert(T);
};

template<class T>
AVLTree<T>::AVLTree() {
    root = NULL;
    levelsRight = 0;
    levelsLeft = 0;
}

template<class T>
void AVLTree<T>::insert(T data) {
    if(root != NULL) {
        NodeAVL<T>* aux = root;
        if(levelsLeft <= levelsRight) {
            if(aux->left != NULL) {
                aux = aux->left;
                while(aux != NULL) {
                    if(aux->left == NULL) {
                        aux->left = new NodeAVL<T>(data,NULL,NULL);
                        return;
                    }
                    else if(aux->right == NULL) {
                        aux->right = new NodeAVL<T>(data,NULL,NULL);
                    }
                    else {
                        
                    }
                }
            }
            else {
                aux->left = new NodeAVL<T>(data,NULL,NULL);
            }
        }
    }
    else {
        root = new NodeAVL<T>(data,NULL,NULL);
    }
}