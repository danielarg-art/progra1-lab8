#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "DataLoader.h"

class TomatoesRepository {
public:
    TomatoesRepository();

    int GetAvailableQuantity(const std::string& tomatoType) const;
    void UpdateQuantity(const std::string& tomatoType, int newQuantity);

private:
    mutable std::unordered_map<std::string, std::vector<std::string>> data_;
};