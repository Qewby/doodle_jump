#ifndef DOODLE_JUMP_MOVINGPLATFORM_H
#define DOODLE_JUMP_MOVINGPLATFORM_H

#include "Platform.h"

class MovingPlatform : public Platform {
public:
    MovingPlatform(int x, int y);
    virtual ~MovingPlatform();

    bool CollisionCallback(bool isCollided) override;
    void Draw(Renderer &renderer) override;

    static void SetSpeed(int speed);

    static SDL_Texture *spPlatformTexture;
private:
    static int sPlatformSpeed;

    bool mIsGoingRight;
};


#endif //DOODLE_JUMP_MOVINGPLATFORM_H
