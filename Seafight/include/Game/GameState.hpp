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
	std::shared_ptr<int> currentRound;
public:
	GameState(std::shared_ptr<User> user, std::shared_ptr<Bot> bot, std::shared_ptr<int> currentRound);
	std::shared_ptr<User> getUser();
	std::shared_ptr<Bot> getBot();
	int getCurrentRound();
	void setCurrentRound(int r);
};
#endif 