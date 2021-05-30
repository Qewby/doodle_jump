#include "Field.h"

Field::Field(bool& quit) : mcStep(WINDOW_HEIGHT / MAX_PLATFORM_COUNT), mrProgramQuit(quit) {
    mLastPosition = WINDOW_HEIGHT - mcStep;
    mPlatforms.push_front(new SimplePlatform(WINDOW_WIDTH * 0.4, mLastPosition));
    mLastPosition -= mcStep;
    while (mLastPosition >= -mcStep) {
        mPlatforms.push_front(mFactory.CreatePlatform(GetRandomX(), mLastPosition));
        mLastPosition -= mcStep;
    }
}

Field::~Field() {
    for (auto platform : mPlatforms) {
        delete platform;
    }
}

void Field::Draw(Renderer &renderer) {
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
