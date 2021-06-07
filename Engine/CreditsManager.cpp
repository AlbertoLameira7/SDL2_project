#include "CreditsManager.h"

CreditsManager* CreditsManager::_instance = nullptr;

CreditsManager* CreditsManager::getInstance() {
    if (_instance == nullptr)
        _instance = new CreditsManager();

    return _instance;
}

CreditsManager::CreditsManager() {
    _creditsInPlay = 0;
}

void CreditsManager::creditsIn() {
    _creditsInPlay++;
}

void CreditsManager::creditsOut() {
    _creditsInPlay = 0;
}

int CreditsManager::getCreditsInPlay() {
    return _creditsInPlay;
}
