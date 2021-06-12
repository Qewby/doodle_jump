#ifndef DOODLE_JUMP_SCORELINE_H
#define DOODLE_JUMP_SCORELINE_H

#include "Drawable.h"
#include "SDL_ttf.h"

extern const int gcMaxScoreLength;
extern unsigned long long SCORE;

class ScoreLine : public Drawable{
public:
    ScoreLine(Renderer& renderer);
    virtual ~ScoreLine();

    void Draw() override;

private:
    SDL_Rect mLineHitBox;
    SDL_Rect mTextHitBox;
    TTF_Font *mpFont;
    SDL_Surface *mpSurface;
    SDL_Texture *mpTexture;
};


#endif //DOODLE_JUMP_SCORELINE_H
