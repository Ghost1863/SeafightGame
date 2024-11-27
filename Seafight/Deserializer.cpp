#include "Deserializer.hpp"

Deserializer::Deserializer(nlohmann::json& j) : j(j) {};

void Deserializer::from_json(ShipManager& shipManager, std::string key) {
    std::vector<int> sizes;
    const auto& jsonShipManager = j.at(key);
    for (const auto& shipJson : jsonShipManager.items()) {
        sizes.push_back(shipJson.value().at("length").get<int>());
    }
    shipManager = ShipManager(sizes);

    for (const auto& shipJson : jsonShipManager.items()) {
        std::string shipKey = shipJson.key();
        int shipIndex = std::stoi(shipKey.substr(4)); 
        Ship& ship = shipManager.getShip(shipIndex);
        const auto& shipData = shipJson.value();

        ship.setIsPlaced(shipData.at("isPlaced").get<bool>());
        ship.setIsVertical(shipData.at("isVertical").get<bool>());
        ship.setIsDestroyed(shipData.at("isDestroyed").get<bool>());

        const auto& segmentsArray = shipData.at("segments");
        for (size_t j = 0; j < segmentsArray.size(); ++j) {
            ShipSegment* segment = ship.getSegment(j);
            const auto& segmentJson = segmentsArray[j];

            segment->status = segmentJson.at("status").get<SegmentStatus>();
            segment->coord.x = segmentJson.at("x").get<int>();
            segment->coord.y = segmentJson.at("y").get<int>();
        }
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
