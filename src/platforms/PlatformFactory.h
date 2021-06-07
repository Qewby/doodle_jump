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
    PlatformFactory();
    ~PlatformFactory();

    Platform* CreatePlatform(int x, int y);
private:
    int mCountEmptyInRaw;
};


#endif //DOODLE_JUMP_PLATFORMFACTORY_H
