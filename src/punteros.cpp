#include <iostream>

int main(int argc, char const *argv[])
{
    int *pNumero = NULL;
    pNumero = new int;
    *pNumero = 25;

    std::cout <<"Direccion: " << pNumero << '\n';
    std::cout <<"Valor: " << *pNumero << '\n';
    std::cout <<"Tamaño: " << sizeof(pNumero) << '\n';
    return 0;
}