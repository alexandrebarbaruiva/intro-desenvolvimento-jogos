/**
 * @file Vec2.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief 2D Vector class header file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef VEC2_HEADER
#define VEC2_HEADER
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"

class Vec2
{
private:
    /* data */
public:
    Vec2(float x, float y);
    Vec2();
    ~Vec2();

    float x;
    float y;

    Vec2 GetRotated(float rotation);

    Vec2 operator+(Vec2 const &vector);
    Vec2 operator+=(Vec2 const &vector);
    Vec2 operator*(float value);
};

#endif

// Links
// https://www.geeksforgeeks.org/operator-overloading-c/