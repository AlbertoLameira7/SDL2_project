#include "Button.h"
#include <iostream>

SDL_Event event;

Button::Button(int xPos, int yPos, int width, int height) {
    _shape = {xPos, yPos, width, height};
    _isPressed = false;
}

Button::~Button() {

}

void Button::update() {
}

void Button::click() {
    std::cout << "button pressed" << std::endl;
}

SDL_Rect* Button::getShape() {
    return &_shape;
}
