#ifndef DOODLE_JUMP_TYPENAMEMENU_H
#define DOODLE_JUMP_TYPENAMEMENU_H

#include "SDL_ttf.h"

#include "Drawable.h"

extern std::pair<bool, std::pair<int, int>> gLeftMouseClickPosition;
extern std::pair<int, int> gMousePosition;
extern std::string gTypedText;

class TypeNameMenu : public Drawable {
public:
    TypeNameMenu(Renderer& renderer);
    virtual ~TypeNameMenu();

    void Draw() override;

    bool HandleActions();
    void Reset();
    std::string GetName();
private:
    std::string mName;
    bool mIsTextChange;

    SDL_Rect mLabelHitBox;
    SDL_Texture *mpLabelTexture;

    SDL_Rect mTypedTextHitBox;
    SDL_Texture *mpTypedTextTexture;

    SDL_Rect mApplyButtonHitBox;
    SDL_Texture *mpApplyButtonTexture;
    SDL_Texture *mpOnApplyButtonTexture;

    TTF_Font *mpFont;

    static const int scIndent;
};


#endif //DOODLE_JUMP_TYPENAMEMENU_H
