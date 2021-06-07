#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class GameView {

public:
    GameView();
    ~GameView();

    void init(const char* title, int xPos, int yPos, int width, int height);

    void handleEvents();
    void update();
    void render();
    bool isRunning();
    void clean();
    
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;
    int _windowWidth;
    int _windowHeight;

    bool isMouseOnButton();
};
