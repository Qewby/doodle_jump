#include "PlatformFactory.h"

extern unsigned long long SCORE;

PlatformFactory::PlatformFactory(Renderer& renderer) : mrRenderer(renderer) {
    mCountEmptyInRaw = 1;
    MovingPlatform::SetSpeed(6);
}

PlatformFactory::~PlatformFactory() {

}

Platform* PlatformFactory::CreatePlatform(int x, int y) {
    std::random_device randomizer{};
    Platform *newPlatform = nullptr;

    int a;
    while (!newPlatform) {
        if (SCORE > 8000) {
            a = 4;
        }
        else if (SCORE > 5000) {
            a = 3;
        }
        else if (SCORE > 2000) {
            a = 2;
        }
        else {
            a = 1;
        }
        if (mCountEmptyInRaw % 4 == 0) {
            switch (randomizer() % a) {
                case 0:
                    newPlatform = new SimplePlatform(x, y, mrRenderer);
                    break;
                case 1:
                    newPlatform = new MovingPlatform(x, y, mrRenderer);
                    break;
                case 2:
                    newPlatform = new OneTimePlatform(x, y, mrRenderer);
                    break;
                case 3:
                    newPlatform = new OneTimeMovingPlatform(x, y, mrRenderer);
                    break;
            }
            mCountEmptyInRaw = 1;
        }
        else {
            newPlatform = new EmptyPlatform(x, y, mrRenderer);
            mCountEmptyInRaw++;
        }
    }
    return newPlatform;
}