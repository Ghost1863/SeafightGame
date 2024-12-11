#include "Serializer.hpp"


Serializer::Serializer(nlohmann::json& j) : j(j) {};

void Serializer::to_json(ShipManager& shipManager, std::string key) {
    nlohmann::json jsonShipManager = nlohmann::json::array();

    for (int i = 0; i < shipManager.getShipsAmount(); i++) {
        Ship& ship = shipManager.getShip(i);
       // std::string shipKey = "ship" + std::to_string(i);
        nlohmann::json shipJson = {
            {"length", ship.getLength()},
            {"isPlaced", ship.getIsPlaced()},
            {"isVertical", ship.getIsVertical()},
            {"isDestroyed", ship.getIsDestroyed()},
            {"segments", nlohmann::json::array()}
        };

        for (int jj = 0; jj < ship.getLength(); jj++) {
            shipJson["segments"].push_back({
                {"status", ship.getSegment(jj)->status},
                {"x", ship.getSegment(jj)->coord.x},
                {"y", ship.getSegment(jj)->coord.y}
                });
        }
        jsonShipManager.push_back(shipJson);
    }

    j[key] = jsonShipManager;
}

void Serializer::to_json(GameField& field, std::string key) {
    nlohmann::json jsonField = nlohmann::json{};
    jsonField["width"] = field.getWidth();
    jsonField["height"] = field.getHeight();
    jsonField["status"] = nlohmann::json::array();
    jsonField["value"] = nlohmann::json::array();
    for (int y = 0; y < field.getHeight(); y++)
    {
        for (int x = 0; x < field.getWidth(); x++)
        {
            auto& cell = field.getFieldCell(Coordinates{ x,y });
            jsonField["status"].push_back(cell.status);
            jsonField["value"].push_back(cell.value);
        }
    }
    j[key] = jsonField;
}

void Serializer::to_json(AbilityManager& abilityManager, std::string key){
    nlohmann::json jsonAbilityManager = nlohmann::json{}.array();
    AbilityPrinter printer;
    for (size_t i = 0; i < abilityManager.getAbilitiesSize(); i++)
    {
        jsonAbilityManager.push_back(abilityManager.getAbilityCreator(i).accept(&printer));
    }
    j[key] = jsonAbilityManager;
}

void Serializer::to_json(int number, std::string key) {
    j[key] = number;
}

void Serializer::hashFile() {
    std::string jsonStr = j.dump();
    std::hash<std::string> hashFn;
    j["checksum"] = hashFn(jsonStr);
}