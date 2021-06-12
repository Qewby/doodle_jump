#include "PlatformFactory.h"

PlatformFactory::PlatformFactory(Renderer& renderer) : mrRenderer(renderer) {
    mCountEmptyInRaw = 0;
    MovingPlatform::SetSpeed(2);
}

PlatformFactory::~PlatformFactory() {

}

Platform* PlatformFactory::CreatePlatform(int x, int y) {
    std::random_device randomizer{};
    Platform *newPlatform = nullptr;
    while (!newPlatform) {
        switch (randomizer() % 2) {
            case 0:
                newPlatform = new OneTimeMovingPlatform(x, y, mrRenderer);
                mCountEmptyInRaw = 0;
                break;
            case 1:
                if (mCountEmptyInRaw < 3) {
                    newPlatform = new MovingPlatform(x, y, mrRenderer);
                    mCountEmptyInRaw++;
                }
                break;
        }
    }
    return newPlatform;
}