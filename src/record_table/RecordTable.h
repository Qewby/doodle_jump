#ifndef DOODLE_JUMP_RECORDTABLE_H
#define DOODLE_JUMP_RECORDTABLE_H

#include <fstream>
#include <array>

#include "SDL_ttf.h"

#include "IRecordTable.h"
#include "../Drawable.h"

extern unsigned long long  SCORE;
extern unsigned long long  RECORD;

extern std::pair<bool, std::pair<int, int>> gLeftMouseClickPosition;
extern std::pair<int, int> gMousePosition;

class RecordTable : public IRecordTable {
public:
    RecordTable(Renderer& renderer);
    virtual ~RecordTable();

    void ReadTable() override;
    void UpdateTable(std::string name) override;
    bool IsRecord() override;

    void Draw() override;
    bool HandleClick() override;
private:
    struct Record {
        std::string nickname = "";
        unsigned long long score = 0;
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
