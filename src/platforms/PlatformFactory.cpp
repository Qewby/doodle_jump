#include "PlatformFactory.h"

PlatformFactory::PlatformFactory(Renderer& renderer) : mrRenderer(renderer) {
    mCountEmptyInRaw = 1;
    MovingPlatform::SetSpeed(4);
}

PlatformFactory::~PlatformFactory() {

}

Platform* PlatformFactory::CreatePlatform(int x, int y) {
    std::random_device randomizer{};
    Platform *newPlatform = nullptr;
    while (!newPlatform) {
        if (mCountEmptyInRaw % 4 == 0) {
            switch (randomizer() % 4) {
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