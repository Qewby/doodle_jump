#ifndef DOODLE_JUMP_FIELD_H
#define DOODLE_JUMP_FIELD_H

#define MAX_PLATFORM_COUNT 20

#include <deque>
#include <random>

#include "platforms/PlatformFactory.h"

extern unsigned long long SCORE;

class Field : public Drawable {
public:
    Field(bool& quit);
    ~Field();

    void Draw(Renderer &renderer) override;
    std::deque<Platform*>& GetPlatforms();
    void Shift(int value);
    void Clear();
    void Refill();
private:
    int GetRandomX();

    std::deque<Platform*> mPlatforms;

    PlatformFactory mFactory;
    const int mcStep;
    int mLastPosition;

    bool& mrProgramQuit;

private:
    SDL_Rect mHitBox;
    SDL_Texture *mpFieldTexture;
};


#endif //DOODLE_JUMP_FIELD_H
