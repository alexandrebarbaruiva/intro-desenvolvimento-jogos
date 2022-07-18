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

Sprite::Sprite(GameObject &associated) : Component(associated)
{
    texture = nullptr;
}

Sprite::Sprite(GameObject &associated, std::string file) : Sprite(associated)
{
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite()
{
}

void Sprite::Open(std::string file)
{
    texture = Resources::GetImage(file);
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
    SetClip(0, 0, width, height);
    associated.box.x = 0;
    associated.box.y = 0;
    associated.box.w = width;
    associated.box.h = height;
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y, int w, int h)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;

    if (SDL_RenderCopy(
            Game::GetInstance()->GetRenderer(), // renderer
            texture,                            // texture
            &clipRect,                          // source rect
            &dst                                // destination rect
            ))
    {
        SDL_LogError(0, "Unable to render sprite: %s", IMG_GetError());
    }
}

void Sprite::Render()
{
    this->Render(associated.box.x, associated.box.y, associated.box.w, associated.box.h);
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

void Sprite::Update(float dt)
{
}

bool Sprite::Is(std::string type)
{
    return (type == "Sprite");
}
