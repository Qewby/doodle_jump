#include "Renderer.h"

Renderer::Renderer(Window &window) {
    mpRenderer = SDL_CreateRenderer(window.GetRawWindow(), -1, SDL_RENDERER_ACCELERATED);
    if (mpRenderer == NULL) {
        std::cerr << "Can't create renderer: " << SDL_GetError() << std::endl;
        throw std::bad_alloc();
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(mpRenderer);
}

SDL_Renderer* Renderer::GetRawRenderer() const {
    return mpRenderer;
}

void Renderer::ClearScreen() {
    SDL_SetRenderDrawColor(mpRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mpRenderer);
}

void Renderer::DrawScreen() {
    SDL_RenderPresent(mpRenderer);
}