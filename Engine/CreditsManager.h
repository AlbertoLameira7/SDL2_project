#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class CreditsManager {

    public:
        static CreditsManager* getInstance();

        void creditsIn();
        void creditsOut();
        int getCreditsInPlay();

    private:
        CreditsManager();
        static CreditsManager* _instance;

        unsigned int _creditsInPlay;

};