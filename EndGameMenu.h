#ifndef DOODLE_JUMP_ENDGAMEMENU_H
#define DOODLE_JUMP_ENDGAMEMENU_H

#include "IDrawable.h"
#include "Game.h"

extern const int gcMaxScoreLength;

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
    void Update();
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
    SDL_Texture *mpScoreTexture;
    SDL_Texture *mpRecordLabelTexture;
    SDL_Texture *mpRecordTexture;

    TTF_Font *mpFont;
    std::string mScoreText;
    std::string mRecordText;
};


#endif //DOODLE_JUMP_ENDGAMEMENU_H
