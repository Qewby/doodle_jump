#include "Window.h"

Window::Window(std::string title, const int width, const int height) {
    mWidth = width;
    mHeight = height;
    mTitle = title;
    mpWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                width, height, SDL_WINDOW_SHOWN);
    if (mpWindow == NULL) throw std::bad_alloc();
}

Window::~Window() {
    SDL_DestroyWindow(mpWindow);
}

SDL_Window* Window::GetRawWindow() const {
    return mpWindow;
}