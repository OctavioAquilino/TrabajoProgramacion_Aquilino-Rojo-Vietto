#ifndef U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#include "NodoArbolTY.h"
#include <vector>
#define U05_ARBOL_ARBOL_ARBOLBINARIO_H_

#endif


template <class T> 
class ArbolBinarioTY {
protected:
    NodoTY<T> *root;

public:
  ArbolBinarioTY();

  void put(T dato, vector<string> row_);

  void inorder();


private:

    NodoTY<T> *put(T dato, NodoTY<T> *r);

    void inorder(NodoTY<T> *r);
  
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T> ArbolBinarioTY<T>::ArbolBinarioTY() {
    root = nullptr;
}



/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T> void ArbolBinarioTY<T>::put(T dato, vector<string> row_) {
    root->setRow(row_);
    root = put(dato,root);
}

template <class T> NodoTY<T> *ArbolBinarioTY<T>::put(T dato,NodoTY<T> *r)
{
    if(r == nullptr){
        return new NodoTY<T>(dato);
    }
    if(r->getData() >= dato){
        r->setLeft(put(dato,r->getLeft()));
    }
    else{
        r->setRight(put(dato,r->getRight()));
    }
    return r;
}

/**
 * Informa si un árbol esta vacío
 * @return
 */

/**
 * Recorre un árbol en preorden
 */
template <class T> void ArbolBinarioTY<T>::inorder() {
inorder(root);
}

template <class T> void ArbolBinarioTY<T>::inorder(NodoTY<T> * r) {// I - R - D

    if(r== nullptr)
        return;

    inorder(r->getLeft());
    r->print();
    std::cout<<std::endl;
    inorder(r->getRight());
}
