#include "RecordTable.h"

const int RecordTable::scIndent = 5;
const int RecordTable::scMaxCharCount = 10;

RecordTable::RecordTable() : mTable() {
    mpFont = TTF_OpenFont("assets/fonts/font.ttf", 80);
    mNameHitBox.w = mScoreHitBox.w = WINDOW_WIDTH / 4;
    mNameHitBox.h = mScoreHitBox.h = WINDOW_HEIGHT / 25;
    mNameHitBox.x = (WINDOW_WIDTH - mNameHitBox.w) / 3;
    mScoreHitBox.x = mNameHitBox.x + mNameHitBox.w + scIndent;
}

RecordTable::~RecordTable() {
    TTF_CloseFont(mpFont);
}

void RecordTable::ReadTable() {
    std::ifstream record_file;
    record_file.open("assets/data/record", std::ios::in);
    mTable.fill(Record{"-", 0});
    if (!record_file) {
        RECORD = 0;
    }
    else {
        for (int i = 0; i < mTable.size() && !record_file.eof(); i++) {
            Record record;
            record_file >> record.nickname >> record.score;
            if (!record.score) record.nickname = "-";
            mTable[i] = record;
        }
        RECORD = mTable.front().score;
        record_file.close();
    }
}

void RecordTable::UpdateTable(std::string name) {
    if (IsRecord()) {
        int i;
        for (i = 0; i < mTable.size(); i++) {
            if (SCORE > mTable[i].score) {
                for (int j = mTable.size() - 1; j > i; j--) {
                    mTable[j].nickname = mTable[j - 1].nickname;
                    mTable[j].score = mTable[j - 1].score;
                }
                mTable[i].score = SCORE;
                mTable[i].nickname = name;
                break;
            }
        }
        RECORD = mTable.front().score;


        std::ofstream record_file;
        record_file.open("assets/data/record", std::ios::out);
        if (record_file) {
            for (auto record : mTable) {
                record_file << record.nickname << " " << record.score << "\n";
            }
            record_file.close();
        }
    }
}

bool RecordTable::IsRecord() {
    return SCORE > mTable.back().score;
}

void RecordTable::Draw(Renderer &renderer) {
    mNameHitBox.y = mScoreHitBox.y = (WINDOW_HEIGHT - ((mNameHitBox.h + scIndent) * mTable.size() - scIndent)) / 2;
    for (auto record : mTable) {
        std::string scoreText = std::to_string(record.score);
        int emptySize = scMaxCharCount - scoreText.length();
        for (int i = 0; i < emptySize; i++) {
            scoreText += " ";
        }

        std::string nicknameText = record.nickname;
        emptySize = scMaxCharCount - nicknameText.length();
        for (int i = 0; i < emptySize; i++) {
            nicknameText += " ";
        }

        mpSurface = TTF_RenderText_Solid(mpFont, nicknameText.c_str(), {0, 0, 0});
        mpTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), mpSurface);
        SDL_RenderCopy(renderer.GetRawRenderer(), mpTexture, NULL, &mNameHitBox);
        SDL_FreeSurface(mpSurface);
        SDL_DestroyTexture(mpTexture);

        mpSurface = TTF_RenderText_Solid(mpFont, scoreText.c_str(), {0, 0, 0});
        mpTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), mpSurface);
        SDL_RenderCopy(renderer.GetRawRenderer(), mpTexture, NULL, &mScoreHitBox);
        SDL_FreeSurface(mpSurface);
        SDL_DestroyTexture(mpTexture);

        mNameHitBox.y = mScoreHitBox.y = mNameHitBox.y + mNameHitBox.h + scIndent;
    }
}
