#define SDL_MAIN_HANDLED

#include "Game.h"

int main()
{
    Game game{"Doodle jump", false};
    game.Run();

    return 0;
}
