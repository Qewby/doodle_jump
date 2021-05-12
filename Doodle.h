#ifndef DOODLE_JUMP_DOODLE_H
#define DOODLE_JUMP_DOODLE_H

#include "IDrawable.h"

class Doodle : public IDrawable {
public:
    Doodle(int windowWidth, int windowHeight);
    ~Doodle();

    void Draw(Renderer& renderer);
    SDL_Rect& GetHitBox();
private:
    SDL_Rect mHitBox;
};


#endif //DOODLE_JUMP_DOODLE_H
