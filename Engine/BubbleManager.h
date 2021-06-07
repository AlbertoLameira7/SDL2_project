#include <iostream>
#include <list>
#include <vector>
#include <string>

#include <Objects/Bubble.h>

class BubbleManager {

    public:
        static BubbleManager* getInstance();

        void createBubbles();
        void drawBubbles();
        
    private:
        BubbleManager();
        static BubbleManager* _instance;

        std::vector<std::string> _bubbleColors { "bubble_blue", "bubble_green", "bubble_pink", "bubble_red", "bubble_yellow" };
        std::list<Bubble*> _bubbles;
};