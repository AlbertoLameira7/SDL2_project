
class Bubble {

    public:
        Bubble(const char* imageID, int xPos, int yPos, int width, int height);

        void update();
        const char* getImageID();
        int getX();
        int getY();
        int getWidth();
        int getHeight();

    private:
        int _xPos, _yPos, _width, _height;
        const char* _imageID;
};
