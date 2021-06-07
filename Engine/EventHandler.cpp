#include "EventHandler.h"
#include "Engine.h"

EventHandler* EventHandler::_instance = nullptr;

EventHandler* EventHandler::getInstance() {
    if (_instance == nullptr)
        _instance = new EventHandler();

    return _instance;
}

EventHandler::EventHandler() {
    _keyStates = SDL_GetKeyboardState(nullptr);
    _isKeyPressed = false;
}

void EventHandler::handleEvents() {
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            Engine::getInstance()->stop();
            break;
        case SDL_KEYDOWN:
            keyDown();
            break;
        case SDL_KEYUP:
            keyUp();
            break;
        default:
            break;
        }
    }
}

/**
 * Get current keydown
 * 
 * Gets current keydown from the SDL_GetKeyboardState list, if a valid key is being pressed
 * and no other key is being pressed a the same time, then set isKeyPressed to true and store which key is being pressed.
 * This mehcanism is to prevent multiple keys from being pressed at once, in a real machine multiple key presses should never happen
 *  
 * @param key SDL_Scancode key
 * @return true if the key is currently being pressed and no other key is being pressed simultaneously.
 */
bool EventHandler::getKeyDown(SDL_Scancode key) {
    if (_keyStates[key] == 1 && !_isKeyPressed) {
        _isKeyPressed = true;
        _currentKeyPressed = key;
        return true;
    }

    return false;
}

/**
 * Release key event
 * 
 * Saves new keyboard state from SDL_GetKeyboardState. If the key released is the same as the first stored key, then release the key lock mechanism.
 * This enables a new key to be pressed and listened for events.
 */
void EventHandler::keyUp() {
    _keyStates = SDL_GetKeyboardState(nullptr);

    if (_keyStates[_currentKeyPressed] == 0) {
        _currentKeyPressed = SDL_SCANCODE_UNKNOWN;
        _isKeyPressed = false;
    }
}

void EventHandler::keyDown() {
    _keyStates = SDL_GetKeyboardState(nullptr);
}
