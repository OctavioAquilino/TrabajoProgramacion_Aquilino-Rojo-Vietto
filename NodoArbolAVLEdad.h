#ifndef U05_ARBOL_ARBOL_NODOARBOLAVLEdad_H_
#define U05_ARBOL_ARBOL_NODOARBOLAVLEdad_H_

#include <string.h>
using namespace std;

template <class T>
class NodoArbolAVLEdad
{
private:
  vector<string> data;
  NodoArbolAVLEdad *left, *right;
  int height;
  

public:
  NodoArbolAVLEdad()
  {
    left = nullptr;
    right = nullptr;
    height=1;
  }

  NodoArbolAVLEdad(T d)
  {
    data = d;
    left = nullptr;
    right = nullptr;
    height = 1;
  }

  T getData() const
  {
    return data;
  }

    int getClave()
  {
    return stoi(data[17]);// El 17 solo funciona para casos edad
  }

  void setData(T d)
  {
    this->data = d;
  }

  NodoArbolAVLEdad *getRight() const
  {
    return right;
  }

  void setRight(NodoArbolAVLEdad *r)
  {
    this->right = r;
  }
  NodoArbolAVLEdad *getLeft() const
  {
    return left;
  }

  void setLeft(NodoArbolAVLEdad *l)
  {
    this->left = l;
  }

  int getHeight(){
    return height;
  }

  void setHeight(int h){
    height = h;
  }

        void print(){// modificada para el proyecto
         
    int colsOfInterest[] = {0, 2, 3, 7, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);
    
          for (int i = 0; i < nColumns; i++)
            {
                cout << data[colsOfInterest[i]] << "     ";
            }
            cout << endl;
    }
};




#endif // U05_ARBOL_ARBOL_NODOARBOLAVLEdad_H_
