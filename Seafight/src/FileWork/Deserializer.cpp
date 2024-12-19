#include "Deserializer.hpp"
#include <set>

Deserializer::Deserializer(nlohmann::json& j) : j(j) {};

void Deserializer::from_json(ShipManager& shipManager, std::string key) {

    const auto& jsonShipManager = j.at(key);

    for (const auto& shipJson : jsonShipManager) {
        Ship ship(shipJson["length"]);
        ship.setIsPlaced(shipJson["isPlaced"]);
        ship.setIsVertical(shipJson["isVertical"]);
        ship.setIsDestroyed(shipJson["isDestroyed"]);

        int i = 0;
        for (const auto& segmentJson : shipJson["segments"]) {
            auto segment=ship.getSegment(i);
            segment->status = segmentJson["status"];
            segment->coord.x = segmentJson["x"];
            segment->coord.y = segmentJson["y"];
            i++;
        }
        shipManager.addShip(ship);
    }
}

void Deserializer::from_json(GameField& field, std::string key) {
    const auto& userField = j.at(key);
    field = GameField(userField.at("width").get<int>(), userField.at("height").get<int>());

    for (int y = 0; y < field.getHeight(); y++) {
        for (int x = 0; x < field.getWidth(); x++) {
            int index = y * field.getWidth() + x;
            auto& cell = field.getFieldCell(Coordinates{ x, y });
            cell.status = userField.at("status").at(index).get<CellStatus>();
            cell.value = userField.at("value").at(index).get<CellValue>();
        }
    }
}

void Deserializer::from_json(AbilityManager& abilityManager, std::string key){
    const auto& jsonAM = j.at(key);
    for (const auto& abilityJson : jsonAM) {
       if (abilityJson.get<std::string>() == "Random Hit") {
           abilityManager.addAbilityCreator(new RandomHitCreator());
       }
       else if(abilityJson.get<std::string>() == "Double Damage"){
           abilityManager.addAbilityCreator(new DoubleDamageCreator());
       }
       else if (abilityJson.get<std::string>() == "Scanner") {
           abilityManager.addAbilityCreator(new ScannerCreator());
       }
    }
}

void Deserializer::from_json(int& number, std::string key){
    number = j[key];
}

bool Deserializer::checkIsValid() {
    auto storedChecksum = j["checksum"];
    j.erase("checksum");
    std::string loadedJsonStr = j.dump();
    std::hash<std::string> hashFn;
    auto checksum = hashFn(loadedJsonStr);
    if (checksum != storedChecksum) {
        return false;
    }
    return true;
}

void Deserializer::from_json(std::map<char, GameCommand>& settings) {
    if (j.find("settings") == j.end()) {
        throw std::invalid_argument("Key 'settings' not found in JSON");
    }
    auto& settings_json = j["settings"];
    std::set<char> unique_keys;
    std::set<int> unique_values;

    for (auto& item : settings_json.items()) {
        std::string key_str = item.key();
        if (key_str.size() != 1) {
            throw std::invalid_argument("Invalid key in JSON: " + key_str);
        }
        char key = key_str[0];
        if (unique_keys.find(key) != unique_keys.end()) {
            throw std::invalid_argument("Duplicate key in JSON: " + key_str);
        }
        unique_keys.insert(key);
        int value = item.value().get<int>();
        if (value < 1 || value > 6) {
            throw std::invalid_argument("Invalid GameCommand value: " + std::to_string(value));
        }

        if (unique_values.find(value) != unique_values.end()) {
            throw std::invalid_argument("Duplicate GameCommand value: " + std::to_string(value));
        }
        unique_values.insert(value);

        settings[key] = static_cast<GameCommand>(value);
        if (settings.size() != 6) {
            throw std::invalid_argument("Invalid settings");
        }
    }
}