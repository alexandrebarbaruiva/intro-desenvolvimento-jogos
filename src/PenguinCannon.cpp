/**
 * @file PenguinCannon.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief PenguinCannon class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/PenguinCannon.h"

PenguinCannon::PenguinCannon(GameObject &associated, std::weak_ptr<GameObject> penguinBody) : Component(associated)
{
    std::cout << "penguin cannon\n";
    Sprite *sprite = new Sprite(associated, "assets/img/cubngun.png");
    associated.AddComponent(sprite);
    this->pbody = penguinBody;
    this->angle = 0;
}

void PenguinCannon::Update(float dt)
{
    if (this->pbody.lock()->IsDead())
    {
        associated.RequestDelete();
    }
    
    associated.box.setPosition(
        pbody.lock()->box.Center() - (associated.box.measures()/2)
    );
}

void PenguinCannon::Render()
{
}

bool PenguinCannon::Is(std::string type)
{
    return (type == PenguinCannon::type);
}
