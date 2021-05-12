#ifndef DOODLE_JUMP_IPLATFORM_H
#define DOODLE_JUMP_IPLATFORM_H

#include "IDrawable.h"

class IPlatform : public IDrawable {
public:
    IPlatform() {};
    virtual ~IPlatform() {};
protected:
    SDL_Rect mHitBox;
    bool mSolid;
};


#endif //DOODLE_JUMP_IPLATFORM_H
