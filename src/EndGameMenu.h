#ifndef DOODLE_JUMP_ENDGAMEMENU_H
#define DOODLE_JUMP_ENDGAMEMENU_H

#include "Drawable.h"
#include "SDL_ttf.h"

extern unsigned long long  SCORE;
extern unsigned long long  RECORD;

extern const int gcMaxScoreLength;

extern std::pair<bool, std::pair<int, int>> gLeftMouseClickPosition;
extern std::pair<int, int> gMousePosition;

enum class EndMenuButton {
    PlayAgainButton,
    MenuButton,
    NoneButton
};

class EndGameMenu : public Drawable {
public:
    EndGameMenu(Renderer& renderer);
    virtual ~EndGameMenu();
    void Draw() override;

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
