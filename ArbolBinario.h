#ifndef U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#include "NodoTY.h"
#define U05_ARBOL_ARBOL_ARBOLBINARIO_H_



template <class T>
class ArbolBinario
{
protected:
  NodoTY<T> *root;

public:
  ArbolBinario();

  void put(T data);

  T search(T data);

  void remove(T data);

  void inorder();

  ~ArbolBinario();

  bool esVacio();

  void print();

private:
  T search(T data, NodoTY<T> *r);
  NodoTY<T> *put(T data, NodoTY<T> *r);
  NodoTY<T> *remove(T data, NodoTY<T> *r);
  NodoTY<T> *findMaxAndRemove(NodoTY<T> *r, bool *found);
  void preorder(NodoTY<T> *r);
  void inorder(NodoTY<T> *r);
  void postorder(NodoTY<T> *r);
  int stringToint(string );

  
};

template <class T>
  int ArbolBinario<T>::stringToint(string fechaString){

int j=0, num = 0;
string fecha_;
int n=fechaString.size();
for(int i = 0; i<n;i++){
int x = fechaString[i];
if(x>=48 && x<=57){
fecha_[j] = fechaString[i];
j++;
}
}
return stoi(fecha_);
}
/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T>
ArbolBinario<T>::ArbolBinario() { root = nullptr; }

/**
 * Destructor del Arbol
 */
template <class T>
ArbolBinario<T>::~ArbolBinario() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T>
T ArbolBinario<T>::search(T data)
{
  return search(data, root);
}

template <class T>
T ArbolBinario<T>::search(T data, NodoTY<T> *r)
{
  int auxiliar = stringToint(data[13]);
  if (r == nullptr)
  {
    throw 404;
  }

  if (r->getClave() == auxiliar)
  {
    return r->getData();
  }

  if (r->getClave() > auxiliar)
  {
    return search(data, r->getLeft());
  }
  else
  {
    return search(data, r->getRight());
  }
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T>
void ArbolBinario<T>::put(T data) { root = put(data, root); }

template <class T>
NodoTY<T> *ArbolBinario<T>::put(T data, NodoTY<T> *r)
{
  int auxiliar = stringToint(data[13]);
  if (r == nullptr)
  {
    return new NodoTY<T>(data);
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
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template <class T>
void ArbolBinario<T>::remove(T data)
{
  root = remove(data, root);
}

template <class T>
NodoTY<T> *ArbolBinario<T>::remove(T data, NodoTY<T> *r)
{
  NodoTY<T> *aux;
int auxiliar = stringToint(data[13]);
  if (r == nullptr)
  {
    throw 404;
  }

  if (r->getClave() == auxiliar)
  {

    if (r->getLeft() == nullptr && r->getRight() == nullptr)
    {
      delete r;
      return nullptr;
    }
    else if (r->getLeft() != nullptr && r->getRight() == nullptr)
    {
      aux = r->getLeft();
      delete r;
      return aux;
    }
    else if (r->getLeft() == nullptr && r->getRight() != nullptr)
    {
      aux = r->getRight();
      delete r;
      return aux;
    }
    else if (r->getLeft() != nullptr && r->getRight() != nullptr)
    {

      if (r->getLeft()->getRight() != nullptr)
      {
        // Aca tenemos que buscar el valor maximo
        bool found;
        aux = findMaxAndRemove(r->getLeft(), &found);
        aux->setRight(r->getRight());
        aux->setLeft(r->getLeft());
      }
      else
      {
        aux = r->getLeft();
        r->getLeft()->setRight(r->getRight());
      }
      delete r;
      return aux;
    }
  }
  else if (r->getClave() > auxiliar)
  {
    r->setLeft(remove(data, r->getLeft()));
  }
  else
  {
    r->setRight(remove(data, r->getRight()));
  }

  return r;
}


/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T>
bool ArbolBinario<T>::esVacio() { return root == nullptr; }






/**
 * Recorre un árbol en orden
 */
template <class T>
void ArbolBinario<T>::inorder()
{
  inorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::inorder(NodoTY<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  inorder(r->getLeft());
  r->print();
  inorder(r->getRight());
}

/**
 * Muestra un árbol por consola
 */
template <class T>
void ArbolBinario<T>::print()
{
  if (root != NULL)
    root->print(false, "");
}

#endif // U05_ARBOL_ARBOL_ARBOLBINARIO_H_
