#ifndef DOODLE_JUMP_TEXTURE_H
#define DOODLE_JUMP_TEXTURE_H

#include <string>

#include "../Renderer.h"

using namespace std;

class Texture
{
public:
    Texture(Renderer &renderer, const string &path);
    ~Texture();

    void Draw(Renderer &renderer, SDL_Rect hitBox);

private:
    SDL_Texture *mTexture;
};

#endif // DOODLE_JUMP_TEXTURE_H
