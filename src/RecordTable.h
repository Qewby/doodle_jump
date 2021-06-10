#ifndef DOODLE_JUMP_RECORDTABLE_H
#define DOODLE_JUMP_RECORDTABLE_H

#include <fstream>
#include <array>

#include "SDL_ttf.h"

#include "IDrawable.h"

extern unsigned long long  SCORE;
extern unsigned long long  RECORD;

class RecordTable : public IDrawable {
public:
    RecordTable();
    ~RecordTable();

    void ReadTable();
    void UpdateTable(std::string name);
    bool IsRecord();

    void Draw(Renderer &renderer) override;
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

    static const int scMaxCharCount;
};


#endif //DOODLE_JUMP_RECORDTABLE_H
