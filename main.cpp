#ifndef U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#include <vector>
#include <iostream>
#include "utils.h"
#include <fstream>
#include <sstream>
#include <string.h>
#include "ArbolBinario.h"
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

void casos_edad(char * anios){
cout<<endl<<"ejecutando casos_edad("<<anios<<").........."<<endl;
}

void casos_cui(string fechaString, string fileName){
int fechaNum = stringToint(fechaString);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;// opcional? (creo que no)
    string line, word;
    //int confirmed = 0;
    int total = -1;
    int cont =0;
   int fechaPos = 0;
 
 // vector<string> arr[3000];
ArbolBinario<vector<string>> arbol;
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
           // cout<<word<<endl;
        }
        
        if (row[12].compare("SI") == 0 )
        {
        //cout<<"Hola"<<endl;
             
                 fechaPos = stringToint(row[13]);

            if(fechaNum<fechaPos){
            
      
                //arr[cont] = row;
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

cout<<"Cantidad de casos cuidados intensivos para joaquin: "<<cont<<endl;
//cout<<"Fecha en numero: "<<fechaNum<<endl;
//cout<<"Fecha ingresada: "<<fecha<<endl;

}




void casos_cui(string fileName){

 int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20};
    int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

    fstream fin;
    fin.open("./" + fileName, ios::in);

    vector<string> row;// opcional? (creo que no)
    string line, word;
    int confirmed = 0;
    int total = -1, cont =0;

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


        if (row[12].compare("SI") == 0 || total==0)
        {
            cont++;
            for (int i = 0; i < cont; i++)
            {
                cout << row[colsOfInterest[i]] << "     ";
            }
           
            cout << endl;
        }
    }

cout<<"Cantidad de casos cuidados intensivos para joaquin: "<<cont<<endl;
}





int main(int argc, char **argv)
{

        if(strcmp(argv[1], "[") == 0){
        if(strcmp(argv[2], "estad") == 0){
            estad();
        }
        else if(strcmp(argv[2], "p_casos") == 0){
            if(strcmp(argv[3], "]") == 0){
            p_casos(argv[4]);
              
            }
            else{
              p_casos(argv[3],argv[5]);
               
            }
        }
        else if(strcmp(argv[2], "p_muertes")==0)
        {
           
                if(strcmp(argv[3], "]") == 0){
           p_muertes(argv[4]);
            }
            else{
                
                p_muertes(argv[3],argv[5]);
            }
        }
        else if(strcmp(argv[2], "casos_edad")==0)
        {
                if(strcmp(argv[3], "]") == 0){
           throw 400;
            }
            else{
                casos_edad(argv[3]);
            }
        }

          else if(strcmp(argv[2], "casos_cui")==0)
        {
                if(strcmp(argv[3], "]") == 0){
                    
               casos_cui(argv[4]);
            }
            else{
            
                casos_cui(argv[3],argv[5]);
            }
        }
        
    }
    return 0;
}

