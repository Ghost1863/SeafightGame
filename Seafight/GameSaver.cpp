#include "GameSaver.hpp"

FileWrapper& operator<<(FileWrapper& file, GameState& state) {
    nlohmann::json j;
    Serializer serializer(j);
    serializer.to_json(state.getUser()->shipManager, "userShipManager");
    serializer.to_json(state.getUser()->field, "userField");
    serializer.to_json(state.getUser()->abilityManager, "abilityManager");
    serializer.to_json(state.getBot()->shipManager, "botShipManager");
    serializer.to_json(state.getBot()->field, "botField");
    serializer.to_json(state.getCurrentRound(), "currentRound");
    serializer.hashFile();

    file.write(j);

    return file;
}

void GameSaver::save() {
    FileWrapper file("saveFile.json",std::ios::out | std::ios::trunc);
    file << state;
}