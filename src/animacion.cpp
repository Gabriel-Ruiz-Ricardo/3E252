#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
using namespace ftxui;

int main()
{
    // Crear la ventana
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));

    // Agregar código de los elementos de la granja
    const std::vector<std::u32string> tierra = {
    U"       _____       ",
    U"    .-'.  ':'-.    ",
    U"  .''::: .:    '.  ",
    U" /   :::::'      \\ ",
    U";.    ':' `       ;",
    U"|       '..       |",
    U"; '      ::::.    ;",
    U" \\       '::::   / ",
    U"  '.      :::  .'  ",
    U"     '-.___'_.-'   "
    };

    const std::vector<std::u32string> planeta = {
    UR"(.-.,="``"=.    )",
    UR"('=/_       \\   )",
    UR"( |  '=._    |  )",
    UR"(  \\     `=./`, )",
    UR"(   '=.__.=' `=')"
    };

    const std::vector<std::u32string> luna = {
    U"  _.._    ",
    U" .' .-'`  ",
    U"/  /      ",
    U"|  |      ",
    U"\\  '.___.;",
    U" '._  _.' ",
    U"    ``    "
    };

    const std::vector<std::u32string> estrella = {
    U"  |  ",
    U"- o -",
    U"  |  "
    };
    const std::vector<std::u32string> estrellapeque = {
    U"*"
    };

    const std::vector<std::u32string> cohete = {
    U"  .  ",
    U" .'. ",
    U" |o| ",
    U".'o'.",
    U"|.-.|",
    U"'   '",
    U" ( ) ",
    U"  )  ",
    U" ( ) "
    };

    GestorDibujos gestor;
    gestor.Agregar(Dibujo(20, 7, tierra, ftxui::Color::Blue));

    gestor.Agregar(Dibujo(1, 1, planeta, ftxui::Color::Red));
    gestor.Agregar(Dibujo(45, 11, planeta, ftxui::Color::Magenta1));

    gestor.Agregar(Dibujo(4, 14, cohete, ftxui::Color::Green));

    gestor.Agregar(Dibujo(40, 1, luna, ftxui::Color::Magenta));

    gestor.Agregar(Dibujo(20, 2, estrella, ftxui::Color::Yellow));
    gestor.Agregar(Dibujo(55, 6, estrella, ftxui::Color::Yellow));
    gestor.Agregar(Dibujo(15, 15, estrella, ftxui::Color::Yellow));
    gestor.Agregar(Dibujo(40, 17, estrella, ftxui::Color::Yellow));
    
   
    gestor.Agregar(Dibujo(55, 3, estrellapeque, ftxui::Color::White));
    gestor.Agregar(Dibujo(35, 6, estrellapeque, ftxui::Color::White));
    gestor.Agregar(Dibujo(15, 8, estrellapeque, ftxui::Color::White));
    gestor.Agregar(Dibujo(13, 12, estrellapeque, ftxui::Color::White));
    gestor.Agregar(Dibujo(39, 16, estrellapeque, ftxui::Color::White));
    
    

    int frames = 120;
    for (int frame = 0; frame < frames; ++frame)
    {
        // Limpia la pantalla
        screen.Clear();

        // Animación:
        gestor.dibujos[1].x = 1 - (frame % 2);
        gestor.dibujos[2].y = 11 - (frame % 2);

        gestor.dibujos[3].y = 14 - (frame % 9);

        gestor.dibujos[4].x = 40 - (frame % 9);

        gestor.dibujos[5].x = 20 - (frame % 2);
        gestor.dibujos[6].x = 55 - (frame % 2);
        gestor.dibujos[7].x = 15 - (frame % 2);
        gestor.dibujos[8].x = 40 - (frame % 2);
        gestor.dibujos[5].y = 2 - (frame % 2);
        gestor.dibujos[6].y = 6 - (frame % 2);
        gestor.dibujos[7].y = 15 - (frame % 2);
        gestor.dibujos[8].y = 17 - (frame % 2);

        gestor.dibujos[9].x = 55 - (frame % 6);
        gestor.dibujos[10].x = 35 - (frame % 9);
        gestor.dibujos[11].x = 15 + (frame % 5);
        gestor.dibujos[12].y = 12 - (frame % 5);
        gestor.dibujos[13].x = 39 + (frame % 5);

        gestor.DibujarTodos(screen);

        // Imprime la pantalla y resetea el cursor
        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }
    return 0;
}