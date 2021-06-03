#ifndef DOODLE_JUMP_STARTMENU_H
#define DOODLE_JUMP_STARTMENU_H

#include "IDrawable.h"
#include "Game.h"

class StartMenu : public IDrawable {
public:
    StartMenu();
    ~StartMenu();
    void Draw(Renderer &renderer) override;

private:
    SDL_Rect mStartButtonHitBox;
    SDL_Rect mExitButtonHitBox;

    SDL_Texture *mpStartButtonTexture;
    SDL_Texture *mpOnStartButtonTexture;
    SDL_Texture *mpExitButtonTexture;
    SDL_Texture *mpOnExitButtonTexture;
};


#endif //DOODLE_JUMP_STARTMENU_H
