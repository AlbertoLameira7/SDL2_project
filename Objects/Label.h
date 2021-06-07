#include <SDL2/SDL.h>
#include <string>

class Label {

    public:
        Label(std::string text, SDL_Color color, int xPos, int yPos);

        void update();
        void setText(std::string text);
        std::string getText();
        SDL_Color getColor();
        int getX();
        int getY();
        void setY(int value);

    private:
        int _xPos, _yPos;
        std::string _text;
        SDL_Color _color;
};
