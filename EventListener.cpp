#include "EventListener.h"

std::map<std::string, bool> gKeyStatesMap{};
std::pair<int, int> gLeftMouseClickPosition{};
std::pair<int, int> gMousePosition{};

EventListener::EventListener(bool& quit) : mQuit(quit) {
    mpKeyboardStateArray = SDL_GetKeyboardState(NULL);
}

EventListener::~EventListener() {

}

void EventListener::Listen() {
    while(SDL_PollEvent(&mEvent))
    {
        switch (mEvent.type) {
            case SDL_QUIT:
                mQuit = true;
                break;
            case SDL_KEYDOWN:
            case SDL_KEYUP:
                gKeyStatesMap["left"] = mpKeyboardStateArray[SDL_SCANCODE_LEFT] || mpKeyboardStateArray[SDL_SCANCODE_A];
                gKeyStatesMap["right"] = mpKeyboardStateArray[SDL_SCANCODE_RIGHT] || mpKeyboardStateArray[SDL_SCANCODE_D];
                break;
            case SDL_MOUSEBUTTONUP:
                if (mEvent.button.button == SDL_BUTTON_LEFT) {
                    gLeftMouseClickPosition = {mEvent.button.x, mEvent.button.y};
                    SDL_Log("%d, %d", gLeftMouseClickPosition.first,
                            gLeftMouseClickPosition.second);
                }
            case SDL_MOUSEMOTION:
                gMousePosition = {mEvent.motion.x, mEvent.motion.y};
        }
    }
}