#ifndef DOODLE_JUMP_DOODLE_H
#define DOODLE_JUMP_DOODLE_H

#include "IDrawable.h"
#include "EventListener.h"
#include "Game.h"

class Game;

class Doodle : public IDrawable {
public:
    Doodle();
    ~Doodle();

    void Draw(Renderer& renderer);
    SDL_Rect& GetHitBox();
    void Move();
private:
    SDL_Rect mHitBox;

    double mVerticalSpeed;
    double mHorizontalSpeed;

    const int mcMaxHorizontalSpeed;
    const double mcHorizontalAcceleration;
    const double mcVerticalAcceleration;
};


#endif //DOODLE_JUMP_DOODLE_H
