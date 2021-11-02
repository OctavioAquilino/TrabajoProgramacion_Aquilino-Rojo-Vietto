#ifndef U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#include <vector>
#include <iostream>
#include "utils.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include "ArbolBinarioAVL.h"
#include "ArbolBinario.h"
#include "ArbolBinarioEdad.h"
#include <ctime>
#define U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#endif



 using namespace std;

 int stringToint(string fechaString){

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

void quickSortTY(vector<string> arr[], int first, int last) {
  int i, j, middle;
  vector<string> pivot, aux;

  middle = (first + last) / 2;
  pivot = arr[middle];
  i = first;
  j = last;

  do {
    while (stringToint(arr[i][13]) < stringToint(pivot[13]))
      i++;
    while (stringToint(arr[j][13]) > stringToint(pivot[13]))
      j--;

    if (i <= j) {
      aux = arr[i];
      arr[i]= arr[j];
      arr[j]= aux;
      i++;
      j--;
    }
  } while (i <= j);

  if (j > first)
    quickSortTY(arr, first, j);
  if (i < last)
    quickSortTY(arr, i, last);
}




void chopCSV(string fileName, int lines)
{

    string newName = fileName.substr(0, fileName.find(".csv"));
    newName += to_string(lines) + ".csv";

    fstream fin, fout;
    fin.open("./" + fileName, ios::in);
    fout.open("./" + newName, ios::out);

    string line, word;
    for (int i = 0; i < lines; i++)
    {
        getline(fin, line);
        fout << line << "\n";
    }
}

void exploreCSV(string fileName)
{
    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;// opcional? (creo que no)
    string line, word;
    int confirmed = 0;
    int total = -1;

    while (getline(fin, line))// corre todas las filas
    {
        total++;
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) //corre todas las columnas
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "NA";
            }
            row.push_back(word);
        }


        if (row[20].compare("Confirmado") == 0 || total==0)
        {
            for (int i = 0; i < nColumns; i++)
            {
                std::cout << row[colsOfInterest[i]] << " ";
            }
            confirmed++;
            cout << endl;
        }
    }

    cout << "Casos confirmados: " << confirmed << " de " << total << " casos registrados." << endl;
}

void exploreHeaders(string fileName)
{
    
    fstream fin;
    
    fin.open("./" + fileName, ios::in);
    
    string headers, header;
    getline(fin, headers);

    stringstream s(headers);
    while (getline(s, header, ','))
    {
        cout << header << endl;
    }
}



void estad(){
    cout<<endl<<"ejecutando estad.........."<<endl;
}

void quickSortTYY(vector<string> arr[], int first, int last)
{
    
    int i, j, middle;
    vector<string> pivot, aux;

    middle = (first + last) / 2;
    pivot = arr[middle];
    i = first;
    j = last;

    do
    {
        while (stoi(arr[i][1]) > stoi(pivot[1]))
            i++;
        while (stoi(arr[j][1]) < stoi(pivot[1]))
            j--;

        if (i <= j)
        {
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
            i++;
            j--;
        }
    } while (i <= j);

    if (j > first)
        quickSortTYY(arr, first, j);
    if (i < last)
        quickSortTYY(arr, i, last);
}

//////////////////////p_muertes///////////////////////////////////////////////////

void p_muertes(string fileName)
{
    cout << "\n\n////////////////////////////////////////////////////" << endl;
    cout << "Cantidad de muertes por provincia" << endl;
    cout << "////////////////////////////////////////////////////\n"
         << endl;

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> arr[25];

    vector<string> row;
    string line, word;

    int Cont_Provincias[25], a = 0;
    string Provincias[] = {"SIN ESPECIFICAR", "CABA", "Buenos Aires", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes", "Entre Ríos", "Formosa", "La Pampa", "La Rioja", "Mendoza", "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra del Fuego", "Tucumán", "Jujuy", "Misiones"};

    for (int i = 0; i < 25; i++)
    {
        arr[i].push_back(Provincias[i]);
    }

    for (int i = 0; i < 25; i++)
    {
        Cont_Provincias[i] = 0;
    }

    while (getline(fin, line))
    {

        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            row.push_back(word);
        }

        for (int i = 0; i < 25; i++)
        {
            if (row[5] == Provincias[i])
            {
                a++;
                if (row[14] == "SI")
                {
                    Cont_Provincias[i]++;
                }
            }
        }
    }

    for (int i = 0; i < 25; i++)
    {
        arr[i].push_back(to_string(Cont_Provincias[i]));
    }

    quickSortTYY(arr, 0, 24);

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void p_muertes(char *n, string fileName)
{
    cout << "\n\n////////////////////////////////////////////////////" << endl;
    cout << "Cantidad de muertes por provincia" << endl;
    cout << "////////////////////////////////////////////////////\n"
         << endl;

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> arr[25];

    vector<string> row;
    string line, word;

    int Cont_Provincias[25], a = 0;
    string Provincias[] = {"SIN ESPECIFICAR", "CABA", "Buenos Aires", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes", "Entre Ríos", "Formosa", "La Pampa", "La Rioja", "Mendoza", "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra del Fuego", "Tucumán", "Jujuy", "Misiones"};

    for (int i = 0; i < 25; i++)
    {
        arr[i].push_back(Provincias[i]);
    }

    for (int i = 0; i < 25; i++)
    {
        Cont_Provincias[i] = 0;
    }

    while (getline(fin, line))
    {

        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            row.push_back(word);
        }

        for (int i = 0; i < 25; i++)
        {
            if (row[5] == Provincias[i])
            {
                a++;
                if (row[14] == "SI")
                {
                    Cont_Provincias[i]++;
                }
            }
        }
    }

    for (int i = 0; i < 25; i++)
    {
        arr[i].push_back(to_string(Cont_Provincias[i]));
    }

    quickSortTYY(arr, 0, 24);

    int val = atoi(n);

    for (int i = 0; i < val; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

/////////////////////p_casos////////////////////////////////////////////////////

void p_casos(string fileName)
{
    cout << "\n\n////////////////////////////////////////////////////" << endl;
    cout << "Cantidad de casos por provincia" << endl;
    cout << "////////////////////////////////////////////////////\n"<< endl;

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> arr[25];

    vector<string> row;
    string line, word;

    int Cont_Provincias[25], a = 0;
    string Provincias[] = {"SIN ESPECIFICAR", "CABA", "Buenos Aires", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes", "Entre Ríos", "Formosa", "La Pampa", "La Rioja", "Mendoza", "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra del Fuego", "Tucumán", "Jujuy", "Misiones"};

    for (int i = 0; i < 25; i++)
    {
        arr[i].push_back(Provincias[i]);
    }

    for (int i = 0; i < 25; i++)
    {
        Cont_Provincias[i] = 0;
    }

    while (getline(fin, line))
    {

        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            row.push_back(word);
        }

        for (int i = 0; i < 25; i++)
        {
            if (row[5] == Provincias[i])
            {
                Cont_Provincias[i]++;
                a++;
            }
        }
    }

    for (int i = 0; i < 25; i++)
    {
        arr[i].push_back(to_string(Cont_Provincias[i]));
    }

    quickSortTYY(arr, 0, 24);

    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void p_casos(char *n, string fileName)
{
    cout << "\n\n////////////////////////////////////////////////////" << endl;
    cout << "Cantidad de casos por provincia" << endl;
    cout << "////////////////////////////////////////////////////\n"<< endl;

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> arr[25];

    vector<string> row;
    string line, word;

    int Cont_Provincias[25], a = 0;
    string Provincias[] = {"SIN ESPECIFICAR", "CABA", "Buenos Aires", "Catamarca", "Chaco", "Chubut", "Córdoba", "Corrientes", "Entre Ríos", "Formosa", "La Pampa", "La Rioja", "Mendoza", "Neuquén", "Río Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra del Fuego", "Tucumán", "Jujuy", "Misiones"};

    for (int i = 0; i < 25; i++)
    {
        arr[i].push_back(Provincias[i]);
    }

    for (int i = 0; i < 25; i++)
    {
        Cont_Provincias[i] = 0;
    }

    while (getline(fin, line))
    {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            row.push_back(word);
        }

        for (int i = 0; i < 25; i++)
        {
            if (row[5] == Provincias[i])
            {
                Cont_Provincias[i]++;
                a++;
            }
        }
    }

    for (int i = 0; i < 25; i++)
    {
        arr[i].push_back(to_string(Cont_Provincias[i]));
    }

    quickSortTYY(arr, 0, 24);

    int val = atoi(n);

    for (int i = 0; i < val; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}

void casos_edad(string edad_,string fileName){
cout<<endl<<"ejecutando casos_edad("<<edad_<<").........."<<endl;
int edad = stoi(edad_);
int cont =0;
string edadString;
    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
 

ArbolBinarioEdad<vector<string>> arbol;
//ArbolBinario<vector<string>> arbol;

 int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);
    
                   
 
    while (getline(fin, line))// corre todas las filas
    {
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) //corre todas las columnas
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "NA";
            }
            row.push_back(word);
          
        }

        edadString = row[2];
        if (row[3].compare("Años") == 0){
        if(edadString.compare("NA") != 0){
            if(stoi(edadString) == edad){
            arbol.put(row);
            cont ++;
         }
       } 
      }
     }
    arbol.inorder();

std::cout<<"Cantidad de casos con "<<edad<<": " <<cont<<endl;

}

void casos_cui(string fechaString, string fileName){
int fechaNum = stringToint(fechaString);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;
    string line, word;
   
    int total = -1;
    int cont =0;
   int fechaPos = 0;
 
 // vector<string> arr[10000];
ArbolBinarioAVL<vector<string>> arbol;
    while (getline(fin, line))// corre todas las filas
    {
        total++;
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) //corre todas las columnas
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "NA";
            }
            row.push_back(word);
          
        }
        
        if (row[12].compare("SI") == 0 )
        {
            fechaPos = stringToint(row[13]);

            if(fechaNum<fechaPos){
               // arr[cont] = row;
                  arbol.put(row);
            cont++;
            }
        }
        
    }
   
  /* quickSortTY(arr, 0, cont-1);

    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);
    cout<<nColumns<<endl;

    for(int j = 0; j < cont ; j++){
            for (int i = 0; i < nColumns; i++)
            {
                cout << arr[j][colsOfInterest[i]] << "     ";
            }
            cout << endl;
    }
           */
    arbol.inorder();

cout<<"Cantidad de casos cuidados intensivos: "<<cont<<endl;

}




void casos_cui(string fileName){

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;// opcional? (creo que no)
    string line, word;
    //int confirmed = 0;
    int cont =0;
   int fechaPos = 0;

 //vector<string> arr[80000];
//ArbolBinario<vector<string>> arbol;
ArbolBinarioAVL<vector<string>> arbol;
 
    while (getline(fin, line))// corre todas las filas
    {
       
        
        row.clear();
        stringstream s(line);
        while (getline(s, word, ',')) //corre todas las columnas
        {
            if (word.size() > 0)
            {
                word = word.substr(1, word.size() - 2);
            }
            else
            {
                word = "NA";
            }
            row.push_back(word);
          
        }
        
        if (row[12].compare("SI") == 0 )
        {
            // arr[cont] = row;
            arbol.put(row);
            cont++;
        }
        
    }
   
 // quickSortTY(arr, 0, cont-1);
/*
    int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);
    cout<<nColumns<<endl;

    for(int j = 0; j < cont ; j++){
            for (int i = 0; i < nColumns; i++)
            {
                cout << arr[j][colsOfInterest[i]] << "     ";
            }
            cout << endl;
    }
       */    
         
    arbol.inorder();

cout<<"Cantidad de casos cuidados intensivos: "<<cont<<endl;

}






int main(int argc, char **argv)
{
    std::cout<<argc<<endl;
    clock_t begin;
    begin = clock();
        
        if(argc == 3){
            cout<<"Hola"<<endl;
            if(strcmp(argv[1], "-estad") == 0){
            estad();
        }
        else if(strcmp(argv[1], "-p_casos") == 0){
            p_casos(argv[2]);
        }
        else if(strcmp(argv[1], "-p_muertes")==0)
        {
           p_muertes(argv[2]);
        }
       
          else if(strcmp(argv[1], "-casos_cui")==0)
        {
               casos_cui(argv[2]);
        
        }
        
        }
        
        else if(argc == 4){

 
        if(strcmp(argv[1], "-p_casos") == 0){

              p_casos(argv[2],argv[3]);
               
        }
        else if(strcmp(argv[1], "-p_muertes")==0)
        {
                p_muertes(argv[2],argv[3]);
            
        }
        else if(strcmp(argv[1], "-casos_edad")==0)
        {

                casos_edad(argv[2],argv[3]);//cambiar
            
        }

          else if(strcmp(argv[1], "-casos_cui")==0)
        {
                casos_cui(argv[2],argv[3]);
        }
        }
        else{
            cout<< "Error en la sintaxis"<<endl;
        }
    

    clock_t end = clock ();

    double elapsed_secs = static_cast<double>(end - begin ) / CLOCKS_PER_SEC;

    cout<< "Tardo elapsed_secs: "<< elapsed_secs<<"\n"<<endl;
    return 0;
}


