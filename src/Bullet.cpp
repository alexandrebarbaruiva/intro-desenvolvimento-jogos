/**
 * @file Bullet.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Bullet class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/Bullet.h"

Bullet::Bullet(GameObject &associated, float angle, float speed, int damage, float maxDistance, std::string sprite) : Component(associated)
{
    Sprite *spriteObj = new Sprite(associated, sprite);
    associated.AddComponent(spriteObj);
    this->speed = Vec2(1, 0).GetRotated(angle) * speed;
    this->distanceLeft = maxDistance;
    this->damage = damage;
}

void Bullet::Start() {
    
}

void Bullet::Update(float dt)
{
    associated.box += (speed * dt);
    distanceLeft -= (speed * dt).magnitude();
    if (distanceLeft <= 0)
    {
        associated.RequestDelete();
    }
}

void Bullet::Render()
{
}

bool Bullet::Is(std::string type)
{
    return (type == Bullet::type);
}

int Bullet::GetDamage()
{
    return this->damage;
}
