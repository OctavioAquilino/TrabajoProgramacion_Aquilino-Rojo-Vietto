
#ifndef hola
#include <vector>
#include <iostream>
#define hola
#endif

using namespace std;
template <class T>

class NodoQS {
private:
    T dato;
    vector<string> row;
   // NodoQS<T> *siguiente;

public:

    T getDato(){ return dato;}
    void setDato(T d){ dato=d;}
    void setRow(vector<string> row_){
        row=row_;
    }

    void print(){
        
        int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);
    
                    for (int i = 0; i < nColumns; i++)
            {
              
                cout << row[colsOfInterest[i]] << "     ";
            }
           
            cout << endl;
       

    }

    void copy(NodoQS<T> aux){
        this->row = aux.row ;
        this->dato = aux.getDato();
    }


};
