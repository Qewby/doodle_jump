#ifndef DOODLE_JUMP_COLLISIONHANDLER_H
#define DOODLE_JUMP_COLLISIONHANDLER_H

#include "Field.h"
#include "Doodle.h"

class CollisionHandler {
public:
    CollisionHandler(Field& field, Doodle& doodle);
    ~CollisionHandler();

    void Handle();
private:
    Field& mrField;
    Doodle& mrDoodle;
};


#endif //DOODLE_JUMP_COLLISIONHANDLER_H
