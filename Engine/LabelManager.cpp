#include "LabelManager.h"
#include "AssetManager.h"
#include "Engine.h"

#include <cstdlib>

LabelManager* LabelManager::_instance = nullptr;

LabelManager* LabelManager::getInstance() {
    if (_instance == nullptr)
        _instance = new LabelManager();

    return _instance;
}

LabelManager::LabelManager() {
    std::string fontPath = "Assets/Fonts/Roboto/Roboto.ttf";

    AssetManager::getInstance()->loadFont(fontPath.c_str(), 20);
}

void LabelManager::createLabel(const char* labelID, const char* text, SDL_Color color, int xPos, int yPos) {
    _labelMap[labelID] = new Label(text, color, xPos, yPos);
}

void LabelManager::updateLabel(const char* labelID, std::string text) {
    _labelMap[labelID]->setText(text);
}

Label* LabelManager::getLabel(const char* labelID) {
    if (_labelMap.find(labelID) == _labelMap.end())
        return nullptr;

    return _labelMap[labelID];
}

void LabelManager::removeLabel(const char* labelID) {
    _labelMap.erase(labelID);
}

void LabelManager::drawLabels() {
    std::map<const char*, Label*>::iterator it;

    for (it = _labelMap.begin(); it != _labelMap.end(); it++) {
        AssetManager::getInstance()->drawLabel(it->second->getText(), it->second->getColor(), it->second->getX(), it->second->getY());
    }
}
