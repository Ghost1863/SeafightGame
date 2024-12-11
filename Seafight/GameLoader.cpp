#include "GameLoader.hpp"

FileWrapper& operator>>(FileWrapper& file, GameState& state) {
    nlohmann::json j;
    file.read(j);

    Deserializer deserializer(j);
    if (!deserializer.checkIsValid()) {
        throw(FileWasDamagedException());
    }
    ShipManager sm;
    ShipManager sm2;
    GameField gf;
    GameField gf2;
    AbilityManager abilityManager;
    int currentRound;

    deserializer.from_json(sm, "userShipManager");
    deserializer.from_json(gf, "userField");
    deserializer.from_json(sm2, "botShipManager");
    deserializer.from_json(gf2, "botField");
    deserializer.from_json(abilityManager, "abilityManager");
    deserializer.from_json(currentRound, "currentRound");
    
    state.getBot()->shipManager = sm2;
    state.getBot()->field = gf2;
    state.getUser()->shipManager = sm;
    state.getUser()->field = gf;
    state.getUser()->abilityManager = abilityManager;
    state.setCurrentRound(currentRound);

    return file;
}

void GameLoader::placeShipsBack(ShipManager& shipManager, GameField& field) {
    for (size_t i = 0; i < shipManager.getShipsAmount(); i++)
    {
        for (size_t j = 0; j < shipManager.getShip(i).getLength(); j++)
        {
            Coordinates coords = shipManager.getShip(i).getSegment(j)->coord;
            auto& cell = field.getFieldCell(coords);
            cell.ship = &shipManager.getShip(i);
            cell.value = CellValue::ShipSegment;
            cell.segmentIndex = j;
        }
    }
}

void GameLoader::load() {
    FileWrapper file("saveFile.json",std::ios::in);
    file >> state;
    placeShipsBack(state.getBot()->shipManager, state.getBot()->field);
    placeShipsBack(state.getUser()->shipManager, state.getUser()->field);
}

