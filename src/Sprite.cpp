#include "Game.h"
#include "Resources.h"
#include "Camera.h"
#include "Sprite.h"
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"

Sprite::Sprite(GameObject &associated, int frameCount, float frameTime, float secondsToSelfDestruct) : Component(associated), selfDestructCount()
{
    this->texture = nullptr;
    this->frameCount = frameCount;
    this->frameTime = frameTime;
    this->secondsToSelfDestruct = secondsToSelfDestruct;
    this->currentFrame = 0;
    this->timeElapsed = 0;
}

Sprite::Sprite(GameObject &associated, std::string file, int frameCount, float frameTime, float secondsToSelfDestruct) : Component(associated), selfDestructCount()
{
    this->texture = nullptr;
    this->scale = {1, 1};
    this->frameCount = frameCount;
    this->frameTime = frameTime;
    this->secondsToSelfDestruct = secondsToSelfDestruct;
    this->currentFrame = 0;
    this->timeElapsed = 0;
    Open(file);
}

Sprite::~Sprite()
{
}

void Sprite::Open(std::string file)
{
    texture = Resources::GetImage(file);

    if (texture == nullptr)
    {
        SDL_Log("Cant load sprite: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_QueryTexture(texture.get(), nullptr, nullptr, &width, &height);
    associated.box.w = width / frameCount;
    associated.box.h = height;
    SetClip(0, 0, GetWidth(), GetHeight());
}

void Sprite::SetClip(int x, int y, int w, int h)
{
    clipRect.h = h;
    clipRect.w = w;
    clipRect.x = x;
    clipRect.y = y;
}

void Sprite::Update(float dt)
{
    timeElapsed += dt;
    if (timeElapsed > frameTime)
    {
        currentFrame++;
        timeElapsed = 0;
        if (currentFrame >= frameCount)
        {
            currentFrame = 0;
        }
        SetClip((currentFrame)*GetWidth(), 0, GetWidth(), GetHeight());
    }

    if (secondsToSelfDestruct > 0)
    {
        selfDestructCount.Update(dt);
        if (selfDestructCount.Get() > secondsToSelfDestruct)
        {
            associated.RequestDelete();
        }
    }
}

bool Sprite::Is(std::string type)
{
    return (type == Sprite::type);
}

void Sprite::Render(int x, int y)
{
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w * scale.x;
    dstrect.h = clipRect.h * scale.y;

    SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture.get(), &clipRect, &dstrect, associated.angleDeg, nullptr, SDL_FLIP_NONE);
}

void Sprite::Render()
{
    Render(associated.box.x - Camera::pos.x, associated.box.y - Camera::pos.y);
}

void Sprite::NotifyCollision(GameObject &other)
{
}

void Sprite::SetScale(float scaleX, float scaleY)
{
    float widthChange = associated.box.w * (scaleX - scale.x);
    float heightChange = associated.box.h * (scaleY - scale.y);

    associated.box.w *= (1 + (scaleX - scale.x));
    associated.box.h *= (1 + (scaleY - scale.y));
    associated.box.x -= widthChange / 2;
    associated.box.y -= heightChange / 2;

    scale = {scaleX, scaleY};
}

void Sprite::SetFrame(int frame)
{
    if (frame < this->frameCount)
    {
        this->currentFrame = frame;
        SetClip((this->currentFrame) * GetWidth(), 0, GetWidth(), GetHeight());
    }
}

void Sprite::SetFrameCount(int frameCount)
{
    this->frameCount = frameCount;
    this->currentFrame = 0;
}

void Sprite::SetFrameTime(float frameTime)
{
    this->frameTime = frameTime;
}

Vec2 Sprite::GetScale()
{
    return this->scale;
}

int Sprite::GetWidth()
{
    return this->width / this->frameCount;
}

int Sprite::GetHeight()
{
    return this->height;
}

bool Sprite::IsOpen()
{
    return this->texture != nullptr;
}
