#include "PizzaBuilder.h"
#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    try {
        PizzaBuilder builder;

        builder.BuildPizza();
        builder.DisplayFinalPizza();

    } catch (const std::exception& ex) {
        std::cerr << "Error fatal: " << ex.what() << std::endl;
        return 1;
    }

    std::cout << "\nPresiona Enter para continuar...";
    std::cin.get();
    return 0;
}