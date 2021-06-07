#include "GameModel.h"

GameModel::GameModel() {
    _creditsToBet = 0;
}

GameModel::~GameModel() {
    std::cout << "byeeee" << std::endl;
}

void GameModel::init(const char* name, int credits) {
    GameModel::_name = name;
    GameModel::_playerCredits = credits;
    _isRunning = true;
}

void GameModel::update() {
    /* std::cout << "press key" << std::endl;
    char input;
    std::cin.get(input);
    std::cout << input << std::endl;

    if (input == 'a')
        creditIn();
    else if (input == 'b')
        creditOut();
    else if (input == 'l')
        creditOutAll(); */
}

bool GameModel::isRunning() {
    return _isRunning;
}

void GameModel::stop() {
    _isRunning = false;
}

void GameModel::creditIn() {
    _playerCredits--;
    _creditsToBet++;
    printCredits();
}

void GameModel::creditOut() {
    _playerCredits++;
    _creditsToBet--;
    printCredits();
}

void GameModel::creditOutAll() {
    _playerCredits += _creditsToBet;
    _creditsToBet = 0;
    printCredits();
}

void GameModel::play() {
    
}

void GameModel::clean() {

}

void GameModel::printCredits() {
    std::cout << "player credits: " << _playerCredits << std::endl;
    std::cout << "credits to bet: " << _creditsToBet << std::endl;
}

void GameModel::printPlayerInfo() {
    std::cout << "Welcome " << _name << std::endl;
    std::cout << "You have " << _playerCredits << " credits." << std::endl;
}
