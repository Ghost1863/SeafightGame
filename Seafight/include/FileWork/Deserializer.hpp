#ifndef DESERIALIZER_HPP
#define DESERIALIZER_HPP
#include"nlohmann/json.hpp"
#include "ShipManager.hpp"
#include "GameField.hpp"
#include "AbilityManager.hpp"
#include "GameCommand.hpp"

class Deserializer {
private:
    nlohmann::json& j;
public:
    Deserializer(nlohmann::json& j);
    void from_json(ShipManager& shipManager, std::string key);
    void from_json(GameField& field, std::string key); 
    void from_json(AbilityManager& abilityManager, std::string key);
    void from_json(int& number, std::string key);
    void from_json(std::map<char, GameCommand>& settings);
    bool checkIsValid();
};
#endif



