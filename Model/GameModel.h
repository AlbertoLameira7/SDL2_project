#pragma once

#include <iostream>

class GameModel {

public:
    GameModel();
    ~GameModel();

    void init(const char* name, int credits);
    void update();
    void clean();
    bool isRunning();
    void stop();
    void creditIn();
    void creditOut();
    void creditOutAll();
    void play();
    void printCredits();
    void printPlayerInfo();

private:
    const char* _name;
    int _playerCredits;
    int _creditsToBet;
    bool _isRunning;
};
