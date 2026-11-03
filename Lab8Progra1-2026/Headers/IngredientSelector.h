#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

template<typename TRepository>
class IngredientSelector {
public:
    IngredientSelector(TRepository& repository, const std::vector<std::string>& availableItems, const std::string& ingredientType);

    void DisplayAvailableIngredients();
    bool AddIngredientToPizza(const std::string& ingredientName, std::vector<std::string>& selectedIngredients);

private:
    TRepository& repository_;
    const std::vector<std::string>& availableItems_;
    const std::string ingredientType_;
};

template<typename TRepository>
IngredientSelector<TRepository>::IngredientSelector(TRepository& repository, const std::vector<std::string>& availableItems, const std::string& ingredientType)
    : repository_(repository), availableItems_(availableItems), ingredientType_(ingredientType) {
}

template<typename TRepository>
void IngredientSelector<TRepository>::DisplayAvailableIngredients() {
    std::cout << "\nTipos de " << ingredientType_ << " disponibles:" << std::endl;
    for (const auto& item : availableItems_) {
        try {
            int quantity = repository_.GetAvailableQuantity(item);
            std::cout << "- " << item << " (Disponibles: " << quantity << ")" << std::endl;
        } catch (const std::invalid_argument&) {
            std::cout << "- " << item << " (No disponible)" << std::endl;
        }
    }
}

template<typename TRepository>
bool IngredientSelector<TRepository>::AddIngredientToPizza(const std::string& ingredientName, std::vector<std::string>& selectedIngredients) {
    try {
        int quantity = repository_.GetAvailableQuantity(ingredientName);
        if (quantity > 0) {
            selectedIngredients.push_back(ingredientName);
            repository_.UpdateQuantity(ingredientName, quantity - 1);
            std::cout << "¡Se agregó " << ingredientName << " a tu pizza!" << std::endl;
            return true;
        } else {
            std::cout << "Lo sentimos, no se puede agregar " << ingredientName << " (" << ingredientType_ << ") en este momento. Elige otro." << std::endl;
            return false;
        }
    } catch (const std::invalid_argument&) {
        std::cout << "Lo sentimos, " << ingredientName << " no es un tipo de " << ingredientType_ << " válido. Elige una de las opciones disponibles." << std::endl;
        return false;
    }
}
