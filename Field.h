#ifndef DOODLE_JUMP_FIELD_H
#define DOODLE_JUMP_FIELD_H

#include <deque>
#include <random>

#include "platforms/Platform.h"
#include "platforms/SimplePlatform.h"

class Field : public IDrawable {
public:
    Field();
    ~Field();

    void Draw(Renderer &renderer) override;
    std::deque<Platform*>& GetPlatforms();
    void Shift(int value);
private:
    std::deque<Platform*> mPlatforms;
};


#endif //DOODLE_JUMP_FIELD_H
