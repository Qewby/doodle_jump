#ifndef DOODLE_JUMP_SIMPLEPLATFORM_H
#define DOODLE_JUMP_SIMPLEPLATFORM_H

#include "IPlatform.h"
#include "Renderer.h"
#include "Game.h"

class SimplePlatform : public IPlatform {
public:
    SimplePlatform(int x, int y);
    ~SimplePlatform();

    void Draw(Renderer &renderer) override;
};


#endif //DOODLE_JUMP_SIMPLEPLATFORM_H
