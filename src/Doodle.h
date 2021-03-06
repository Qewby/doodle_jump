#ifndef DOODLE_JUMP_DOODLE_H
#define DOODLE_JUMP_DOODLE_H

#include "Drawable.h"
#include "Field.h"
#include "EventListener.h"

class Doodle : public Drawable {
public:
    Doodle(Field& field, Renderer& renderer);
    virtual ~Doodle();

    void Draw() override;
    SDL_Rect& GetHitBox();
    void Move();
    void Jump();
    void Respawn();
    bool isFalling();
private:
    SDL_Rect mHitBox;
    SDL_Rect mTextureHitBox;
    SDL_Texture *mpDoodleTexture;

    Field& mrField;

    double mVerticalSpeed;
    double mHorizontalSpeed;

    const int mcMaxHorizontalSpeed;
    const double mcHorizontalAcceleration;
    const double mcVerticalAcceleration;
    const signed int mcJumpSpeed;
};


#endif //DOODLE_JUMP_DOODLE_H
