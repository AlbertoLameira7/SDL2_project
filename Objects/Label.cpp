#include "Label.h"

#include <iostream>

Label::Label(std::string text, SDL_Color color, int xPos, int yPos) {
    _text = text;
    _color = color;
    _xPos = xPos;
    _yPos = yPos;
}

void Label::update() {

}

void Label::setText(std::string text) {
    _text = text;
}

std::string Label::getText() {
    return _text;
}

SDL_Color Label::getColor() {
    return _color;
}

int Label::getX() {
    return _xPos;
}

int Label::getY() {
    return _yPos;
}

void Label::setY(int value) {
    _yPos = value;
}
