#include "BubbleManager.h"
#include "AssetManager.h"
#include "Engine.h"

#include <cstdlib>

const int BUBBLE_SIZE = 60;

BubbleManager* BubbleManager::_instance = nullptr;

BubbleManager* BubbleManager::getInstance() {
    if (_instance == nullptr)
        _instance = new BubbleManager();

    return _instance;
}

BubbleManager::BubbleManager() {
    std::string folderPath = "Assets/Textures/Bubbles/";
    std::string fileExtension = ".png";

    for (int i = 0; i < _bubbleColors.size(); i++) {
        std::string fullPath = folderPath + _bubbleColors[i] + fileExtension;
        AssetManager::getInstance()->loadImage(_bubbleColors[i].c_str(), fullPath.c_str());
    }
}

/**
 * Create bubbles based on a predefined order (5 rows by 10 columns) with random colors. 
 * 
 */
void BubbleManager::createBubbles() {
    // set random seed based on time
    srand(time(0));

    // offset the bubbles horizontally so that they are centered. Number 10 is hardcoded to make 10 columns.
    int xOffset = (Engine::getInstance()->getScreenWidth() - (10 * BUBBLE_SIZE)) / 2;

    //offset the bubbles vertically so that 4 rows of bubbles are above the middle of the window
    int yOffset = (Engine::getInstance()->getScreenHeight() / 2) - (5 * BUBBLE_SIZE);

    // create the bubbles with random color, based on predefined _bubbleColors
    // relative bubble position is hardcoded (5 rows, 10 columns)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            _bubbles.push_back(new Bubble(_bubbleColors[rand() % 5].c_str(), j * BUBBLE_SIZE + xOffset, i * BUBBLE_SIZE + yOffset, BUBBLE_SIZE, BUBBLE_SIZE));
        }
    }
}

void BubbleManager::drawBubbles() {
    for (auto const& i : _bubbles) {
        AssetManager::getInstance()->drawImage(i->getImageID(), i->getX(), i->getY(), i->getWidth(), i->getHeight());
    }
}
