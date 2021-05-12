#include "EventHandler.h"

std::map<std::string, bool> gKeyStatesMap;

EventHandler::EventHandler(bool& quit) : mQuit(quit) {
    mpKeyboardStateArray = SDL_GetKeyboardState(NULL);
}

EventHandler::~EventHandler() {

}

void EventHandler::Listen() {
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
        }
    }
}