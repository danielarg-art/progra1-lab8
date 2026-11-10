#include "MeatsRepository.h"
#include <cstdio>
#include <fstream>
#include <stdexcept>
#include <utility>
#ifdef _WIN32
#include <windows.h>
#endif

MeatsRepository::MeatsRepository() {
    // Usar el mismo archivo que la aplicación puede abrir en este directorio de trabajo.
    filePath_ = "meats.txt";
    std::ifstream probe(filePath_);
    if (!probe) filePath_ = "Data/meats.txt";
    data_ = DataLoader::LoadFromFile("meats.txt");
}

int MeatsRepository::GetAvailableQuantity(const std::string& ingredientType) const {
    auto it = data_.find(ingredientType);
    if (it == data_.end()) throw std::invalid_argument("Carne desconocida: " + ingredientType);
    return std::stoi(it->second.at(0));
}

void MeatsRepository::UpdateQuantity(const std::string& ingredientType, int newQuantity) {
    auto it = data_.find(ingredientType);
    if (it == data_.end()) throw std::invalid_argument("Carne desconocida: " + ingredientType);
    if (newQuantity < 0) throw std::invalid_argument("La cantidad no puede ser negativa");

    // Guardar todos los registros antes de modificar el inventario en memoria.
    const std::string temporal = filePath_ + ".tmp";
    std::ofstream salida(temporal, std::ios::trunc);
    if (!salida) throw std::runtime_error("No se pudo abrir el archivo temporal de carnes");
    // Mantener el orden de la lista de opciones y el resto del inventario.
    const std::vector<std::string> orden = {"Pepperoni", "Bacon", "Chicken", "Shrimp", "Mignon", "Ham", "Sausage", "Prosciutto"};
    for (const auto& nombre : orden) {
        auto encontrado = data_.find(nombre);
        if (encontrado == data_.end()) continue;
        int cantidad = nombre == ingredientType ? newQuantity : std::stoi(encontrado->second.at(0));
        salida << nombre << ": " << cantidad << '\n';
    }
    salida.flush();
    if (!salida) { salida.close(); std::remove(temporal.c_str()); throw std::runtime_error("Error guardando el inventario"); }
    salida.close();
#ifdef _WIN32
    if (!MoveFileExA(temporal.c_str(), filePath_.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH)) {
        std::remove(temporal.c_str());
        throw std::runtime_error("No se pudo reemplazar meats.txt");
    }
#else
    if (std::rename(temporal.c_str(), filePath_.c_str()) != 0) {
        std::remove(temporal.c_str());
        throw std::runtime_error("No se pudo reemplazar meats.txt");
    }
#endif
    it->second[0] = std::to_string(newQuantity);
}
