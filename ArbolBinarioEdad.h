#ifndef U05_ARBOL_ARBOL_ArbolBinarioEdad_H_
#include "NodoArbolEdad.h"
#define U05_ARBOL_ARBOL_ArbolBinarioEdad_H_



template <class T>
class ArbolBinarioEdad
{
protected:
  NodoArbolEdad<T> *root;

public:
  ArbolBinarioEdad();

  void put(T data);

  void inorder();

  ~ArbolBinarioEdad();

  bool esVacio();

  void print();

private:

  NodoArbolEdad<T> *put(T data, NodoArbolEdad<T> *r);
  
  void inorder(NodoArbolEdad<T> *r);

 
};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T>
ArbolBinarioEdad<T>::ArbolBinarioEdad() { root = nullptr; }

/**
 * Destructor del Arbol
 */
template <class T>
ArbolBinarioEdad<T>::~ArbolBinarioEdad() {}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T>
void ArbolBinarioEdad<T>::put(T data) { root = put(data, root); }

template <class T>
NodoArbolEdad<T> *ArbolBinarioEdad<T>::put(T data, NodoArbolEdad<T> *r)
{
  int auxiliar = stoi(data[17]);
  if (r == nullptr)
  {
    return new NodoArbolEdad<T>(data);
  }


  if (r->getClave() >= auxiliar)
  {
    r->setLeft(put(data, r->getLeft()));
  }
  else
  {
    r->setRight(put(data, r->getRight()));
  }

  return r;
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T>
bool ArbolBinarioEdad<T>::esVacio() { return root == nullptr; }


/**
 * Recorre un árbol en orden
 */
template <class T>
void ArbolBinarioEdad<T>::inorder()
{
  inorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinarioEdad<T>::inorder(NodoArbolEdad<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  inorder(r->getLeft());
  r->print();
  inorder(r->getRight());
}


#endif // U05_ARBOL_ARBOL_ArbolBinarioEdad_H_
