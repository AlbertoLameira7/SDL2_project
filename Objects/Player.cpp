#include "Player.h"

Player::Player(const char* name, creditsWallet* wallet) {
    _name = name;
    _wallet = wallet;
}

bool Player::removeCreditsFromWallet() {
    if (_wallet->_credits > 0) {
        _wallet->_credits--;
        return true;
    }

    return false;
}

void Player::insertCreditsToWallet(int value) {
    _wallet->_credits += value;
}

creditsWallet* Player::getWallet() {
    return _wallet;
}
