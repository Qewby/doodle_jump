#ifndef DOODLE_JUMP_ENDGAMEMENU_H
#define DOODLE_JUMP_ENDGAMEMENU_H

#include "IDrawable.h"
#include "Game.h"

enum class EndMenuButton {
    PlayAgainButton,
    MenuButton,
    NoneButton
};

class EndGameMenu : public IDrawable {
public:
    EndGameMenu();
    ~EndGameMenu();
    void Draw(Renderer &renderer) override;

    EndMenuButton HandleClick();
private:
    SDL_Rect mPlayAgainButtonHitBox;
    SDL_Rect mMenuButtonHitBox;

    SDL_Texture *mpPlayAgainButtonTexture;
    SDL_Texture *mpOnPlayAgainButtonTexture;
    SDL_Texture *mpMenuButtonTexture;
    SDL_Texture *mpOnMenuButtonTexture;

    SDL_Rect mScoreLabelHitBox;
    SDL_Rect mScoreHitBox;
    SDL_Rect mRecordLabelHitBox;
    SDL_Rect mRecordHitBox;

    SDL_Texture *mpScoreLabelTexture;
    SDL_Texture *mpRecordLabelTexture;
};


#endif //DOODLE_JUMP_ENDGAMEMENU_H
