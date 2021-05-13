#ifndef DOODLE_JUMP_PLATFORMFACTORY_H
#define DOODLE_JUMP_PLATFORMFACTORY_H

#include <random>

#include "SimplePlatform.h"
#include "EmptyPlatform.h"

class PlatformFactory {
public:
    PlatformFactory();
    ~PlatformFactory();

    Platform* createPlatform(int x, int y);
private:
    int mCountEmptyInRaw;
};


#endif //DOODLE_JUMP_PLATFORMFACTORY_H
