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
#include <cmath>
#define PI M_PI

class Vec2
{
private:
    /* data */
public:
    float x;
    float y;

    Vec2();
    Vec2(float x, float y);

    Vec2 operator+(const Vec2 &vector) const;
    Vec2 operator+=(const Vec2 &vector) const;
    Vec2 operator-(const Vec2 &vector) const;
    Vec2 operator*(const float vector) const;

    static float Distance(Vec2 v1, Vec2 v2);
    static float Atan2(Vec2 v1, Vec2 v2);
    float Atan2();

    static inline float Mag(const Vec2 &vec)
    {
        return sqrt(vec.x * vec.x + vec.y * vec.y);
    }

    static inline Vec2 Normalize(const Vec2 &vec)
    {
        return vec * (1.f / Mag(vec));
    }

    static inline float Dot(const Vec2 &v1, const Vec2 &v2)
    {
        return v1.x * v2.x + v1.y * v2.y;
    }

    static inline Vec2 Rotate(const Vec2 &vec, float angle)
    {
        return Vec2(
            vec.x * cos(angle) - vec.y * sin(angle),
            vec.y * cos(angle) + vec.x * sin(angle));
    }
};
#endif