#ifndef DOODLE_JUMP_WINDOW_H
#define DOODLE_JUMP_WINDOW_H

#include <string>

#include "SDL.h"

class Window {
public:
    Window(std::string title, bool isFoolScreen, int width, int height);
    ~Window();

    SDL_Window* GetRawWindow() const;
private:
    SDL_Window *mpWindow;
};


#endif //DOODLE_JUMP_WINDOW_H
