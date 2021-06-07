#include "Widget.h"
#include <SDL2/SDL.h>

enum ButtonState { DEFAULT=0, HOVER=1, PRESSED=2 };

class Button : public Widget {

public:
    Button(int xPos, int yPos, int width, int height);
    ~Button();

    void update();
    SDL_Rect* getShape();
    void click();

private:
    SDL_Rect _shape;
    int _x;
    int _y;
    bool _isPressed;
};
