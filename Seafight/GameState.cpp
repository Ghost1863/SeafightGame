#include "GameState.hpp"

GameState::GameState(std::shared_ptr<User> user, std::shared_ptr<Bot> bot, std::shared_ptr<int> currentRound) :
    user(user), bot(bot), currentRound(currentRound) {};

std::shared_ptr<User> GameState::getUser() {
    return user;
}

std::shared_ptr<Bot> GameState::getBot() {
    return bot;
}

int GameState::getCurrentRound() {
    return *currentRound;
}

void GameState::setCurrentRound(int r) {
    *currentRound = r;
}

