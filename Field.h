#ifndef DOODLE_JUMP_FIELD_H
#define DOODLE_JUMP_FIELD_H

#define MAX_PLATFORM_COUNT 20

#include <deque>
#include <random>

#include "platforms/PlatformFactory.h"

class Field : public IDrawable {
public:
    Field();
    ~Field();

    void Draw(Renderer &renderer) override;
    std::deque<Platform*>& GetPlatforms();
    void Shift(int value);
private:
    int GetRandomX();

    std::deque<Platform*> mPlatforms;

    PlatformFactory mFactory;
    const int mcStep;
    int mLastPosition;
};


#endif //DOODLE_JUMP_FIELD_H
