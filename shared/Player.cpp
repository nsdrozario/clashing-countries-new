#include <Player.hpp>
using namespace ClashingCountries;

Game::Player::Player(std::string n) {
    this->name = n;
}

int Game::Player::getHP() const {
    return this->HP;
}

long long Game::Player::getTotalMana() const {
    return this->totalMana;
}
