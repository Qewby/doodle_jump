#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include "../Drawable.h"

class Platform : public Drawable {
public:
    Platform(int x, int y, Renderer& renderer);
    virtual ~Platform() {};

    bool isVisible();
    SDL_Rect& GetHitBox();

    virtual bool CollisionCallback(bool isCollided) = 0;
protected:
    SDL_Rect mHitBox;
    bool mVisible;
};


#endif //DOODLE_JUMP_PLATFORM_H
