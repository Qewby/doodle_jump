#ifndef DOODLE_JUMP_SCORELINE_H
#define DOODLE_JUMP_SCORELINE_H

#include "IDrawable.h"
#include "SDL_ttf.h"

extern int SCORE;
extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

class ScoreLine : public IDrawable{
public:
    ScoreLine();
    ~ScoreLine();

    void Draw(Renderer &renderer) override;

private:
    static const int mcMaxScoreLength = 10;
    SDL_Rect mLineHitBox;
    SDL_Rect mTextHitBox;
    TTF_Font *mpFont;
    SDL_Surface *mpSurface;
    SDL_Texture *mpTexture;
};


#endif //DOODLE_JUMP_SCORELINE_H
