#include <Foco.hpp>
#include <SerieNavidad.hpp>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    SerieNavidad miSerieNavidad;
    miSerieNavidad.Encender();
    miSerieNavidad.ImprimirSerie();
    miSerieNavidad.Apagar();
    miSerieNavidad.ImprimirSerie();

    Foco foco;
    foco.Apagar();
    foco.Encender();

    cout
    <<"Foco: "
    <<foco.MostrarEstado()
    <<endl;
    return 0;
}