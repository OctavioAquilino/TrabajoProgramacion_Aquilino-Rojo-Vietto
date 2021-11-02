#ifndef U05_ARBOL_ARBOL_ARBOLBINARIOAVLEdad_H_
#define U05_ARBOL_ARBOL_ARBOLBINARIOAVLEdad_H_

#include "NodoArbolAVLEdad.h"

template <class T>
class ArbolBinarioAVLEdad
{
protected:
  NodoArbolAVLEdad<T> *root;

public:
  ArbolBinarioAVLEdad();

  void put(T data);

  void inorder();

  ~ArbolBinarioAVLEdad();

  bool esVacio();

  int getBalance()
  {
    return getBalance(root);
  }

private:
 
  void inorder(NodoArbolAVLEdad<T> *r);

  int max(int a, int b);
  int calculateHeight(NodoArbolAVLEdad<T> *r);
  int getBalance(NodoArbolAVLEdad<T> *r);
  NodoArbolAVLEdad<T> *rotacionDerecha(NodoArbolAVLEdad<T> *y);
  NodoArbolAVLEdad<T> *rotacionIzquierda(NodoArbolAVLEdad<T> *x);
  NodoArbolAVLEdad<T> *put(T data, NodoArbolAVLEdad<T> *r);

 
};


/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T>
ArbolBinarioAVLEdad<T>::ArbolBinarioAVLEdad() { root = nullptr; }

/**
 * Destructor del Arbol
 */
template <class T>
ArbolBinarioAVLEdad<T>::~ArbolBinarioAVLEdad() {}


/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T>
void ArbolBinarioAVLEdad<T>::put(T data) { root = put(data, root); }

template <class T>
NodoArbolAVLEdad<T> *ArbolBinarioAVLEdad<T>::put(T data, NodoArbolAVLEdad<T> *r)
{
  //1. Realizar Insercion normal
  if (r == nullptr)
  {
    return new NodoArbolAVLEdad<T>(data);
  }
  

  if (r->getClave() >= stoi(data[17]))
  {
    r->setLeft(put(data, r->getLeft()));
  }
  else
  {
    r->setRight(put(data, r->getRight()));
  }

  //2. Actualizar altura de este nodo padre
  r->setHeight(max(calculateHeight(r->getLeft()), calculateHeight(r->getRight())) + 1);


  //3. Obtener el factor de balance de este nodo padre
  // y chequear si este nodo se desbalanceo
  int balance = getBalance(r);

  //Quedo desbalanceado II: corresponde una rot Der
  if (balance > 1 && stoi(data[17]) <= r->getLeft()->getClave())
  {
    //std::cout<<"Rotacion derecha"<<std::endl;
    return rotacionDerecha(r);
  }

  //Quedo desbalanceado ID: corresponde una rot Izq Der
  if (balance > 1 && stoi(data[17]) > r->getLeft()->getClave())
  {
    //std::cout<<"Rotacion izq der"<<std::endl;
    r->setLeft(rotacionIzquierda(r->getLeft()));
    return rotacionDerecha(r);
  }

  //Quedo desbalanceado DD: corresponde una rot Izq
  if (balance < -1 && stoi(data[17]) >= r->getRight()->getClave())
  {
    //std::cout<<"Rotacion izq"<<std::endl;
    return rotacionIzquierda(r);
  }

  //Quedo desbalanceado DI: corresponde una rot Der Izq
  if (balance < -1 && stoi(data[17]) <= r->getRight()->getClave())
  {
    //std::cout<<"Rotacion der izq"<<std::endl;
    r->setRight(rotacionDerecha(r->getRight()));
    return rotacionIzquierda(r);
  }

  return r;
  
}


/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T>
bool ArbolBinarioAVLEdad<T>::esVacio() { return root == nullptr; }




/**
 * Recorre un árbol en orden
 */
template <class T>
void ArbolBinarioAVLEdad<T>::inorder()
{
  inorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinarioAVLEdad<T>::inorder(NodoArbolAVLEdad<T> *r)
{
 
  if (r == nullptr)
  {
    return;
  }

  inorder(r->getLeft());
  r->print();
  inorder(r->getRight());
}

template <class T>
int ArbolBinarioAVLEdad<T>::max(int a, int b)
{
  return (a > b) ? a : b;
}

template <class T>
int ArbolBinarioAVLEdad<T>::calculateHeight(NodoArbolAVLEdad<T> *r)
{
  if (r == nullptr)
  {
    return 0;
  }
  else
    return r->getHeight();
}
template <class T>
int ArbolBinarioAVLEdad<T>::getBalance(NodoArbolAVLEdad<T> *r)
{
  if (r == nullptr)
  {
    return 0;
  }
  return calculateHeight(r->getLeft()) - calculateHeight(r->getRight());
}
template <class T>
NodoArbolAVLEdad<T> *ArbolBinarioAVLEdad<T>::rotacionDerecha(NodoArbolAVLEdad<T> *y)
{
  NodoArbolAVLEdad<T> *x = y->getLeft();
  NodoArbolAVLEdad<T> *T2 = x->getRight();

  //Rotacion
  x->setRight(y);
  y->setLeft(T2);

  //Actualizar alturas
  y->setHeight(max(calculateHeight(y->getLeft()), calculateHeight(y->getRight())) + 1);
  x->setHeight(max(calculateHeight(x->getLeft()), calculateHeight(x->getRight())) + 1);

  //Devolver la nueva raiz;
  return x;
}

template <class T>
NodoArbolAVLEdad<T> *ArbolBinarioAVLEdad<T>::rotacionIzquierda(NodoArbolAVLEdad<T> *x)
{
  NodoArbolAVLEdad<T> *y = x->getRight();
  NodoArbolAVLEdad<T> *T2 = y->getLeft();

  //Rotacion
  y->setLeft(x);
  x->setRight(T2);

  //Atualizar alturas
  x->setHeight(max(calculateHeight(x->getLeft()), calculateHeight(x->getRight())) + 1);
  y->setHeight(max(calculateHeight(y->getLeft()), calculateHeight(y->getRight())) + 1);

  //Devolver la nueva raiz
  return y;
}

#endif // U05_ARBOL_ARBOL_ARBOLBINARIOAVLEdad_H_
