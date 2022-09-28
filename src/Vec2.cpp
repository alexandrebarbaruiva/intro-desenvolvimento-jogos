/**
 * @file Vec2.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Vec2 class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Vec2.h"

Vec2::Vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vec2::Vec2()
{
    this->x = 0;
    this->y = 0;
}

Vec2 Vec2::operator+(const Vec2 &vector) const
{
    return Vec2(this->x + vector.x, this->y + vector.y);
}

Vec2 Vec2::operator+=(const Vec2 &vector) const
{
    return *this + vector;
}

Vec2 Vec2::operator-(const Vec2 &vector) const
{
    return Vec2(this->x - vector.x, this->y - vector.y);
}

Vec2 Vec2::operator*(const float vector) const
{
    return Vec2(this->x * vector, this->y * vector);
}

float Vec2::Distance(Vec2 v1, Vec2 v2)
{
    return Mag(v1 - v2);
}

float Vec2::Atan2()
{
    return atan2(this->y, this->x);
}

float Vec2::Atan2(Vec2 v1, Vec2 v2)
{
    return atan2(v1.y, v1.x) - atan2(v2.y, v2.x);
}
