#include "Bubble.h"

Bubble::Bubble(const char* imageID, int xPos, int yPos, int width, int height) {
    _imageID = imageID;
    _xPos = xPos;
    _yPos = yPos;
    _width = width;
    _height = height;
}

void Bubble::update() {

}

const char* Bubble::getImageID() {
    return _imageID;
}

int Bubble::getX() {
    return _xPos;
}

int Bubble::getY() {
    return _yPos;
}

int Bubble::getWidth() {
    return _width;
}

int Bubble::getHeight() {
    return _height;
}
