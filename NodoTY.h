


#include <iostream>
#include <vector>



using namespace std;
template <class T> class NodoTY{
private:
  vector<string> data;
  NodoTY *left, *right;
  int stringToint(string fechaString);
 // vector<string> row;

public:

  NodoTY() {
      left= nullptr;
      right = nullptr;
  }

  NodoTY(T d) {
      data = d;
      left= nullptr;
      right = nullptr;
  }

  int getClave() {
      return stringToint(data[13]);
  }

  T getData() const{
      return data;
  }

  void setData(T d) {
      this->data=d;
  }

  NodoTY *getRight() const {
      return right;
  }

  void setRight(NodoTY *r) {
     this-> right = r;
  }
  
  NodoTY *getLeft() const {
      return left;
  }

  void setLeft(NodoTY *l) {
      this->left = l;
  }

      void print(){
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
 int NodoTY<T>::stringToint(string fechaString){

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


