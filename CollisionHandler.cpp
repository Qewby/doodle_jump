#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(Field &field, Doodle &doodle) : mrField(field), mrDoodle(doodle) {

}

CollisionHandler::~CollisionHandler() {

}

void CollisionHandler::Handle() {
    SDL_Rect doodleHitBox = mrDoodle.GetHitBox();
    for (auto platform : mrField.GetPlatforms()) {
        bool isCollided = false;
        SDL_Rect platformHitBox = platform->GetHitBox();
        if (mrDoodle.isFalling() &&
            platformHitBox.y - doodleHitBox.y < doodleHitBox.h &&
            platformHitBox.y - doodleHitBox.y > platformHitBox.h * 1.4 &&
            doodleHitBox.x + doodleHitBox.w > platformHitBox.x &&
            doodleHitBox.x < platformHitBox.x + platformHitBox.w)
        {
            isCollided = true;
            if (platform->CollisionCallback(isCollided)) {
                mrDoodle.Jump();
                return;
            }
        }
    }
}
