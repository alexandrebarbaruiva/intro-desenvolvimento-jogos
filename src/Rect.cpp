/**
 * @file Rect.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Rect class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/Rect.h"

Rect::Rect(/* args */)
{
}

Rect::~Rect()
{
}

bool Rect::Contains(Vec2 vector)
{
    bool vectorInsideX = (vector.x > this->x) && (vector.x < (this->x + this->w));
    bool vectorInsideY = (vector.y > this->y) && (vector.y < (this->y + this->h));
    if (vectorInsideX && vectorInsideY)
    {
        return true;
    }
    return false;
}

Vec2 Rect::Center()
{
    return Vec2(((x + w) / 2), ((y + h) / 2));
}