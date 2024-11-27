#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "Deserializer.hpp"
#include "Serializer.hpp"
#include "Player.hpp"
#include "FileWrapper.hpp"
#include <fstream>

class GameState {
private:
	std::shared_ptr<User> user;
	std::shared_ptr<Bot> bot;
	int currentRound;
public:
	GameState(std::shared_ptr<User> user, std::shared_ptr<Bot> bot, int& current_round);
;	void save(const std::string& filename);
	void load(const std::string& filename);
	std::shared_ptr<User> getUser();
	std::shared_ptr<Bot> getBot();
	int getCurrentRound();
	void placeShipsBack(ShipManager& shipManager,GameField& field);
};
#endif 