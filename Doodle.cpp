#include "Doodle.h"

Doodle::Doodle() : mcMaxHorizontalSpeed(WINDOW_WIDTH * 0.015),
    mcHorizontalAcceleration(mcMaxHorizontalSpeed / 16.0), mcVerticalAcceleration(0.4)
    {
    mHitBox.h = WINDOW_HEIGHT * 0.07;
    mHitBox.w = mHitBox.h / 3 * 2;
    mHitBox.x = (WINDOW_WIDTH - mHitBox.w) / 2;
    mHitBox.y = WINDOW_HEIGHT;

    mHorizontalSpeed = 0;
    Jump();
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
    if (mHitBox.x + mHitBox.w / 2 < 0) mHitBox.x += WINDOW_WIDTH;
    if (mHitBox.x + mHitBox.w / 2 > WINDOW_WIDTH) mHitBox.x -= WINDOW_WIDTH;
    mHitBox.y += mVerticalSpeed;
    mVerticalSpeed += mcVerticalAcceleration;
}

void Doodle::Jump() {
    mVerticalSpeed = mcJumpSpeed;
}

bool Doodle::isFalling() {
    return mVerticalSpeed >= 0;
}