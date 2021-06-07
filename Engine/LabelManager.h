#include <iostream>
#include <map>
#include <string>
#include <SDL2/SDL.h>

#include <Objects/Label.h>

class LabelManager {

    public:
        static LabelManager* getInstance();

        void createLabel(const char* labelID, const char* text, SDL_Color color, int _xPos, int _yPos);
        void updateLabel(const char* labelID, std::string text);
        Label* getLabel(const char* labelID);
        void removeLabel(const char* labelID);
        void drawLabels();
        
    private:
        LabelManager();
        static LabelManager* _instance;

        std::map<const char*, Label*> _labelMap;
};