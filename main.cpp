#include "Engine/Engine.h"

int main(int argc, const char * argv[]) {

    Engine::getInstance()->init("sdl_project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 720);

    while(Engine::getInstance()->isRunning()) {
        Engine::getInstance()->handleEvents();
        Engine::getInstance()->update();
        Engine::getInstance()->render();
    }

    Engine::getInstance()->clean();

    return 0;
}
