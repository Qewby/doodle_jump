#include "TextureFactory.h"

map<string, shared_ptr<Texture>> TextureFactory::sTextureCache;

shared_ptr<Texture> TextureFactory::getTexture(Renderer &renderer, const string &path)
{
    if (path.empty())
    {
        return nullptr;
    }
    if (!sTextureCache.count(path))
    {
        try
        {
            sTextureCache[path] = make_shared<Texture>(renderer, path);
        }
        catch (invalid_argument e)
        {
            sTextureCache[path] = nullptr;
            SDL_LogCritical(SDL_LOG_PRIORITY_CRITICAL, e.what());
        }
    }
    return sTextureCache.at(path);
}