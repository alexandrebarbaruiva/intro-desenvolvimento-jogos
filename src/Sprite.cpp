/**
 * @file Sprite.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Sprite class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/Sprite.h"
#include "../include/Game.h"
#include <string>

Sprite::Sprite()
{
    texture = nullptr;
}

Sprite::Sprite(std::string file)
{
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file)
{
    if (IsOpen())
    {
        texture = nullptr;
    }
    texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), file.c_str());
    if (!IsOpen())
    {
        SDL_LogError(0, "Unable to load texture: %s", IMG_GetError());
    }
    if (SDL_QueryTexture(
            texture, // texture
            nullptr, // format
            nullptr, // access
            &width,  // width
            &height  // height
            ) != 0)
    {
        SDL_LogError(0, "Unable to query texture: %s", IMG_GetError());
    }
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = clipRect.w;
    dst.h = clipRect.h;

    if (SDL_RenderCopy(
        Game::GetInstance()->GetRenderer(), // renderer
        texture,                            // texture
        &clipRect,                           // source rect
        &dst                                 // destination rect
    )){
        SDL_LogError(0, "Unable to render copy: %s", IMG_GetError());
    }
}

int Sprite::GetWidth()
{
    return width;
}

int Sprite::GetHeight()
{
    return height;
}

bool Sprite::IsOpen()
{
    if (texture != nullptr)
    {
        return true;
    }
    return false;
}