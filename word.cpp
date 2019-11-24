#include <iostream>
#include <fstream>
#include <string>
#include "word.h"
#include <sstream>
#include <vector>

using namespace std;

/* Este es el constructor, que al inicializar los objetos
llena la matriz de caracteres con los datos del texto
 */

Word::Word(){
    ifstream archivo;
    char caracter;
    string nomArch;
    cout<<"Digite el nombre del archivo de donde desea leer: ";
    cin>>nomArch;
    archivo.open(nomArch,ios::in);
    if(!archivo){
        cout<<"No se puede abrir el archivo";
    } else {
        //aqui llenaremos el vector palabras
        string palabra, linea;
        int max = 0;
        while(getline(archivo, linea)){
            stringstream linea2(linea);
            while(linea2 >> palabra){
                if (palabra.length() > max){
                    max = palabra.length();
                }
                palabras.push_back(palabra);
            }
        }
        archivo.close();
        //aqui empieza la lectura por caracteres
        bool correcto = false;
        while (!correcto){
            cout << "Digite la longitud de cada linea del archivo" <<
                 " (debe ser al menos "<< max <<"): ";
            cin >> size;
            if (size >= max){
                correcto = true;
            }
        }
        //comenzamos a leer el archivo y guardarlo en la matriz
        vector<char> line;
        int cont = 0;
        archivo.open(nomArch,ios::in);
        while(archivo >> noskipws >> caracter){
            //checkeamos que no sea salto de linea y escribimos en la matriz
            //caso contrario, saltamos de linea.
            if (caracter != '\n' && cont<size){
                line.push_back(caracter);
                cont++;
            } else{
                texto.push_back(line);
                line.clear();
                cont = 0;
            }
        }
        archivo.close();
        cout << "Cargado correctamente" << endl;
    }
    encript = false;
    aligned = false;
}

//a partir de aqui vienen los setters y getters

vector<string> Word::getPalabras(){
    return palabras;
}

int Word::getSize() const {
    return size;
}

void Word::setSize(int size) {
    Word::size = size;
}

bool Word::isEncript() const {
    return encript;
}

void Word::setEncript(bool encript) {
    Word::encript = encript;
}

const vector<vector<char>> &Word::getTexto() const {
    return texto;
}

bool Word::isAligned() const {
    return aligned;
}

void Word::setAligned(bool aligned) {
    Word::aligned = aligned;
}

//a partir de aqui empieza la definicion de los metodos

void Word::justificar(){

}

void Word::alinearDerecha(){

}

void Word::alinearIzquierda(){

}

void Word::alinearCentro(){

}

void Word::findWord(string palabra){
    int cont = 0;
    bool encontrado = false;
    for (auto i: palabras){
        if (i == palabra){
            encontrado = true;
            cout << "Se encontro la palabra en la posicion " << cont << endl;
        }
        cont++;
    }
    if (!encontrado)
        cout << "No se encontro la palabra en el texto" << endl;
}

void Word::reemplazar(string palabra, string palabra2){
    bool encontrado = false;
    for (int i =0; i<palabras.size(); i++){
        if (palabras[i]==palabra){
            encontrado = true;
            palabras[i] = palabra2;
        }
    }
    if (!encontrado)
        cout << "No se encontro la palabra a reemplazar en el texto" << endl;
    else
        cout << "Se reemplazaron todas las ocurrencias" << endl;
}

int Word::contarPalabra(string palabra){
    int cont=0;
    for (int i = 0; i<palabras.size(); i++){
        if (palabras[i] == palabra){
            cont++;
        }
    }
    return cont;
}

void Word::encriptar(){

}

void Word::desencriptar(){

}
