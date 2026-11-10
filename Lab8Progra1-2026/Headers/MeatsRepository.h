#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "DataLoader.h"

class MeatsRepository {
public:
    MeatsRepository();
    int GetAvailableQuantity(const std::string& ingredientType) const;
    void UpdateQuantity(const std::string& ingredientType, int newQuantity);
private:
    std::unordered_map<std::string, std::vector<std::string>> data_;
    std::string filePath_;
};
