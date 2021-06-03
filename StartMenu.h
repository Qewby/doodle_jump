#ifndef DOODLE_JUMP_STARTMENU_H
#define DOODLE_JUMP_STARTMENU_H

#include "IDrawable.h"
#include "Game.h"

enum class StartMenuButton {
    PlayButton,
    ExitButton,
    NoneButton
};

class StartMenu : public IDrawable {
public:
    StartMenu();
    ~StartMenu();
    void Draw(Renderer &renderer) override;

    StartMenuButton HandleClick();
private:
    SDL_Rect mPlayButtonHitBox;
    SDL_Rect mExitButtonHitBox;

    SDL_Texture *mpPlayButtonTexture;
    SDL_Texture *mpOnPlayButtonTexture;
    SDL_Texture *mpExitButtonTexture;
    SDL_Texture *mpOnExitButtonTexture;
};

#endif //DOODLE_JUMP_STARTMENU_H
