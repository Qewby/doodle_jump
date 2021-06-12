#ifndef DOODLE_JUMP_RECORDTABLE_H
#define DOODLE_JUMP_RECORDTABLE_H

#include <fstream>
#include <array>

#include "SDL_ttf.h"

#include "Drawable.h"

extern unsigned long long  SCORE;
extern unsigned long long  RECORD;

extern std::pair<bool, std::pair<int, int>> gLeftMouseClickPosition;
extern std::pair<int, int> gMousePosition;

class RecordTable : public Drawable {
public:
    RecordTable(Renderer& renderer);
    virtual ~RecordTable();

    void ReadTable();
    void UpdateTable(std::string name);
    bool IsRecord();

    void Draw() override;
    bool HandleClick();
private:
    struct Record {
        std::string nickname;
        unsigned long long score;
    };
    std::array<Record, 5> mTable;

    static const int scIndent;
    TTF_Font *mpFont;
    SDL_Rect mNameHitBox;
    SDL_Rect mScoreHitBox;
    SDL_Surface *mpSurface;
    SDL_Texture *mpTexture;

    SDL_Rect mBackButtonHitBox;
    SDL_Texture *mpBackButtonTexture;
    SDL_Texture *mpOnBackButtonTexture;

    static const int scMaxCharCount;
};


#endif //DOODLE_JUMP_RECORDTABLE_H
