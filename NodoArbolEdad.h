


#include <iostream>
#include <vector>



using namespace std;
template <class T> class NodoArbolEdad{
private:
  vector<string> data;
  NodoArbolEdad *left, *right;
 

public:

  NodoArbolEdad() {
      left= nullptr;
      right = nullptr;
  }

  NodoArbolEdad(T d) {
      data = d;
      left= nullptr;
      right = nullptr;
  }

  int getClave() {
      return stoi(data[17]); // 17 = Carga_Provincias
  }

  T getData() const{
      return data;
  }

  void setData(T d) {
      this->data=d;
  }

  NodoArbolEdad *getRight() const {
      return right;
  }

  void setRight(NodoArbolEdad *r) {
     this-> right = r;
  }
  
  NodoArbolEdad *getLeft() const {
      return left;
  }

  void setLeft(NodoArbolEdad *l) {
      this->left = l;
  }

      void print(){
    int colsOfInterest[] = {0, 2, 3, 7, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);
    
          for (int i = 0; i < nColumns; i++)
            {
                cout << data[colsOfInterest[i]] << "     ";
            }
            cout << endl;
    }

    
};



