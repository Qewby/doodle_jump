#include "Doodle.h"

Doodle::Doodle(Field& field) : mrField(field), mcMaxHorizontalSpeed(WINDOW_WIDTH * 0.015),
    mcHorizontalAcceleration(mcMaxHorizontalSpeed / 16.0), mcVerticalAcceleration(WINDOW_HEIGHT / 2780.0),
    mcJumpSpeed(-(mcVerticalAcceleration * 35))
    {
    mHitBox.h = WINDOW_HEIGHT * 0.07;
    mHitBox.w = mHitBox.h * 4 / 5;
    mHitBox.x = (WINDOW_WIDTH - mHitBox.w) / 2;
    mHitBox.y = WINDOW_HEIGHT - mHitBox.h - 1;

    mTextureHitBox.h = mHitBox.h;
    mTextureHitBox.w = mHitBox.h;

    mHorizontalSpeed = 0;
    Jump();
}

Doodle::~Doodle() {

}

void Doodle::Draw(Renderer &renderer) {
    static bool firstDraw = true;
    if (firstDraw) {
        SDL_Surface *pSurface = IMG_Load("ninja.png");
        if (pSurface) {
            mpDoodleTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
        }
        firstDraw = false;
    }

    static SDL_RendererFlip flip = SDL_FLIP_NONE;
    if (gKeyStatesMap["right"] && !gKeyStatesMap["left"]) {
        flip = SDL_FLIP_NONE;

    }
    else if (!gKeyStatesMap["right"] && gKeyStatesMap["left"]) {
        flip = SDL_FLIP_HORIZONTAL;
    }
    if (flip == SDL_FLIP_NONE) {
        mTextureHitBox.x = mHitBox.x;
    }
    else {
        mTextureHitBox.x = mHitBox.x - (mTextureHitBox.w - mHitBox.w);
    }
    mTextureHitBox.y = mHitBox.y;
    /*SDL_SetRenderDrawColor(renderer.GetRawRenderer(), 255, 0, 0, 255);
    SDL_RenderFillRect(renderer.GetRawRenderer(), &mTextureHitBox);
    SDL_SetRenderDrawColor(renderer.GetRawRenderer(), 0, 0, 255, 255);
    SDL_RenderFillRect(renderer.GetRawRenderer(), &mHitBox);*/
    SDL_RenderCopyEx(renderer.GetRawRenderer(), mpDoodleTexture, NULL,
                     &mTextureHitBox, 0, NULL, flip);
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
    if (mHitBox.y < WINDOW_HEIGHT / 2) {
        mrField.Shift(WINDOW_HEIGHT / 2 - mHitBox.y);
        mHitBox.y = WINDOW_HEIGHT / 2;
    }
    else if (mHitBox.y + mHitBox.h > WINDOW_HEIGHT) {
        mrField.Shift(-mVerticalSpeed);
        mHitBox.y = WINDOW_HEIGHT - mHitBox.h - 1;;
    }
    else {
        mrField.Shift(0);
    }
}

void Doodle::Jump() {
    mVerticalSpeed = mcJumpSpeed;
}

bool Doodle::isFalling() {
    return mVerticalSpeed >= 0;
}