#ifndef DOODLE_JUMP_EVENTHANDLER_H
#define DOODLE_JUMP_EVENTHANDLER_H

#include <map>

#include "SDL.h"

extern std::map<std::string, bool> gKeyStatesMap;

class EventHandler {
public:
    EventHandler(bool& quit);
    ~EventHandler();

    void Listen();
private:
    SDL_Event mEvent;
    bool& mQuit;
    const Uint8 *mpKeyboardStateArray;
};


#endif //DOODLE_JUMP_EVENTHANDLER_H
