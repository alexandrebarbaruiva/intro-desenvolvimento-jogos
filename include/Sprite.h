/**
 * @file Sprite.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Sprite class header file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef SPRITE_HEADER
#define SPRITE_HEADER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include "Component.h"
#include "Timer.h"
#include <string>
#include <memory>

class Sprite : public Component
{
private:
    std::shared_ptr<SDL_Texture> texture;
    int width;
    int height;
    SDL_Rect clipRect;
    Vec2 scale;

    int frameCount;
    int currentFrame;
    float timeElapsed;
    float frameTime;

    float secondsToSelfDestruct;
    Timer selfDestructCount;

public:
    Sprite(GameObject &associated, int frameCount, float frameTime, float secondsToSelfDestruct = 0);
    Sprite(GameObject &associated, std::string file, int frameCount = 1, float frameTime = 1, float secondsToSelfDestruct = 0);
    ~Sprite();

    std::string type = "Sprite";

    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    void Render();

    void SetFrame(int frame);
    void SetFrameCount(int frameCount);
    void SetFrameTime(float frameTime);

    int GetWidth();
    int GetHeight();
    void SetScale(float scaleX, float scaleY);
    Vec2 GetScale();

    bool IsOpen();

    void Update(float dt);
    bool Is(std::string type);
    void NotifyCollision(GameObject &other);
};

#endif
