#include "Window.h"

Window::Window(std::string title, bool isFoolScreen, int width, int height) {
    Uint32 flags = SDL_WINDOW_SHOWN;
    if (isFoolScreen) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }
    mpWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                width, height, flags);
    if (mpWindow == NULL) throw std::bad_alloc();
}

Window::~Window() {
    SDL_DestroyWindow(mpWindow);
}

SDL_Window* Window::GetRawWindow() const {
    return mpWindow;
}