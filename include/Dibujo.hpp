#pragma once
#include <string>
#include <list>
using namespace std;

#include <ftxui/screen/screen.hpp>
using namespace ftxui;

class Dibujo
{
private:
    list<string> dibujo;
    int x = 0;
    int y = 0;
    Color fondo;
    Color color;

public:
    Dibujo(list<string> dibujo)
    {
            this->dibujo = dibujo;
    }

    Dibujo(Color color, Color fondo, 
        list<string> dibujo)
    {
        this->dibujo = dibujo;
        this->color = color;
        this->dibujo = dibujo;
    }


    void Imprimir(Screen& pantalla)
    {
        int fila = 0;
        for (auto &linea : dibujo)
        {
            int columna = 0;
            for (auto &letra : linea)
            {
                Pixel &pixel = pantalla.PixelAt(
                    x + columna, 
                    y + fila
                );
                pixel.character = letra;
                pixel.background_color = fondo;
                pixel.foreground_color = color;
                columna++;
            }
            fila++;
        }
    }

    void MoverDerecha()
    {
        x++;
    }

    void MoverIzquierda()
    {
        x--;
    }

    void MoverAbajo()
    {
        y++;
    }

    void MoverArriba()
    {
        y--;
    }
};