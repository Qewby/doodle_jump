#ifndef DOODLE_JUMP_GAME_H
#define DOODLE_JUMP_GAME_H

#include <iostream>
#include <fstream>

#include "SDL.h"
#include "SDL_ttf.h"

#include "Window.h"
#include "Renderer.h"
#include "CollisionHandler.h"
#include "EventListener.h"
#include "ScoreLine.h"
#include "StartMenu.h"
#include "EndGameMenu.h"

extern unsigned long long  SCORE;
extern unsigned long long  RECORD;

extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

class Doodle;

class Game {
public:
    Game(std::string name, bool isFullScreen);
    ~Game();
    void Run();
    void Play();
    void UpdateRecord();
private:
    Doodle *mpDoodle;
    Renderer *mpRenderer;
    Window *mpWindow;
    CollisionHandler *mpCollisionHandler;
    Field *mpField;
    ScoreLine *mpScoreLine;
    EndGameMenu *mpEndMenu;
    StartMenu *mpStartMenu;
    EventListener mListener;
    int mScreenHeight;
    int mScreenWidth;
    int mWindowHeight;
    int mWindowWidth;
    int mScreenRate;
    bool mQuit;
    bool mLose;
};


#endif //DOODLE_JUMP_GAME_H
