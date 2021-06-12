#include "Field.h"

Field::Field(bool& quit, Renderer& renderer) : Drawable(renderer), mFactory(renderer),
            mcStep(WINDOW_HEIGHT / MAX_PLATFORM_COUNT), mrProgramQuit(quit)
    {
    mHitBox.x = 0;
    mHitBox.y = 0;
    mHitBox.h = WINDOW_HEIGHT;
    mHitBox.w = WINDOW_WIDTH;
    mpFieldTexture = nullptr;
}

Field::~Field() {
    Clear();
    SDL_DestroyTexture(mpFieldTexture);
}

void Field::Draw() {
    if (!mpFieldTexture) {
        SDL_Surface *pSurface = IMG_Load("assets/textures/background.png");
        if (pSurface) {
            mpFieldTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
        }
    }
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), mpFieldTexture, NULL, &mHitBox);

    for (auto platform : mPlatforms) {
        if (platform->isVisible()) {
            platform->Draw();
        }
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
            delete toDelete;
            mPlatforms.pop_back();
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

void Field::Clear() {
    while (mPlatforms.size()) {
        Platform *pPlatform = mPlatforms.at(0);
        delete pPlatform;
        mPlatforms.pop_front();
    }
}

void Field::Refill() {
    Clear();
    mLastPosition = WINDOW_HEIGHT - mcStep;
    mPlatforms.push_front(new SimplePlatform(WINDOW_WIDTH * 0.4, mLastPosition, mrRenderer));
    mLastPosition -= mcStep;
    while (mLastPosition >= -mcStep) {
        mPlatforms.push_front(mFactory.CreatePlatform(GetRandomX(), mLastPosition));
        mLastPosition -= mcStep;
    }
}
