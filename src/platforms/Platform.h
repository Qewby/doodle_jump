#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include "../IDrawable.h"

extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

class Platform : public IDrawable {
public:
    Platform(int x, int y);
    virtual ~Platform() {};

    bool isVisible();
    SDL_Rect& GetHitBox();

    virtual bool CollisionCallback(bool isCollided) = 0;
protected:
    SDL_Rect mHitBox;
    bool mVisible;
};


#endif //DOODLE_JUMP_PLATFORM_H
