#include "Platform.h"

#include "TextureFactory.h"

Platform::Platform(int x, int y, Renderer &renderer, const string &texturePath) : Drawable(renderer), mVisible(true)
{
    mTexture = TextureFactory::getTexture(renderer, texturePath);
    mHitBox.x = x;
    mHitBox.y = y;
    mHitBox.h = WINDOW_HEIGHT * 0.025;
    mHitBox.w = WINDOW_WIDTH * 0.16;
}

bool Platform::isVisible()
{
    return mVisible;
}

const SDL_Rect &Platform::GetHitBox()
{
    return mHitBox;
}

const void Platform::ShiftHitBox(int value)
{
    mHitBox.y += value;
}

void Platform::Draw()
{
    if (mTexture)
    {
        mTexture->Draw(mrRenderer, mHitBox);
    }
}
