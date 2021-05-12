#ifndef DOODLE_JUMP_RENDERER_H
#define DOODLE_JUMP_RENDERER_H

#include <iostream>

#include "SDL.h"

#include "Window.h"

class Renderer {
public:
    Renderer(Window &window);
    ~Renderer();

    void ClearScreen();
    void DrawScreen();
    SDL_Renderer* GetRawRenderer() const;
private:
    SDL_Renderer *mpRenderer;
};

#endif //DOODLE_JUMP_RENDERER_H
