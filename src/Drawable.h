#ifndef DOODLE_JUMP_DRAWABLE_H
#define DOODLE_JUMP_DRAWABLE_H

#include "Renderer.h"

extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

class Drawable {
public:
    Drawable(Renderer &renderer) : mRenderer(renderer) {};
    virtual ~Drawable() {};
    virtual void Draw() = 0;

protected:
    Renderer& mRenderer;
};


#endif //DOODLE_JUMP_DRAWABLE_H
