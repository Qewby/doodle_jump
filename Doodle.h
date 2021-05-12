#ifndef DOODLE_JUMP_DOODLE_H
#define DOODLE_JUMP_DOODLE_H

#include "IDrawable.h"
#include "EventHandler.h"

class Doodle : public IDrawable {
public:
    Doodle(int windowWidth, int windowHeight);
    ~Doodle();

    void Draw(Renderer& renderer);
    SDL_Rect& GetHitBox();
    void Move();
private:
    SDL_Rect mHitBox;

    int mWindowWidth;
    int mWindowHeight;

    double mVerticalSpeed;
    double mHorizontalSpeed;

    const int mcMaxHorizontalSpeed;
    const double mcHorizontalAcceleration;
    const double mcVerticalAcceleration;
};


#endif //DOODLE_JUMP_DOODLE_H
