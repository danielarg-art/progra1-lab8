#pragma once
#include <vector>
#include <string>
#include "TomatoesRepository.h"
#include "IngredientSelector.h"

class PizzaBuilder {
public:
    PizzaBuilder();

    void BuildPizza();
    void DisplayFinalPizza() const;

private:
    void WaitForEnterAndClear();
    bool QuiereSeguirAgregandoTomate();
    void SelectTomatoes();
    void IrAlSiguienteIngrediente();
    void SelectCheese();
    void SelectHerb();
    void SelectMeat();
    void MostrarGrupo(const std::string& nombre, const std::vector<std::string>& ingredientes) const;
    int ContarTiposAgregados() const;

    TomatoesRepository tomatoRepo_;

    // Cada miembro llena su lista desde su método Select.
    std::vector<std::string> selectedTomatoes_;
    std::vector<std::string> selectedCheeses_;
    std::vector<std::string> selectedMeats_;
    std::vector<std::string> selectedHerbs_;

    const std::vector<std::string> availableTomatoes_ = {"Cherry", "Roma", "Beefsteak", "Heirloom", "Grape"};
    // TODO: agrega aquí la lista de tu ingrediente.
    // const std::vector<std::string> availableCheeses_ = { ... };
    // const std::vector<std::string> availableMeats_ = { ... };
    // const std::vector<std::string> availableHerbs_ = { ... };
};