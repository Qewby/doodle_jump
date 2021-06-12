#ifndef DOODLE_JUMP_MOVINGPLATFORM_H
#define DOODLE_JUMP_MOVINGPLATFORM_H

#include "Platform.h"

class MovingPlatform : public Platform {
public:
    MovingPlatform(int x, int y, Renderer& renderer);
    virtual ~MovingPlatform();

    virtual bool CollisionCallback(bool isCollided) override;
    virtual void Draw() override;

    static void SetSpeed(int speed);

    static SDL_Texture *spPlatformTexture;
private:
    static int sPlatformSpeed;

    bool mIsGoingRight;
};


#endif //DOODLE_JUMP_MOVINGPLATFORM_H
