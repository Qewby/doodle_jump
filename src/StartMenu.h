#ifndef DOODLE_JUMP_STARTMENU_H
#define DOODLE_JUMP_STARTMENU_H

#include "Drawable.h"

extern std::pair<bool, std::pair<int, int>> gLeftMouseClickPosition;
extern std::pair<int, int> gMousePosition;

enum class StartMenuButton {
    PlayButton,
    ExitButton,
    RecordsButton,
    NoneButton
};

class StartMenu : public Drawable {
public:
    StartMenu();
    ~StartMenu();
    void Draw(Renderer &renderer) override;

    StartMenuButton HandleClick();
private:
    SDL_Rect mPlayButtonHitBox;
    SDL_Rect mRecordsButtonHitBox;
    SDL_Rect mExitButtonHitBox;

    SDL_Texture *mpPlayButtonTexture;
    SDL_Texture *mpOnPlayButtonTexture;
    SDL_Texture *mpRecordsButtonTexture;
    SDL_Texture *mpOnRecordsButtonTexture;
    SDL_Texture *mpExitButtonTexture;
    SDL_Texture *mpOnExitButtonTexture;
};

#endif //DOODLE_JUMP_STARTMENU_H
