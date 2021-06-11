#include "RecordTable.h"

const int RecordTable::scIndent = 5;
const int RecordTable::scMaxCharCount = 10;

RecordTable::RecordTable() : mTable() {
    mpFont = TTF_OpenFont("assets/fonts/font.ttf", 80);
    mNameHitBox.w = mScoreHitBox.w = WINDOW_WIDTH / 4;
    mNameHitBox.h = mScoreHitBox.h = WINDOW_HEIGHT / 25;
    mNameHitBox.x = mBackButtonHitBox.x = (WINDOW_WIDTH - mNameHitBox.w) / 3;
    mScoreHitBox.x = mNameHitBox.x + mNameHitBox.w + scIndent;

    mBackButtonHitBox.w = mBackButtonHitBox.w = WINDOW_WIDTH / 2;
    mBackButtonHitBox.h = mBackButtonHitBox.h = mBackButtonHitBox.w / 2.5;

    mpBackButtonTexture = nullptr;
    mpOnBackButtonTexture = nullptr;
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
    if (!mpBackButtonTexture || !mpOnBackButtonTexture) {
        SDL_Surface *pSurface;
        if (!mpBackButtonTexture) {
            pSurface = IMG_Load("assets/textures/back.png");
            if (pSurface) {
                mpBackButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
        if (!mpOnBackButtonTexture) {
            pSurface = IMG_Load("assets/textures/back_on.png");
            if (pSurface) {
                mpOnBackButtonTexture = SDL_CreateTextureFromSurface(renderer.GetRawRenderer(), pSurface);
                SDL_FreeSurface(pSurface);
            }
        }
    }

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
    mBackButtonHitBox.y = mNameHitBox.y + scIndent;

    static SDL_Texture *pPlayTexture = nullptr;
    if (gMousePosition.first - mBackButtonHitBox.x >= 0 &&
        gMousePosition.first - mBackButtonHitBox.x <= mBackButtonHitBox.w &&
        gMousePosition.second - mBackButtonHitBox.y >= 0 &&
        gMousePosition.second - mBackButtonHitBox.y <= mBackButtonHitBox.h) {

        pPlayTexture = mpOnBackButtonTexture;
    }
    else {
        pPlayTexture = mpBackButtonTexture;
    }
    SDL_RenderCopy(renderer.GetRawRenderer(), pPlayTexture, NULL, &mBackButtonHitBox);
}

bool RecordTable::HandleClick() {
    bool isClicked = false;
    if (gLeftMouseClickPosition.first == false) return isClicked;
    if (gLeftMouseClickPosition.second.first - mBackButtonHitBox.x >= 0 &&
        gLeftMouseClickPosition.second.first - mBackButtonHitBox.x <= mBackButtonHitBox.w &&
        gLeftMouseClickPosition.second.second - mBackButtonHitBox.y >= 0 &&
        gLeftMouseClickPosition.second.second - mBackButtonHitBox.y <= mBackButtonHitBox.h) {

        isClicked = true;
    }
    gLeftMouseClickPosition.first = false;
    return isClicked;
}
