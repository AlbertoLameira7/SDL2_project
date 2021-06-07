#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class EventHandler {

    public:
        static EventHandler* getInstance();

        void handleEvents();
        bool getKeyDown(SDL_Scancode key);
        
    private:
        EventHandler();
        static EventHandler* _instance;
        void keyUp();
        void keyDown();
        
        const Uint8* _keyStates;
        SDL_Scancode _currentKeyPressed;
        bool _isKeyPressed;
};