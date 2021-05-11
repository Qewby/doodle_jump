#ifndef DOODLE_JUMP_WINDOW_H
#define DOODLE_JUMP_WINDOW_H

#include <string>

#include "SDL.h"

class Window {
public:
    Window(std::string title, const int width, const int height);
    ~Window();

    SDL_Window* GetRawWindow() const;
private:
    SDL_Window *mpWindow;
    std::string mTitle;
    int mWidth;
    int mHeight;
};


#endif //DOODLE_JUMP_WINDOW_H
