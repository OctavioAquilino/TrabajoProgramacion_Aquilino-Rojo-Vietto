#ifndef U05_ARBOL_ARBOL_NODOARBOLAVL_H_
#define U05_ARBOL_ARBOL_NODOARBOLAVL_H_

#include <string.h>
using namespace std;

template <class T>
class NodoArbolAVL
{
private:
  vector<string> data;
  NodoArbolAVL *left, *right;
  int height;
  int stringToint(string fechaString);

public:
  NodoArbolAVL()
  {
    left = nullptr;
    right = nullptr;
    height=1;
  }

  NodoArbolAVL(T d)
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
    return stringToint(data[13]);// El 13 solo funciona para casos cui
  }

  void setData(T d)
  {
    this->data = d;
  }

  NodoArbolAVL *getRight() const
  {
    return right;
  }

  void setRight(NodoArbolAVL *r)
  {
    this->right = r;
  }
  NodoArbolAVL *getLeft() const
  {
    return left;
  }

  void setLeft(NodoArbolAVL *l)
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
         
    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);
    
          for (int i = 0; i < nColumns; i++)
            {
                cout << data[colsOfInterest[i]] << "     ";
            }
            cout << endl;
    }
};


template<class T>
 int NodoArbolAVL<T>::stringToint(string fechaString){

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




#endif // U05_ARBOL_ARBOL_NODOARBOLAVL_H_
