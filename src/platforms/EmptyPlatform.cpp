#include "EmptyPlatform.h"

EmptyPlatform::EmptyPlatform(int x, int y, Renderer& renderer) : Platform(x, y, renderer) {
    mVisible = false;
}

EmptyPlatform::~EmptyPlatform() {

}

void EmptyPlatform::Draw() {

}

bool EmptyPlatform::CollisionCallback(bool isCollided) {
    return false;
}
