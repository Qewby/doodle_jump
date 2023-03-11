#include "Texture.h"

Texture::Texture(Renderer &renderer, const string &path)
{
    SDL_Surface *pSurface = IMG_Load(path.c_str());
    if (pSurface)
    {
        mTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else
    {
        throw invalid_argument("Can't load image " + path);
    }
}

Texture::~Texture()
{
    SDL_DestroyTexture(mTexture);
}

void Texture::Draw(Renderer &renderer, SDL_Rect hitBox)
{
    SDL_RenderCopy(renderer.GetRawRenderer(), mTexture, NULL, &hitBox);
}
