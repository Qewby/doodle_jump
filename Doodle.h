#ifndef DOODLE_JUMP_DOODLE_H
#define DOODLE_JUMP_DOODLE_H

#include "IDrawable.h"
#include "Field.h"
#include "EventListener.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

class Doodle : public IDrawable {
public:
    Doodle(Field& field);
    ~Doodle();

    void Draw(Renderer& renderer);
    SDL_Rect& GetHitBox();
    void Move();
    void Jump();
    bool isFalling();
private:
    SDL_Rect mHitBox;

    Field& mrField;

    double mVerticalSpeed;
    double mHorizontalSpeed;

    const int mcMaxHorizontalSpeed;
    const double mcHorizontalAcceleration;
    const double mcVerticalAcceleration;

    const signed int mcJumpSpeed = -12;
};


#endif //DOODLE_JUMP_DOODLE_H
