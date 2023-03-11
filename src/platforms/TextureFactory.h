#ifndef DOODLE_JUMP_TEXTUREFACTORY_H
#define DOODLE_JUMP_TEXTUREFACTORY_H

#include <map>
#include <memory>

#include "Texture.h"

class TextureFactory
{
public:
    static shared_ptr<Texture> getTexture(Renderer &renderer, const string &path);

private:
    static map<string, shared_ptr<Texture>> sTextureCache;
};

#endif // DOODLE_JUMP_TEXTUREFACTORY_H
