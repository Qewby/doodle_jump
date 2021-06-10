#ifndef DOODLE_JUMP_IDRAWABLE_H
#define DOODLE_JUMP_IDRAWABLE_H

#include "Renderer.h"

extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

class IDrawable {
public:
    IDrawable() {};
    virtual ~IDrawable() {};
    virtual void Draw(Renderer& renderer) = 0;
};


#endif //DOODLE_JUMP_IDRAWABLE_H
