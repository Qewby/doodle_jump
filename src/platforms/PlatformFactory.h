#ifndef DOODLE_JUMP_PLATFORMFACTORY_H
#define DOODLE_JUMP_PLATFORMFACTORY_H

#include <random>

#include "SimplePlatform.h"
#include "EmptyPlatform.h"
#include "MovingPlatform.h"
#include "OneTimePlatform.h"
#include "OneTimeMovingPlatform.h"

class PlatformFactory {
public:
    PlatformFactory(Renderer& renderer);
    ~PlatformFactory();

    Platform* CreatePlatform(int x, int y);
private:
    int mCountEmptyInRaw;
    Renderer& mrRenderer;
};


#endif //DOODLE_JUMP_PLATFORMFACTORY_H
