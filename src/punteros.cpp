#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int *pNumero = NULL;
    pNumero = new int;
    *pNumero = 25;

    cout <<"Direccion: " << pNumero << '\n';
    cout <<"Valor: " << *pNumero << '\n';
    cout <<"Tamaño: " << sizeof(pNumero) << '\n';

    cout<< "Tipos de datos: " << endl;

    cout<< "Tamaño int : " << sizeof(int) << endl;
    cout<< "Tamaño long : " << sizeof(long) << endl;
    cout<< "Tamaño float : " << sizeof(float) << endl;
    cout<< "Tamaño double : " << sizeof(double) << endl;
    cout<< "Tamaño char : " << sizeof(char) << endl;
    cout<< "Tamaño bool : " << sizeof(bool) << endl;
    cout<< "Tamaño byte : " << sizeof(byte) << endl;
    return 0;
}