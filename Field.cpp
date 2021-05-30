#include "Field.h"

Field::Field(bool& quit) : mcStep(WINDOW_HEIGHT / MAX_PLATFORM_COUNT), mrProgramQuit(quit) {
    mLastPosition = WINDOW_HEIGHT - mcStep;
    mPlatforms.push_front(new SimplePlatform(WINDOW_WIDTH * 0.4, mLastPosition));
    mLastPosition -= mcStep;
    while (mLastPosition >= -mcStep) {
        mPlatforms.push_front(mFactory.CreatePlatform(GetRandomX(), mLastPosition));
        mLastPosition -= mcStep;
    }

    mHitBox.x = 0;
    mHitBox.y = 0;
    mHitBox.h = WINDOW_HEIGHT;
    mHitBox.w = WINDOW_WIDTH;
    mpFieldTexture = nullptr;
}

Field::~Field() {
    for (auto platform : mPlatforms) {
        delete platform;
    }
}

void Field::Draw(Renderer &renderer) {
    if (!mpFieldTexture) {
        SDL_Surface *pSurface = IMG_Load("background.png");
        if (pSurface) {
            mpFieldTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
        }
    }
    SDL_RenderCopy(renderer.GetRawRenderer(), mpFieldTexture, NULL, &mHitBox);

    for (auto platform : mPlatforms) {
        platform->Draw(renderer);
    }
}

std::deque<Platform *>& Field::GetPlatforms() {
    return mPlatforms;
}

void Field::Shift(int value) {
    mLastPosition += value;
    for (auto platform : mPlatforms) {
        SDL_Rect& platformHitBox = platform->GetHitBox();
        platformHitBox.y += value;
        if (platformHitBox.y > WINDOW_HEIGHT) {
            Platform* toDelete = mPlatforms.back();
            mPlatforms.pop_back();
            delete toDelete;
            mPlatforms.push_front(mFactory.CreatePlatform(GetRandomX(), mLastPosition));
            mLastPosition -= mcStep;
        }
    }
    if (value > 0) SCORE += value;
    if (mPlatforms.front()->GetHitBox().y < -WINDOW_HEIGHT) mrProgramQuit = true;
}

int Field::GetRandomX() {
    std::random_device randomizer{};
    return randomizer() % static_cast<int>(WINDOW_WIDTH * 0.83);
}
