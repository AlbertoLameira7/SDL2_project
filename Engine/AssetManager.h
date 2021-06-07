#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <map>

class AssetManager {

    public:
        static AssetManager* getInstance();

        bool loadImage(const char* id, const char* filePath);
        bool loadFont(const char* filePath, int fontSize);
        void drawImage(const char* id, int xPos, int yPos, int width, int height);
        void drawLabel(std::string id, SDL_Color color, int xPos, int yPos);
        void clean();
        
    private:
        AssetManager() {}
        static AssetManager* _instance;

        std::map<const char*, SDL_Texture*> _imageMap;
        TTF_Font* _font;
};