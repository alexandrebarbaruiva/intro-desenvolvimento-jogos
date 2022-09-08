/**
 * @file Rect.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Rectangle class header file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef RECT_HEADER
#define RECT_HEADER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Vec2.h"

class Rect
{
private:
    /* data */
public:
    Rect(/* args */);
    Rect(float x, float y, float w, float h);
    ~Rect();
    float x;
    float y;
    float w;
    float h;
    bool Contains(Vec2 vector);
    Vec2 Center();
    Vec2 toVec2();
    Vec2 measures();
    void setPosition(Vec2 vector);
    Rect operator+(Vec2 const &vector);
    Rect operator+=(Vec2 const &vector);
};

#endif