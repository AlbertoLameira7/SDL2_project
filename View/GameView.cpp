#include "GameView.h"
#include "Components/Button.h"
#include <Model/GameModel.h>

GameModel* gameModel = nullptr;
Button* button = nullptr;
SDL_Texture* texture;
SDL_Rect srcR, destR;
Button* buttonToClick;
int _cursorXPos, _cursorYPos;
const int BUTTON_WIDTH = 128;
const int BUTTON_HEIGHT = 64;

GameView::GameView() {

}

GameView::~GameView() {

}

void GameView::init(const char* title, int xPos, int yPos, int width, int height) {
    // TODO: use flags in constructor to enable fullscreen
    int flags = 0;

    _windowWidth = width;
    _windowHeight = height;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL loaded" << std::endl;

        _window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

        if (_window) {
            std::cout << "Window created" << std::endl;
        }

        _renderer = SDL_CreateRenderer(_window, -1, 0);
        
        if (_renderer) {
            SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
            std::cout << "Renderer created" << std::endl;
        }
    }

    gameModel = new GameModel();
    gameModel->init("Alberto", 500);

    button = new Button((_windowWidth / 2) - (BUTTON_WIDTH / 2), _windowHeight - (BUTTON_HEIGHT * 2), BUTTON_WIDTH, BUTTON_HEIGHT);

    SDL_Surface* tmpSurface = IMG_Load("Assets/Textures/test.png");
    texture = SDL_CreateTextureFromSurface(_renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);
}

/**
 * Handle SDL Poll events and Button clicks
 * 
 */
void GameView::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        gameModel->stop();
        break;
    case SDL_MOUSEBUTTONDOWN:
        if (isMouseOnButton()) {
            buttonToClick->click();
        }
        std::cout << "button down" << std::endl;
        break;
    case SDL_MOUSEBUTTONUP:
        buttonToClick = nullptr;
        break;
    default:
        break;
    }
}

/**
 * Check if the cursor is on top of a button, if it is keep a reference to the button.
 * 
 * @return true if cursor and button overlap, false if not.
 */
bool GameView::isMouseOnButton() {
    SDL_GetMouseState(&_cursorXPos, &_cursorYPos);
    SDL_Point point = {_cursorXPos, _cursorYPos};

    if (SDL_PointInRect(&point, button->getShape())) {
        // save a reference to the button
        buttonToClick = button;

        return true;
    }

    return false;
}

void GameView::update() {
    button->update();

    destR.w = BUTTON_WIDTH;
    destR.h = BUTTON_HEIGHT;
    destR.x = (_windowWidth / 2) - (BUTTON_WIDTH / 2);
    destR.y = _windowHeight - (BUTTON_HEIGHT * 2);
}

void GameView::render() {
    SDL_RenderClear(_renderer);

    SDL_RenderCopy(_renderer, texture, NULL, &destR);

    SDL_RenderPresent(_renderer);
}

bool GameView::isRunning() {
    return gameModel->isRunning();
}

void GameView::clean() {
    delete gameModel;
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
    SDL_Quit();
}
