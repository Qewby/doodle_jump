#include "Field.h"

Field::Field() {
    int step = WINDOW_HEIGHT / 18;
    std::random_device randomizer{};
    int x = 0;
    for (int y = WINDOW_HEIGHT - step; y >= -step; y -= step) {
        x = randomizer() % static_cast<int>(WINDOW_WIDTH * 0.83);
        mPlatforms.push_back(new SimplePlatform(x, y));
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
    for (auto platform : mPlatforms) {
        platform->GetHitBox().y += value;
    }
}
