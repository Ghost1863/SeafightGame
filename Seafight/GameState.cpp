#include "GameState.hpp"

FileWrapper& operator<<(FileWrapper& file, GameState& state) {
    nlohmann::json j;
    Serializer serializer(j);
    serializer.to_json(state.getUser()->shipManager, "userShipManager");
    serializer.to_json(state.getUser()->field, "userField");
    serializer.to_json(state.getUser()->abilityManager, "abilityManager");
    serializer.to_json(state.getBot()->shipManager, "botShipManager");
    serializer.to_json(state.getBot()->field, "botField");
    j["currentRound"] = state.getCurrentRound();
    j["currentDamage"] = state.getUser()->currentDamage;
   
    try {
        file.write(j);
    }
    catch (std::exception& e){
        std::cout << e.what();
    }

    return file;
}

FileWrapper& operator>>(FileWrapper& file, GameState& state) {
    nlohmann::json j;

    try {
        file.read(j);
    }
    catch (std::exception& e) {
        std::cout << e.what();
        return file;
    }

    Deserializer deserializer(j);
    ShipManager sm;
    ShipManager sm2;
    GameField gf;
    GameField gf2;
    AbilityManager abilityManager;

    deserializer.from_json(sm, "userShipManager");
    deserializer.from_json(gf, "userField");
    deserializer.from_json(sm2, "botShipManager");
    deserializer.from_json(gf2, "botField");
    deserializer.from_json(abilityManager, "abilityManager");
    int currentRound = j["currentRound"];
    int currentDamage = j["currentDamage"];

    state.getBot()->shipManager = sm2;
    state.getBot()->field = gf2;
    state.getUser()->shipManager = sm;
    state.getUser()->field = gf;
    state.getUser()->abilityManager = abilityManager;
    state.getUser()->currentDamage = currentDamage;
    
    state.placeShipsBack(state.getBot()->shipManager, state.getBot()->field);
    state.placeShipsBack(state.getUser()->shipManager, state.getUser()->field);

    return file;
}

GameState::GameState(std::shared_ptr<User> user, std::shared_ptr<Bot> bot, int& current_round) :
    user(user), bot(bot), currentRound(currentRound) {};

void GameState::save(const std::string& filename){
    FileWrapper file(filename);
    file << *this;   
}

void GameState::load(const std::string& filename) {
    FileWrapper file(filename);
    file >> *this;
}

void GameState::placeShipsBack(ShipManager& shipManager, GameField& field) {
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

std::shared_ptr<User> GameState::getUser() {
    return user;
}

std::shared_ptr<Bot> GameState::getBot() {
    return bot;
}

int GameState::getCurrentRound() {
    return currentRound;
}
