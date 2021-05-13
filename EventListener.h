#ifndef DOODLE_JUMP_EVENTLISTENER_H
#define DOODLE_JUMP_EVENTLISTENER_H

#include <map>

#include "SDL.h"

extern std::map<std::string, bool> gKeyStatesMap;

class EventListener {
public:
    EventListener(bool& quit);
    ~EventListener();

    void Listen();
private:
    SDL_Event mEvent;
    bool& mQuit;
    const Uint8 *mpKeyboardStateArray;
};


#endif //DOODLE_JUMP_EVENTLISTENER_H
