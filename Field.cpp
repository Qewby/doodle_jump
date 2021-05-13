#include "Field.h"

Field::Field() : mcStep(WINDOW_HEIGHT / MAX_PLATFORM_COUNT) {
    mLastPosition = WINDOW_HEIGHT - mcStep;
    mPlatforms.push_front(new SimplePlatform(WINDOW_WIDTH * 0.4, mLastPosition));
    mLastPosition -= mcStep;
    while (mLastPosition >= -mcStep) {
        mPlatforms.push_front(mFactory.createPlatform(GetRandomX(), mLastPosition));
        mLastPosition -= mcStep;
    }
}

Field::~Field() {

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
    SCORE += value;
    mLastPosition += value;
    for (auto platform : mPlatforms) {
        SDL_Rect& platformHitBox = platform->GetHitBox();
        platformHitBox.y += value;
        if (platformHitBox.y > WINDOW_HEIGHT) {
            Platform* toDelete = mPlatforms.back();
            mPlatforms.pop_back();
            delete toDelete;
            mPlatforms.push_front(mFactory.createPlatform(GetRandomX(), mLastPosition));
            mLastPosition -= mcStep;
        }
    }
}

int Field::GetRandomX() {
    std::random_device randomizer{};
    return randomizer() % static_cast<int>(WINDOW_WIDTH * 0.83);
}
