#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

class Engine {

    public:
        static Engine* getInstance();

        bool init(const char* title, int xPos, int yPos, int width, int height);
        void handleEvents();
        void update();
        void render();
        void clean();
        bool isRunning();
        void stop();

        SDL_Renderer* getRenderer();
        int getScreenWidth();
        int getScreenHeight();
        
    private:
        Engine() {}
        static Engine* _instance;

        void removeCreditsFromBet();
        void updateCreditsInLabel();
        void createNotEnoughCreditsLabel();
        void removeNotEnoughCreditsLabel();

        bool _isRunning;
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        int _screenWidth, _screenHeight;
};