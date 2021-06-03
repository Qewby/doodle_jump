#ifndef DOODLE_JUMP_SCORELINE_H
#define DOODLE_JUMP_SCORELINE_H

#include "IDrawable.h"
#include "SDL_ttf.h"

extern const int gcMaxScoreLength;
extern unsigned long long SCORE;
extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

class ScoreLine : public IDrawable{
public:
    ScoreLine();
    ~ScoreLine();

    void Draw(Renderer &renderer) override;

private:
    SDL_Rect mLineHitBox;
    SDL_Rect mTextHitBox;
    TTF_Font *mpFont;
    SDL_Surface *mpSurface;
    SDL_Texture *mpTexture;
};


#endif //DOODLE_JUMP_SCORELINE_H
