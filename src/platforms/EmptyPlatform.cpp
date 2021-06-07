#include "EmptyPlatform.h"

EmptyPlatform::EmptyPlatform(int x, int y) : Platform(x, y) {
    mVisible = false;
}

EmptyPlatform::~EmptyPlatform() {

}

void EmptyPlatform::Draw(Renderer &renderer) {

}

bool EmptyPlatform::CollisionCallback(bool isCollided) {
    return false;
}
