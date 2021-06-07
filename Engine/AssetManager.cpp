#include "AssetManager.h"
#include "Engine.h"

AssetManager* AssetManager::_instance = nullptr;

AssetManager* AssetManager::getInstance() {
    if (_instance == nullptr)
        _instance = new AssetManager();

    return _instance;
}

bool AssetManager::loadImage(const char* id, const char* filePath) {
    SDL_Surface* surface = IMG_Load(filePath);

    if (surface == nullptr) {
        std::cout << "Image not loaded: " << filePath << ", Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), surface);

    _imageMap[id] = texture;
    SDL_FreeSurface(surface);
    return true;
}

bool AssetManager::loadFont(const char* filePath, int fontSize) {
    _font = TTF_OpenFont(filePath, fontSize);

    if (_font == nullptr) {
        std::cout << "Font not loaded: " << filePath << ", Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void AssetManager::drawImage(const char* id, int xPos, int yPos, int width, int height) {
    SDL_Rect srcR = { 0, 0, width, height };
    SDL_Rect dstR = { xPos, yPos, width, height };

    SDL_RenderCopy(Engine::getInstance()->getRenderer(), _imageMap[id], &srcR, &dstR);
}

void AssetManager::drawLabel(std::string text, SDL_Color color, int xPos, int yPos) {
    SDL_Surface* surface = TTF_RenderText_Blended(_font, text.c_str(), color);

    if (!surface) {
        std::cout << "Label surface not loaded, error: " << SDL_GetError() << std::endl;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Engine::getInstance()->getRenderer(), surface);

    if (!texture) {
        std::cout << "Label texture not loaded, error: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(surface);

    int texWidth = 0;
    int texHeight = 0;
    SDL_QueryTexture(texture, NULL, NULL, &texWidth, &texHeight);
    SDL_Rect dstR = { xPos, yPos, texWidth, texHeight };

    SDL_RenderCopy(Engine::getInstance()->getRenderer(), texture, NULL, &dstR);
    SDL_DestroyTexture(texture);
}

void AssetManager::clean() {
    std::map<const char*, SDL_Texture*>::iterator itImage;

    for (itImage = _imageMap.begin(); itImage != _imageMap.end(); itImage++) {
        SDL_DestroyTexture(itImage->second);
    }

    TTF_CloseFont(_font);
    TTF_Quit();
    _imageMap.clear();
}
