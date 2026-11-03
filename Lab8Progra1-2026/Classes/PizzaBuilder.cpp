#include "PizzaBuilder.h"
#include <cstdlib>
#include <iostream>
#include <string>

PizzaBuilder::PizzaBuilder() {
}

void PizzaBuilder::WaitForEnterAndClear() {
    std::cout << "\nPresiona Enter para continuar...";
    std::string line;
    std::getline(std::cin, line);
    system("cls");
}

bool PizzaBuilder::QuiereSeguirAgregandoTomate() {
    while (true) {
        std::cout << "\n¿Quieres seguir agregando tomate?" << std::endl;
        std::cout << "1. Sí" << std::endl;
        std::cout << "2. No, pasar al siguiente ingrediente" << std::endl;
        std::cout << "Elige una opción: ";

        std::string opcion;
        std::getline(std::cin, opcion);

        if (opcion == "1") {
            return true;
        }
        if (opcion == "2") {
            return false;
        }

        std::cout << "Opción no válida. Escribe 1 o 2." << std::endl;
    }
}

void PizzaBuilder::BuildPizza() {
    std::cout << "=== Constructor de pizza ===" << std::endl;
    std::cout << "¡Vamos a armar tu pizza!" << std::endl;

    SelectTomatoes();
    IrAlSiguienteIngrediente();
    WaitForEnterAndClear();
}

void PizzaBuilder::IrAlSiguienteIngrediente() {
    // 2 = queso, 3 = carnes, 4 = hierbas.
    // Hoy ningún miembro ha conectado el suyo, así que cae en default.
    int siguiente = 2;

    switch (siguiente) {
    case 2:
        // TODO queso: descomenta SelectCheese(). No pongas break:
        // así el switch sigue hasta el default mientras no haya más ingredientes.
        // SelectCheese();
    case 3:
        // TODO carnes: descomenta SelectMeat(). No pongas break todavía.
        // SelectMeat();
    case 4:
        // TODO hierbas: descomenta SelectHerb(). No pongas break todavía.
        // SelectHerb();
    default:
        std::cout << "No existen más ingredientes para tu pizza." << std::endl;
        break;
    }
}

void PizzaBuilder::MostrarGrupo(const std::string& nombre, const std::vector<std::string>& ingredientes) const {
    std::cout << nombre << " (" << ingredientes.size() << "):" << std::endl;
    if (ingredientes.empty()) {
        std::cout << "- Ninguno" << std::endl;
        return;
    }

    for (const auto& ingrediente : ingredientes) {
        std::cout << "- " << ingrediente << std::endl;
    }
}

int PizzaBuilder::ContarTiposAgregados() const {
    int tipos = 0;
    if (!selectedTomatoes_.empty()) {
        ++tipos;
    }
    if (!selectedCheeses_.empty()) {
        ++tipos;
    }
    if (!selectedMeats_.empty()) {
        ++tipos;
    }
    if (!selectedHerbs_.empty()) {
        ++tipos;
    }
    return tipos;
}

void PizzaBuilder::DisplayFinalPizza() const {
    std::cout << "Tu pizza tiene los siguientes ingredientes:" << std::endl;
    std::cout << std::endl;
    MostrarGrupo("Tomates", selectedTomatoes_);
    MostrarGrupo("Queso", selectedCheeses_);
    MostrarGrupo("Carnes", selectedMeats_);
    MostrarGrupo("Hierbas", selectedHerbs_);

    std::cout << std::endl;
    switch (ContarTiposAgregados()) {
    case 0:
        std::cout << "No agregaste ingredientes a tu pizza." << std::endl;
        break;
    case 1:
        if (!selectedTomatoes_.empty()) {
            std::cout << "Tu pizza solo tiene tomate." << std::endl;
        } else {
            std::cout << "Tu pizza tiene un solo tipo de ingrediente." << std::endl;
        }
        break;
    case 2:
        std::cout << "Tu pizza ya tiene un segundo ingrediente." << std::endl;
        break;
    case 3:
        std::cout << "Tu pizza ya tiene un tercer ingrediente." << std::endl;
        break;
    default:
        std::cout << "Tu pizza ya tiene los cuatro ingredientes." << std::endl;
        break;
    }

    std::cout << "¡Buen provecho!" << std::endl;
}

void PizzaBuilder::SelectTomatoes() {
    // TODO: Reusar esta linea, pero con su propio Repositorio.
    IngredientSelector<TomatoesRepository> selector(tomatoRepo_, availableTomatoes_, "tomate");
    bool yaPregunto = false;

    while (true) {
        std::cout << "\n--- Selección de tomates ---" << std::endl;
        selector.DisplayAvailableIngredients();

        std::cout << "\nIngresa el tipo de tomate (o 'listo' para terminar): ";
        std::string userChoice;
        std::getline(std::cin, userChoice);

        if (userChoice == "listo" || userChoice == "LISTO") {
            system("cls");
            break;
        }

        bool exitosa = selector.AddIngredientToPizza(userChoice, selectedTomatoes_);
        if (exitosa) {
            std::cout << "La selección fue exitosa." << std::endl;
        } else {
            std::cout << "La selección no fue exitosa." << std::endl;
        }

        if (exitosa && !yaPregunto) {
            yaPregunto = true;
            if (!QuiereSeguirAgregandoTomate()) {
                system("cls");
                return;
            }
        }

        WaitForEnterAndClear();
    }
}

// TODO:  Crear cada uno su parte. ☝️ toma el ejemplo de  SelectTomatoes y crea tu propia implementación.
// Guarda lo elegido en selectedCheeses_, selectedMeats_ o selectedHerbs_.
// En IrAlSiguienteIngrediente, descomenta la llamada de tu case.


//void PizzaBuilder::SelectCheese() {
// // Resolver.
//}
//
//void PizzaBuilder::SelectHerb() {
//    // Resolver.
//}
//
//void PizzaBuilder::SelectMeat() {
//    // Resolver.
//}
