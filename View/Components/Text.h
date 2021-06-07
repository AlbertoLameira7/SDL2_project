#include "Widget.h"

class Text : public Widget {

public:
    Text(int xPos, int yPos, const char* text);
    ~Text();

    void update();

private:

};