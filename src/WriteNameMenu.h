#ifndef DOODLE_JUMP_WRITENAMEMENU_H
#define DOODLE_JUMP_WRITENAMEMENU_H

#include "Drawable.h"

class WriteNameMenu : public Drawable {
public:
    WriteNameMenu(Renderer& renderer);
    ~WriteNameMenu();

    void Draw() override;

private:

};


#endif //DOODLE_JUMP_WRITENAMEMENU_H
