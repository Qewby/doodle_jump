#ifndef DOODLE_JUMP_PLATFORM_H
#define DOODLE_JUMP_PLATFORM_H

#include <memory>

#include "Texture.h"
#include "../Drawable.h"

class Platform : public Drawable
{
public:
    Platform(int x, int y, Renderer &renderer, const string &texturePath);
    virtual ~Platform(){};

    bool isVisible();
    const SDL_Rect &GetHitBox();
    const void ShiftHitBox(int value);

    virtual void Draw() override;

    virtual bool CollisionCallback(bool isCollided) = 0;

protected:
    bool mVisible;
    SDL_Rect mHitBox;
    
private:
    shared_ptr<Texture> mTexture;
};

#endif // DOODLE_JUMP_PLATFORM_H
