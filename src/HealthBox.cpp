/**
 * @file HealthBox.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief HealthBox class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "HealthBox.h"
#include "Sprite.h"
#include "Collider.h"

HealthBox::HealthBox(GameObject &associated) : Component(associated)
{
    this->healEffect = 100;
    associated.AddComponent(new Sprite(associated, "assets/img/health.png", 1, 1.0));
    associated.AddComponent(new Collider(associated));
}

void HealthBox::Update(float dt)
{
}

void HealthBox::Render()
{
}

void HealthBox::NotifyCollision(GameObject &other)
{
    if (other.GetComponent("PenguinBody") != nullptr)
    {
        associated.RequestDelete();
    }
}

bool HealthBox::Is(std::string type)
{
    return (type == HealthBox::type);
}

int HealthBox::GetHealth()
{
    return healEffect;
}
