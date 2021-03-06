#ifndef U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include "ArbolBinarioAVL.h"     //Libreria utilizada en casos_cui
#include "ArbolBinarioAVLEdad.h" //libreria utilizada en casos_edad
#include <ctime>
#define U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#endif

using namespace std;
/**
 * Transforma un string a un int pero tomando en cuenta solo los caracteres que sean numericos, en este caso se usas para las fechas en casos_cui 
 * @param fechaString variable en formato string
 * @return variable en formato int solo con caracteres numericos
 */
int stringToint(string fechaString)
{

    int j = 0, num = 0;
    string fecha_;
    int n = fechaString.size();
    for (int i = 0; i < n; i++)
    {
        int x = fechaString[i];
        if (x >= 48 && x <= 57) //Se utiliza tabla ascii para filtrar datos
        {
            fecha_[j] = fechaString[i];
            j++;
        }
    }

    return stoi(fecha_);
}

/**
 * Mismo funcionamiento que "StringToint" solo que con un funcionamiento adicional.
 * @param fechaString variable en formato string
 * @return variable en formato int solo con caracteres numericos
 */
int stringToint_control(string fechaString)
{
    int j = 0, num = 0;
    string fecha_;
    int n = fechaString.size();
    for (int i = 0; i < n; i++)
    {
        int x = fechaString[i];
        if (x >= 48 && x <= 57)
        {
            fecha_[j] = fechaString[i];
            j++;
        }
        else if (x != 45)
        {
            cout << "\nParametro ingresado despues de '-casos_cui' invalido. \nPruebe una fecha con formato: YYYY-MM-DD o vacio." << endl;
            exit(1);
        }
    }

    return stoi(fecha_);
}

/**
 * Controla si el dato ingresado como string es un numero.
 * @param str string a controlar.
 * @return falso en caso de que no sea un numero, verdadero si si lo es.
 */
bool controlNum(string str)
{
    int x;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        x = str[i];
        if (x < 48 || x > 57)
        {
            return false;
        }
    }
    return true;
}

/**
 * Ordena un array de listas, utilizado en p_casos y p_muertes.
 * @param arr arreglo de listas.
 * @param first la posicion que se inicia el ordenamiento.
 * @param last la posicion donde finaliza el ordenamiento.
 */
void quickSortProvincias(vector<string> arr[], int first, int last)
{
    int i, j, middle;
    vector<string> pivot, aux;

    middle = (first + last) / 2;
    pivot = arr[middle];
    i = first;
    j = last;

    do
    {
        while (stoi(arr[i][1]) > stoi(pivot[1])) // se tiene en cuenta la primera posicion de las listas que es el nombre de la provincias
            i++;
        while (stoi(arr[j][1]) < stoi(pivot[1])) //Se utiliza stoi para que se pueda comparar los nombres de las provincias, teniendo en cuenta la tabla ascii
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
        quickSortProvincias(arr, first, j);
    if (i < last)
        quickSortProvincias(arr, i, last);
}

/**
 * Muestra informacion estadistica de los datos de Covid-19.
 * @param fileName Nombre del archivo
 */
void estad(string fileName)
{
   cout << "\n\n////////////////////////////////////////////////////" << endl;
    cout << "Ejecutando estad" << endl;
    cout << "////////////////////////////////////////////////////\n"
         << endl;
    int totalcasos = -1;
    int contagiados = 0;
    int fallecidos = 0;
    long double EdadConfirmado[100]; //arrays que permiten guardar la cantidad de casos segun rango etario
    long double EdadFallecido[100];
    float porcentajefall, porcentajecont;
    int a = 0, b = 0;

    for (int j = 0; j <= 10; j++) //se igualan a cero las posiciones del array
    {
        EdadConfirmado[j] = 0;
        EdadFallecido[j] = 0;
    }

    fstream fin;
    fin.open("./" + fileName, ios::in);

    if (!fin.fail())
    {

        vector<string> row;
        string line, word;

        while (getline(fin, line)) // corre todas las filas
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
            totalcasos++; //aumento constantemente el contador de los casos+

            if (controlNum(row[2])) //si los datosd e la columna dos no son "NA" ni "edad", entra a la funcion
            {
                a = stoi(row[2]); //convierto la edad que viene como string, a variable entera int

                if (row[20].compare("Confirmado") == 0)
                {
                    contagiados++; // se aumentan los contagiados si la comparacion del if es true
                    if (row[3].compare("Meses") == 0)
                    {
                        EdadConfirmado[0]++; // en la posicion 0 se guardan los casos de meses o 1 a 9 a??os
                    }
                    else
                    {
                        EdadConfirmado[a / 10]++; // divido la edad obtenida en 10, para que se guarde en la posicion del valor entero
                    }                             // ejemplo: edad 54 a??os. 54/10=5.4 --> como es variable entera solo va a considerar el 5
                                                  //siguiendo esa logica, todas las edades entre 50 y 59 se guardaran en la posicion 5.
                }
                if (row[14].compare("SI") == 0)
                {
                    fallecidos++;
                    if (row[3].compare("Meses") == 0)
                    {
                        EdadFallecido[0]++; // mismo procedimiento que para contagiados, pero en el array de fallecidos
                    }
                    else
                    {
                        EdadFallecido[a / 10]++; // mismo procedimiento que para contagiados, pero en el array de fallecidos
                    }
                }
            }
        }
        porcentajefall = ((fallecidos * 100) / contagiados); //se calculan los porcentajes totales
        porcentajecont = ((contagiados * 100) / totalcasos); //se calculan los porcentajes totales

        cout << "\nCantidad total de muestras: " << totalcasos << endl;
        cout << "\nCantidad total de contagiados: " << contagiados << endl;
        cout << "\nCantidad total de fallecidos: " << fallecidos << endl;
        cout << "\nPorcentaje de Contagiados: " << porcentajecont << "%" << endl;
        cout << "\nPorcentaje de Fallecidos respecto de Contagiados: " << porcentajefall << "%" << endl;
        cout << "\nLa cantidad de Contagiados segun rango etario:" << endl;
        for (int i = 0; i <= 10; i++)
        {
            cout << "Entre " << i * 10 << " y " << (i * 10) + 9 << " anios es: " << EdadConfirmado[i] << endl;
        }
        cout << "\nLa cantidad de Fallecidos segun rango etario:" << endl;
        for (int i = 0; i < 11; i++)
        {
            cout << "Entre " << i * 10 << " y " << (i * 10) + 9 << " anios es: " << EdadFallecido[i] << endl;
        }
    }
    else
    {
        cout << "Error al abrir el archivo" << endl; // si no entra en el if, devuelve error
        exit(1);
    }
}

/**
 * Muestra n primeras provincias con mas muertes por Covid-19 en
   orden descendente si el parametro es mandado, si no se mostrar?? todo.
 * @param prov Cantidad de provincias ingresado por usuario.
 * @param fileName Nombre del archivo.
 */
void p_muertes(string prov, string fileName)
{
    cout << "\n\n////////////////////////////////////////////////////" << endl;
    cout << "Ejecutando p_muertes" << endl;
    cout << "////////////////////////////////////////////////////\n"
         << endl;

    if (fileName == "") //Si se ejecuta la funcion sin enviar parametros
    {
        fileName = prov;
        prov = "25";  //Se considera 25 por todas las provincias.
    }

    if (!controlNum(prov))  //Control de que el parametro sea un numero.
    {
        cout << "Solo se permiten numeros enteros para la funcion\n"
             << endl;
        exit(1);
    }

    int val = stoi(prov);  //Conversion de string a int.

    if (val > 25 || val <= 0) //Si el valor ingresado supera la cantidad de provinicias, se cambia a 25.
    {
        cout << "Solo hay 25 posibles provincias, se cambiar?? a este valor\n"
             << endl;
        val = 25;
    }

    fstream fin;
    fin.open("./" + fileName, ios::in);


    if (!fin.fail())  //Se controla si hay problemas con el archivo
    {

    vector<string> arr[25]; //Se crea array de 25 posiciones que acepta listas.

    vector<string> row;
    string line, word;

    int Cont_Provincias[25];
    string Provincias[] = {"SIN ESPECIFICAR", "CABA", "Buenos Aires", "Catamarca", "Chaco", "Chubut", "C??rdoba", "Corrientes", "Entre R??os", "Formosa", "La Pampa", "La Rioja", "Mendoza", "Neuqu??n", "R??o Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra del Fuego", "Tucum??n", "Jujuy", "Misiones"};

    for (int i = 0; i < 25; i++)  
    {
        arr[i].push_back(Provincias[i]); //Se cargan los nombres de las provincias a su respectiva lista.
    }

    for (int i = 0; i < 25; i++)  //Se le asigna valor 0 a toda las posiciones del array.
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

        for (int i = 0; i < 25; i++)  //For para recorrer las posiciones del array int.
        {
            if (row[7] == Provincias[i]) //Si la provincia de la tabla es igual a la provincia en la posicion del array
            {
                if (row[14] == "SI") //Si fallecio
                {
                    Cont_Provincias[i]++; //Se suma 1 en la misma posicion del array int
                }
            }
        }
    }

    for (int i = 0; i < 25; i++) 
    {
        arr[i].push_back(to_string(Cont_Provincias[i])); //Se agrega la cantidad de muertos, convertido a string, de cada provincia a su respectiva lista.
    }

    quickSortProvincias(arr, 0, 24); //Ordenamiento de del array que contiene las listas.

    for (int i = 0; i < val; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << "  ";  //Se muestran los datos: provinicia y cantidad de muertos.
        }
        cout << endl;
    }
    }
    else{
        cout<<"Error al abrir el archivo"<<endl;
        exit(1);
    }
}

/**
 * Muestra n primeras provincias con mas contagiados de Covid-19 en 
   orden descendente si el parametro es mandado, si no se mostrar?? todo.
 * @param prov Cantidad de provincias ingresado por usuario.
 * @param fileName Nombre del archivo.
 */
void p_casos(string prov, string fileName)
{
    cout << "\n\n////////////////////////////////////////////////////" << endl;
    cout << "Ejecutando p_casos" << endl;
    cout << "////////////////////////////////////////////////////\n"
         << endl;

    if (fileName == "") //Si se ejecuta la funcion sin enviar parametros
    {
        fileName = prov;
        prov = "25"; //Se considera 25 por todas las provincias.
    }

    if (!controlNum(prov))  //Control de que el parametro sea un numero.
    {
        cout << "Solo se permiten numeros enteros para la funcion\n"
             << endl;
        exit(1);
    }

    int val = stoi(prov);  //Conversion de string a int.

    if (val > 25 || val <= 0)  //Si el valor ingresado supera la cantidad de provinicias, se cambia a 25.
    {
        cout << "Solo hay 25 posibles provincias, se cambiar?? a este valor\n"
             << endl;
        val = 25;
    }

    fstream fin;
    fin.open("./" + fileName, ios::in);

    
    if (!fin.fail())  //Se controla si hay problemas con el archivo
    {
    vector<string> arr[25];

    vector<string> row;
    string line, word;

    int Cont_Provincias[25];
    string Provincias[] = {"SIN ESPECIFICAR", "CABA", "Buenos Aires", "Catamarca", "Chaco", "Chubut", "C??rdoba", "Corrientes", "Entre R??os", "Formosa", "La Pampa", "La Rioja", "Mendoza", "Neuqu??n", "R??o Negro", "Salta", "San Juan", "San Luis", "Santa Cruz", "Santa Fe", "Santiago del Estero", "Tierra del Fuego", "Tucum??n", "Jujuy", "Misiones"};

    for (int i = 0; i < 25; i++)  
    {
        arr[i].push_back(Provincias[i]); //Se cargan los nombres de las provincias a su respectiva lista.
    }

    for (int i = 0; i < 25; i++)  //Se le asigna valor 0 a toda las posiciones del array.
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

        for (int i = 0; i < 25; i++)  //For para recorrer las posiciones del array int.
        {
            if (row[7] == Provincias[i])  //Si la provincia de la tabla es igual a la provincia en la posicion del array
            {
                Cont_Provincias[i]++; //Se suma 1 en la misma posicion del array int
            }
        }
    }

    for (int i = 0; i < 25; i++) 
    {
        arr[i].push_back(to_string(Cont_Provincias[i])); //Se agrega la cantidad de casos, convertido a string, de cada provincia a su repsectiva lista.
    }

    quickSortProvincias(arr, 0, 24); //Ordenamiento de del array que contiene las listas.

    for (int i = 0; i < val; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << "  "; //Se muestran los datos: provinicia y cantidad de casos.
        }
        cout << endl;
    }
    }
    else{
        cout<<"Problemas al abrir el archivo"<<endl;
        exit(1);
    }
}

/**
 * Muestra la cantidad de casos Covid-19 de una edad indicada.
 * @param edad_ La edad ingresada por el usuario en formato string
 * @param fileName Nombre del archivo
 */
void casos_edad(string edad_, string fileName)
{
     cout << "\n\n////////////////////////////////////////////////////" << endl;
    cout << "Ejecutando casos_edad" << endl;
    cout << "////////////////////////////////////////////////////\n"
         << endl;
    if (controlNum(edad_))
    { // se controla que lo ingresado sean numeros, para evitar errores

        int edad = stoi(edad_); //Se pasa la edad a formato int

        int cont = 0;      
        string edadString; //Variable donde se guardaran las edades de los casos, se utiliza para evitar repetir row[2]
        string mesoanio;   // Variable que guarda si es un mes o un anio
        fstream fin;
        fin.open("./" + fileName, ios::in);

        
    if (!fin.fail()) //Controla si hubo algun problema con el archivo
    {
        vector<string> row; //Se almacenaran cada columna del archivo por fila en el
        string line, word;

        ArbolBinarioAVLEdad<vector<string>> arbol; //Un arbol avl que admite listas como dato(para poder poner cada fila del archivo en un nodo)

        int colsOfInterest[] = {0, 2, 3, 12, 13, 14, 17, 20}; //Columnas de interes del archivo
        int nColumns = sizeof(colsOfInterest) / sizeof(colsOfInterest[0]);

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
                else
                {
                    word = "NA"; //Token para evitar lugares vacios
                }
                row.push_back(word); // Se ordena todos los datos de una fila en una lista
            }

            edadString = row[2]; //se asigna la edad de los casos para evitar repetir row[2]
            mesoanio = row[3];   //se asigna si el valor es mes o anio para evitar repetir row[3]
            if (controlNum(edadString))
            {

                if (mesoanio.compare("A??os") == 0)
                { //Se controla si el caso tiene anios o meses

                    if (stoi(edadString) == edad)//Se filtra los casos con la edad ingresada
                    {                   
                        arbol.put(row); // se ingresan las lineas en el arbol
                        cont++;
                    }
                }

                else if (edad == 0)
                {                   //Si se ingreso la edad 0 se muestran los casos con meses
                    arbol.put(row); // se ingresan las lineas en el arbol
                    cont++;
                }
            }
        }

        arbol.inorder(); //Se muestra las filas en orden tomando en cuenta el id de la provincias (Manejado en ArbolBinarioAVLEdad.h)

        if (edad == 0)
        {
            cout << "Cantidad de casos con ninios menores a un anio: " << cont << endl;
        }
        else
        {
            cout << "Cantidad de casos con " << edad << ": " << cont << endl;
        }
    }
    else{
    cout<<"Problemas al abrir el archivo"<<endl;
    exit(1);
    }
    }
    else
    {
        cout << "Edad ingresada no es correcta" << endl;
    }
}

/**
 * Mostrar?? los datos de los casos que estuvieron en cuidados
   intensivos ordenados por fecha de cuidados intensivos, si fecha est?? indicada, 
   se mostrar??n solo las fechas mayores a esta.
 * @param fechaString Fecha ingresada por usuario.
 * @param fileName Nombre del archivo.
 */
void casos_cui(string fechaString, string fileName)
{
       cout << "\n\n////////////////////////////////////////////////////" << endl;
    cout << "Ejecutando casos_cui" << endl;
    cout << "////////////////////////////////////////////////////\n"
         << endl;
    int fechaNum;

    if (fileName == "") //Si se ejecuta la funcion sin enviar parametros
    {
        fileName = fechaString;
        fechaNum = stringToint("1");//Se elige el 1 como un numero muy chico
        fechaString = "Sin Especificar";
    }
    else
    {
        fechaNum = stringToint_control(fechaString);//Se realiza la asignacion con un control extra
    }

    fstream fin;
    fin.open("./" + fileName, ios::in);

    if (!fin.fail()) //Se controla si hay problemas con el archivo
    {
        vector<string> row;
        string line, word;

        int total = -1;
        int cont = 0;
        int fechaPos = 0;

        ArbolBinarioAVL<vector<string>> arbol; //El arbolAVL admite listas
        while (getline(fin, line)) 
        {
            total++;
            row.clear();
            stringstream s(line);
            while (getline(s, word, ',')) 
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

            if (row[12].compare("SI") == 0)//Si el caso estuvo en cuidados intensivos
            {
                fechaPos = stringToint(row[13]);//Se asigna la fecha en la que estuvo en cuidados intensivos

                if (fechaNum < fechaPos)//Se filtra para trabajar las fechas mayores a la ingresada
                {
                    arbol.put(row);
                    cont++;
                }
            }
        }

        arbol.inorder();//se muestran las listas en orden

    if(fechaString=="Sin Especificar"){ //cuando no se ingreso parametros
        cout << "Cantidad de casos cuidados intensivos: " << cont << endl;
    }
    else{//cuando tiene parametros
cout << "Cantidad de casos cuidados intensivos despues de la fecha " << fechaString << ": " << cont << endl;
    }
    }
    else{
        cout << "Problemas con el archivo" << endl;
        exit(1);
    }
}

/**
 * Muestra mensajes de error en caso de un mal ingreso en la sintaxis de los argumentos.
 */
void Error(){
            cout << "Error en la sintaxis" << endl;
            cout << "Ejemplos de uso: " << endl;
            cout << "    covid19.exe -estad Covid19Casos.csv " << endl;
            cout << "    covid19.exe -p_casos 5 Covid19Casos.csv " << endl;
            cout << "    covid19.exe -p_casos Covid19Casos.csv" << endl;
            exit(1);
}

/**
 * Encargado de recibir argumentos y llamar a las funciones.
 * @param argc Tama??o de argumento.
 * @param argv Argumentos.
 */
int main(int argc, char **argv)
{

    clock_t begin;
    begin = clock();

    if (argc == 3)
    {
        if (strcmp(argv[1], "-casos_cui") == 0)
        {
            casos_cui(argv[2], "");
        }
        else if (strcmp(argv[1], "-p_casos") == 0)
        {
            p_casos(argv[2], "");
        }
        else if (strcmp(argv[1], "-p_muertes") == 0)
        {
            p_muertes(argv[2], "");
        }

       else if (strcmp(argv[1], "-estad") == 0)
        {
            estad(argv[2]);
        }
        else
        {
            Error();
        }
    }
    else if (argc == 4)
    {

        if (strcmp(argv[1], "-p_casos") == 0)
        {

            p_casos(argv[2], argv[3]);
        }
        else if (strcmp(argv[1], "-p_muertes") == 0)
        {
            p_muertes(argv[2], argv[3]);
        }
        else if (strcmp(argv[1], "-casos_edad") == 0)
        {

            casos_edad(argv[2], argv[3]);
        }

        else if (strcmp(argv[1], "-casos_cui") == 0)
        {
            casos_cui(argv[2], argv[3]);
        }
        else
        {
            Error();
        }
    } else
    {
        Error();
    }

    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout << "Tardo elapsed_secs: " << elapsed_secs << "\n"
         << endl;
    return 0;
}
