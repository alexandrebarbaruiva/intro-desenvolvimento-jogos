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
#include "../include/Vec2.h"

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

Vec2::~Vec2()
{
}

Vec2 Vec2::GetRotated(float rotation)
{
    float newX = ((x * cos(rotation)) - (y * sin(rotation)));
    float newY = ((y * cos(rotation)) - (x * sin(rotation)));
    return Vec2(newX, newY);
}

Vec2 Vec2::operator+(Vec2 const &vector)
{
    Vec2 newVector = Vec2(0, 0);
    newVector.x = this->x + vector.x;
    newVector.y = this->y + vector.y;
    return newVector;
}

Vec2 Vec2::operator-(Vec2 const &vector)
{
    Vec2 newVector = Vec2(0, 0);
    newVector.x = this->x - vector.x;
    newVector.y = this->y - vector.y;
    return newVector;
}

Vec2 Vec2::operator+=(Vec2 const &vector)
{
    *this = *this + vector;
    return *this;
}

Vec2 Vec2::operator*(float value)
{
    Vec2 newVector = Vec2(0, 0);
    newVector.x = this->x * value;
    newVector.y = this->y * value;
    return newVector;
}

Vec2 Vec2::operator/(float value)
{
    Vec2 newVector = Vec2(0, 0);
    if (value != 0.0)
    {
        newVector.x = this->x / value;
        newVector.y = this->y / value;
    }
    return newVector;
}

float Vec2::atan() {
    return atan2(this->y, this->x);
}

float Vec2::direct(Vec2 &vector) {
    Vec2 result = (vector - *this);
    return -atan2(result.y, result.x);
}

Vec2 Vec2::normalize()
{
    float mag = this->magnitude();
    return Vec2(
        (this->x / mag),
        (this->y / mag));
}

float Vec2::magnitude()
{
    return sqrt((pow(this->x, 2)) + (pow(this->y, 2)));
}

float Vec2::distanceTo(Vec2 &vector)
{
    return (*this - vector).magnitude();
}
