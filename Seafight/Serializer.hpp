#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include"nlohmann/json.hpp"
#include "ShipManager.hpp"
#include "GameField.hpp"
#include "AbilityManager.hpp"

class Serializer {
private:
    nlohmann::json& j;
public:
    Serializer(nlohmann::json& j);
    void to_json(ShipManager& shipManager, std::string key);
    void to_json(GameField& field, std::string key);
    void to_json(AbilityManager& abilityManager, std::string key);
    void to_json(int number, std::string key);
    void hashFile();
};
#endif 
