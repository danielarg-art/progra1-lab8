#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>

static inline std::string trim(const std::string& s) {
    auto start = s.find_first_not_of(" \t\r\n");
    auto end   = s.find_last_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

std::unordered_map<std::string, std::vector<std::string>>
DataLoader::LoadFromFile(const std::string& path) {
    std::ifstream in(path);
    if (!in) {
        in.clear();
        in.open(std::string("Data\\") + path);
    }
    if (!in) {
        in.clear();
        in.open(std::string("Data/") + path);
    }
    if (!in) {
        throw std::runtime_error("No se puede abrir el archivo: " + path);
    }

    std::unordered_map<std::string, std::vector<std::string>> result;
    std::string line;
    int lineno = 0;

    while (std::getline(in, line)) {
        ++lineno;
        line = trim(line);
        if (line.empty()) continue;

        auto pos = line.find(':');
        if (pos == std::string::npos) {
            throw std::runtime_error("Formato inválido en la línea " + std::to_string(lineno) + ": falta ':'");
        }

        std::string name = trim(line.substr(0, pos));
        std::string rest = trim(line.substr(pos + 1));

        std::vector<std::string> ingredients;
        std::stringstream ss(rest);
        std::string item;
        while (std::getline(ss, item, ',')) {
            auto ing = trim(item);
            if (!ing.empty()) ingredients.push_back(ing);
        }

        if (name.empty() || ingredients.empty()) {
            throw std::runtime_error("Entrada inválida en la línea " + std::to_string(lineno));
        }
        result[name] = std::move(ingredients);
    }
    return result;
}