#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include <iostream>

#include "SDL.h"

#include "Window.h"
#include "Renderer.h"
#include "Doodle.h"
#include "EventHandler.h"

class Game {
public:
    Game(std::string name, bool isFullScreen);
    ~Game();
    void Run();

private:
    EventHandler *mpHandler;
    Doodle *mpDoodle;
    Renderer *mpRenderer;
    Window *mpWindow;
    int mScreenHeight;
    int mScreenWidth;
    int mWindowHeight;
    int mWindowWidth;
    int mScreenRate;
    bool mQuit;
};


#endif //DOODLE_JUMP_GAME_H
