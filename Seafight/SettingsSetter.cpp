#include "SettingsSetter.hpp"
#include "FileWrapper.hpp"
#include "Deserializer.hpp"

void SettingsSetter::setFromFile() {
    std::map<char, GameCommand> settings;
    FileWrapper file("settings.json", std::ios::in);
    nlohmann::json j;
    file.read(j);
    Deserializer(j).from_json(settings);
    handler.setSettings(settings);
}