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
#include "Bullet.h"

Bullet::Bullet(GameObject &associated, float angle, float speed, int damage, float maxDistance, std::string sprite, float frameTime, int frameCount, bool targetsPlayer) : Component(associated)
{
    associated.AddComponent(new Sprite(associated, sprite, frameCount, frameTime));
    associated.AddComponent(new Collider(associated));

    this->speed = Vec2::Rotate(Vec2(speed, 0), angle);
    this->distanceLeft = maxDistance;
    this->damage = damage;
    this->targetsPlayer = targetsPlayer;
}

void Bullet::Update(float dt)
{
    associated.box = associated.box + speed * dt;
    this->distanceLeft -= Vec2::Mag(speed * dt);
    if (this->distanceLeft <= 0)
    {
        associated.RequestDelete();
    }
}

void Bullet::Render()
{
}

void Bullet::NotifyCollision(GameObject &other)
{
    if ((this->targetsPlayer && other.GetComponent("PenguinBody") != nullptr) || (!this->targetsPlayer && other.GetComponent("Alien") != nullptr))
    {
        associated.RequestDelete();
    }
}

bool Bullet::Is(std::string type)
{
    return (type == Bullet::type);
}

int Bullet::GetDamage()
{
    return this->damage;
}
