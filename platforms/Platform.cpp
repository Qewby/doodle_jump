#include "Platform.h"

Platform::Platform(int x, int y) {
    mHitBox.x = x;
    mHitBox.y = y;
    mHitBox.h = WINDOW_HEIGHT * 0.027;
    mHitBox.w = WINDOW_WIDTH * 0.18;
}

bool Platform::isVisible() {
    return mVisible;
}

SDL_Rect& Platform::GetHitBox() {
    return mHitBox;
}