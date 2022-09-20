/**
 * @file Bullet.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Bullet class header file
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef BULLET_HEADER
#define BULLET_HEADER
#include "Component.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Vec2.h"
#include <vector>
#include <cmath>
#include <string>

class Bullet : public Component
{
private:
    Vec2 speed;
    float distanceLeft;
    int damage;

public:
    Bullet(GameObject &associated, float angle, float speed, int damage, float maxDistance, std::string sprite, int frameCount, int frameTime);

    std::string type = "Bullet";

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    int GetDamage();
};

#endif
