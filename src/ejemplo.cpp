#include <iostream>
#include <ftxui/screen/screen.hpp>
#include <thread>
#include <chrono>
#include <string>

#include <Dibujo.hpp>

using namespace std;
using namespace ftxui;

int main(int arg, char const *argv[])
{
    Screen pantalla = Screen::Create(
        Dimension::Full(),
        Dimension::Fixed(10)
    );

    Dibujo nave (Color::Green1, Color::Black, 
    {
        string("      ___       "),
        string("  ___/   \\___   "),
        string(" /   '---'   \\  "),
        string(" '--_______--'  ")          
    });

    Dibujo vaca ({
        string("         (__) "),     
        string(" `-------(oo) "),     
        string("   ||    (__) "),     
        string("   ||w--||    "),
    });

    int contador = 0;
    while(true)
    {
        vaca.MoverDerecha();
        if (contador%5 == 0) nave.MoverDerecha();
        nave.Imprimir(pantalla);
        vaca.Imprimir(pantalla);
        pantalla.Print();

        this_thread::sleep_for(chrono::milliseconds(100));

        pantalla.Clear();
        cout << pantalla.ResetPosition();
        contador++;
    }
    return 0;
}