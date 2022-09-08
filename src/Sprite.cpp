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
    this->scale = Vec2(1, 1);
}

Sprite::Sprite(GameObject &associated, std::string file) : Sprite(associated)
{
    texture = nullptr;
    this->scale = Vec2(1, 1);
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
    dst.w = w * this->scale.x;
    dst.h = h * this->scale.y;

    if (SDL_RenderCopyEx(
            Game::GetInstance()->GetRenderer(), // renderer
            texture,                            // texture
            &clipRect,                          // source rect
            &dst,                               // destination rect
            associated.angleDeg,
            nullptr,
            SDL_FLIP_NONE))
    {
        SDL_LogError(0, "Unable to render sprite: %s", IMG_GetError());
    }
}

void Sprite::Render()
{
    this->Render(
        associated.box.x - Camera::pos.x,
        associated.box.y - Camera::pos.y,
        associated.box.w,
        associated.box.h);
}

int Sprite::GetWidth()
{
    return width * this->scale.x;
}

int Sprite::GetHeight()
{
    return height * this->scale.y;
}

void Sprite::SetScale(float scaleX, float scaleY)
{
    if (scaleX == 0)
    {
        scaleX = this->scale.x;
    }
    if (scaleY == 0)
    {
        scaleY = this->scale.y;
    }

    this->scale = Vec2(scaleX, scaleX);
}

Vec2 Sprite::GetScale()
{
    return this->scale;
}

bool Sprite::IsOpen()
{
    return (texture != nullptr);
}

void Sprite::Update(float dt)
{
}

bool Sprite::Is(std::string type)
{
    return (type == "Sprite");
}
