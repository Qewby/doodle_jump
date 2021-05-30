#include "PlatformFactory.h"

PlatformFactory::PlatformFactory() {
    mCountEmptyInRaw = 0;
}

PlatformFactory::~PlatformFactory() {

}

Platform* PlatformFactory::CreatePlatform(int x, int y) {
    std::random_device randomizer{};
    Platform *newPlatform = nullptr;
    while (!newPlatform) {
        switch (randomizer() % 2) {
            case 0:
                newPlatform = new SimplePlatform(x, y);
                mCountEmptyInRaw = 0;
                break;
            case 1:
                if (mCountEmptyInRaw < 3) {
                    newPlatform = new EmptyPlatform(x, y);
                    mCountEmptyInRaw++;
                }
                break;
        }
    }
    return newPlatform;
}