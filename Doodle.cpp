#include "Doodle.h"

Doodle::Doodle(int windowWidth, int windowHeight) : mcMaxHorizontalSpeed(windowWidth * 0.015),
    mcHorizontalAcceleration(mcMaxHorizontalSpeed / 16.0), mcVerticalAcceleration(0.4)
    {
    mHitBox.h = windowHeight * 0.07;
    mHitBox.w = mHitBox.h / 3 * 2;
    mHitBox.x = (windowWidth - mHitBox.w) / 2;
    mHitBox.y = windowHeight - 200;

    mWindowWidth = windowWidth;
    mWindowHeight = windowHeight;

    mHorizontalSpeed = 0;
    mVerticalSpeed = 0;
}

Doodle::~Doodle() {

}

void Doodle::Draw(Renderer &renderer) {
    SDL_SetRenderDrawColor(renderer.GetRawRenderer(), 255, 255, 255, 255);
    SDL_RenderFillRect(renderer.GetRawRenderer(), &mHitBox);
}

SDL_Rect& Doodle::GetHitBox() {
    return mHitBox;
}

void Doodle::Move() {
    if (gKeyStatesMap["right"] && !gKeyStatesMap["left"])
    {
        if (mHorizontalSpeed <= mcMaxHorizontalSpeed) mHorizontalSpeed += mcHorizontalAcceleration;
        if (mHorizontalSpeed < 0) mHorizontalSpeed = 0;
    }
    else if (!gKeyStatesMap["right"] && gKeyStatesMap["left"])
    {
        if (mHorizontalSpeed >= -mcMaxHorizontalSpeed) mHorizontalSpeed -= mcHorizontalAcceleration;
        if (mHorizontalSpeed > 0) mHorizontalSpeed = 0;
    }
    else {
        if (std::abs(mHorizontalSpeed) < 2) mHorizontalSpeed = 0;
        else mHorizontalSpeed /= 1.8;
    }

    mHitBox.x += mHorizontalSpeed;
    if (mHitBox.x + mHitBox.w / 2 < 0) mHitBox.x += mWindowWidth;
    if (mHitBox.x + mHitBox.w / 2 > mWindowWidth) mHitBox.x -= mWindowWidth;
    mHitBox.y += mVerticalSpeed;
    mVerticalSpeed += mcVerticalAcceleration;
    if (mHitBox.y + mHitBox.h > mWindowHeight) mVerticalSpeed = -15;
}