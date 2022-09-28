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
#include "Vec2.h"

class Rect
{
private:
    /* data */
public:
    Rect(/* args */);
    Rect(float x, float y, float w, float h);

    float x;
    float y;
    float w;
    float h;

    Vec2 Center();
    Vec2 Origin();
    Vec2 End();
    void SetOrigin(Vec2 vector);
    void SetCenter(Vec2 vector);
    static float Distance(Rect r1, Rect r2);
    Rect operator+(const Vec2 &vector) const;
    Rect operator+=(const Vec2 &vector) const;
};

#endif
