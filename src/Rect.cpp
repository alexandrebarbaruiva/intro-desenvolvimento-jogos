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
    this->x = 0;
    this->y = 0;
    this->w = 0;
    this->h = 0;
}

Rect::Rect(float x, float y, float w, float h)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

Rect::~Rect()
{
}

bool Rect::Contains(Vec2 vector)
{
    bool vectorInsideX = (vector.x > this->x) && (vector.x < (this->x + this->w));
    bool vectorInsideY = (vector.y > this->y) && (vector.y < (this->y + this->h));
    return (vectorInsideX && vectorInsideY);
}

Vec2 Rect::Center()
{
    return Vec2((this->x + this->w / 2), (this->y + this->h / 2));
}

Vec2 Rect::toVec2()
{
    return Vec2(this->x, this->y);
}

Vec2 Rect::measures()
{
    return Vec2(this->w, this->h);
}

void Rect::setPosition(Vec2 vector) {
    this->x = vector.x;
    this->y = vector.y;
}

Rect Rect::operator+(Vec2 const &vector)
{
    float newX = this->x + vector.x;
    float newY = this->y + vector.y;
    Rect newRect = Rect(
        newX,
        newY,
        this->w,
        this->h);
    return newRect;
}

Rect Rect::operator+=(Vec2 const &vector)
{
    *this = *this + vector;
    return *this;
}
