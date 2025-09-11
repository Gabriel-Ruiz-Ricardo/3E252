#pragma once
#include <EstadoFoco.hpp>

class Foco
{
private:
    EstadoFoco estado;

public:

    Foco()  //Constructor
    {
        estado = false;
    }   

    ~Foco() {}  //Destructor

    void Encender()
    {   //Codigo en paradigma estructurado
        estado = true;
    }

    void Apagar()
    {
        estado = false;
    }

    EstadoFoco MostrarEstado()
    {
        return estado;
    }
};