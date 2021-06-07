#include "Engine.h"
#include "AssetManager.h"
#include "EventHandler.h"
#include "CreditsManager.h"
#include "BubbleManager.h"
#include "LabelManager.h"

#include <string>
#include <Objects/Player.h>

Engine* Engine::_instance = nullptr;
Player* player = nullptr;

Engine* Engine::getInstance() {
    if (_instance == nullptr)
        _instance = new Engine();

    return _instance;
}

bool Engine::init(const char* title, int xPos, int yPos, int width, int height) {
    // TODO: use flags in constructor to enable fullscreen or other SDL window configs
    int flags = 0;

    _screenWidth = width;
    _screenHeight = height;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL not loaded" << std::endl;
        return false;
    }

    TTF_Init();

    _window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

    if (_window == nullptr) {
        std::cout << "Window not created" << std::endl;
        return false;
    }

    _renderer = SDL_CreateRenderer(_window, -1, 0);
    
    if (_renderer == nullptr) {
        std::cout << "Renderer not created" << std::endl;
        return false;
    }

    // instanciate new player with 500 credits in wallet
    player = new Player("Alberto", new creditsWallet(5));

    BubbleManager::getInstance()->createBubbles();

    SDL_Color color = { 255, 255, 255 };
    LabelManager::getInstance()->createLabel("creditsInLabel", "Teste Manager", color, 0, 0);

    _isRunning = true;
    return true;
}

/**
 * Handle SDL Poll events and Button clicks
 * 
 */
void Engine::handleEvents() {
    EventHandler::getInstance()->handleEvents();
}

void Engine::update() {
    if (EventHandler::getInstance()->getKeyDown(SDL_SCANCODE_A)) {
        // CreditsIn event
        // remove one credit from player, if successful, insert credit into machine and update accoring label
        if (player->removeCreditsFromWallet()) {
            CreditsManager::getInstance()->creditsIn();
            updateCreditsInLabel();
        } else {
            // displays an informative message to the user saying that they can't put more credits into the machine
            createNotEnoughCreditsLabel();
        }
    }
    
    if (EventHandler::getInstance()->getKeyDown(SDL_SCANCODE_D)) {
        // CreditsOut event, remove credits from the bet, update creditsIn label and remove not enough credits message, in case it exists.
        removeCreditsFromBet();
        updateCreditsInLabel();
        removeNotEnoughCreditsLabel();
    }
}

void Engine::render() {
    SDL_RenderClear(_renderer);

    SDL_SetRenderDrawColor(_renderer, 100, 100, 100, 100);

    BubbleManager::getInstance()->drawBubbles();
    LabelManager::getInstance()->drawLabels();

    SDL_RenderPresent(_renderer);
}

void Engine::clean() {
    AssetManager::getInstance()->clean();
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Engine::removeCreditsFromBet() {
    // give player the credits currently in play
    if (CreditsManager::getInstance()->getCreditsInPlay() > 0) {
        player->insertCreditsToWallet(CreditsManager::getInstance()->getCreditsInPlay());
        CreditsManager::getInstance()->creditsOut();
    }
}

void Engine::updateCreditsInLabel() {
    std::string creditsInLabel = "Credits in play: " + std::to_string(CreditsManager::getInstance()->getCreditsInPlay());
    LabelManager::getInstance()->updateLabel("creditsInLabel", creditsInLabel);
}

void Engine::createNotEnoughCreditsLabel() {
    // check if label already exists, if it doesn't create one underneath the credits in label.
    if (LabelManager::getInstance()->getLabel("notEnoughCredits") == nullptr) {
        SDL_Color color = { 255, 255, 255 };
        LabelManager::getInstance()->createLabel("notEnoughCredits", "Not enough credits in player wallet!", color, 0, LabelManager::getInstance()->getLabel("creditsInLabel")->getY() + 20);
    }
}

void Engine::removeNotEnoughCreditsLabel() {
    if (LabelManager::getInstance()->getLabel("notEnoughCredits") != nullptr) {
        LabelManager::getInstance()->removeLabel("notEnoughCredits");
    }
}

bool Engine::isRunning() {
    return _isRunning;
}

void Engine::stop() {
    _isRunning = false;
}

SDL_Renderer* Engine::getRenderer() {
    return _renderer;
}

int Engine::getScreenWidth() {
    return _screenWidth;
}

int Engine::getScreenHeight() {
    return _screenHeight;
}
