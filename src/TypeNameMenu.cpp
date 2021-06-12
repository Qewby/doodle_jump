#include "TypeNameMenu.h"

std::string gTypedText = "";

const int TypeNameMenu::scIndent = 5;

TypeNameMenu::TypeNameMenu(Renderer& renderer) : Drawable(renderer) {
    mLabelHitBox.w = mTypedTextHitBox.w = WINDOW_WIDTH / 4;
    mLabelHitBox.h = mTypedTextHitBox.h = WINDOW_HEIGHT / 25;

    mApplyButtonHitBox.w = mApplyButtonHitBox.w = WINDOW_WIDTH / 2;
    mApplyButtonHitBox.h = mApplyButtonHitBox.h = mApplyButtonHitBox.w / 2.5;

    mLabelHitBox.x = mApplyButtonHitBox.x = (WINDOW_WIDTH - mLabelHitBox.w) / 3;
    mTypedTextHitBox.x = mLabelHitBox.x + mLabelHitBox.w + scIndent;

    mLabelHitBox.y = mTypedTextHitBox.y = (WINDOW_HEIGHT - mLabelHitBox.h - mApplyButtonHitBox.h
            - scIndent) / 2;
    mApplyButtonHitBox.y = mLabelHitBox.y + mLabelHitBox.h + scIndent;

    mpTypedTextTexture = nullptr;
    mIsTextChange = true;
    mName = "";
    LoadTextures();
}

TypeNameMenu::~TypeNameMenu() {
    DestroyTextures();
}

void TypeNameMenu::Draw() {
    static SDL_Texture *pApplyTexture = nullptr;
    if (gMousePosition.first - mApplyButtonHitBox.x >= 0 &&
        gMousePosition.first - mApplyButtonHitBox.x <= mApplyButtonHitBox.w &&
        gMousePosition.second - mApplyButtonHitBox.y >= 0 &&
        gMousePosition.second - mApplyButtonHitBox.y <= mApplyButtonHitBox.h) {

        pApplyTexture = mpOnApplyButtonTexture;
    }
    else {
        pApplyTexture = mpApplyButtonTexture;
    }

    if (mIsTextChange) {
        if (mpTypedTextTexture) {
            SDL_DestroyTexture(mpTypedTextTexture);
        }
        SDL_Surface *pSurface;
        pSurface = TTF_RenderText_Solid(mpFont, mName.c_str(), {0, 0, 0});
        if (pSurface) {
            mpTypedTextTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
            SDL_FreeSurface(pSurface);
            mIsTextChange = false;
        }
    }

    SDL_RenderCopy(mrRenderer.GetRawRenderer(), pApplyTexture, NULL, &mApplyButtonHitBox);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), mpLabelTexture, NULL, &mLabelHitBox);
    SDL_RenderCopy(mrRenderer.GetRawRenderer(), mpTypedTextTexture, NULL, &mTypedTextHitBox);
}

void TypeNameMenu::LoadTextures() {
    SDL_Surface *pSurface;
    std::string path;

    path = "assets/fonts/font.ttf";
    mpFont = TTF_OpenFont(path.c_str(), 200);
    if (!mpFont) {
        SDL_Log("ERROR: can't load font");
    }

    path = "assets/textures/apply.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpApplyButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    path = "assets/textures/apply_on.png";
    pSurface = IMG_Load(path.c_str());
    if (pSurface) {
        mpOnApplyButtonTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't load texture: %s", path.c_str());
    }

    std::string label = "type name:";
    pSurface = TTF_RenderText_Solid(mpFont, label.c_str(), {0, 0, 0});
    if (pSurface) {
        mpLabelTexture = SDL_CreateTextureFromSurface(mrRenderer.GetRawRenderer(), pSurface);
        SDL_FreeSurface(pSurface);
    }
    else {
        SDL_Log("ERROR: can't make label texture");
    }
}

void TypeNameMenu::DestroyTextures() {
    if (mpTypedTextTexture) {
        SDL_DestroyTexture(mpTypedTextTexture);
    }
    SDL_DestroyTexture(mpLabelTexture);
    SDL_DestroyTexture(mpApplyButtonTexture);
    SDL_DestroyTexture(mpOnApplyButtonTexture);
    TTF_CloseFont(mpFont);
}

bool TypeNameMenu::HandleActions() {
    if (mName != gTypedText) {
        mName = gTypedText;
        int emptySize = 10 - mName.length();
        for (int i = 0; i < emptySize; i++) {
            mName += " ";
        }
        mIsTextChange = true;
    }

    bool isClicked = false;
    if (gLeftMouseClickPosition.first == false) return isClicked;
    if (gLeftMouseClickPosition.second.first - mApplyButtonHitBox.x >= 0 &&
        gLeftMouseClickPosition.second.first - mApplyButtonHitBox.x <= mApplyButtonHitBox.w &&
        gLeftMouseClickPosition.second.second - mApplyButtonHitBox.y >= 0 &&
        gLeftMouseClickPosition.second.second - mApplyButtonHitBox.y <= mApplyButtonHitBox.h) {

        isClicked = true;
    }
    gLeftMouseClickPosition.first = false;
    return isClicked;
}

void TypeNameMenu::Reset() {
    mName.clear();
    gTypedText.clear();
}

std::string TypeNameMenu::GetName() {
    return mName;
}


