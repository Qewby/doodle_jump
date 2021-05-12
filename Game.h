#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include <iostream>

#include "Window.h"
#include "SDL.h"

class Game {
public:
    Game(std::string name, bool isFullScreen);
    ~Game();
    void Run();

private:
    Window *mpWindow;
    int mScreenHeight;
    int mScreenWidth;
    int mWindowHeight;
    int mWindowWidth;
    bool mQuit;
};


#endif //DOODLE_JUMP_GAME_H
