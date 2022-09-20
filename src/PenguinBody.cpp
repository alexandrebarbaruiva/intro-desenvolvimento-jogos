/**
 * @file Penguin.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Penguin class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/PenguinBody.h"
#include "../include/PenguinCannon.h"
#include "../include/Game.h"
#include "../include/State.h"

PenguinBody *PenguinBody::player;

PenguinBody::PenguinBody(GameObject &associated) : Component(associated)
{
    std::cout << "starter pack A\n";
    Sprite *sprite = new Sprite(associated, "assets/img/penguin.png");
    associated.AddComponent(sprite);
    this->speed = Vec2();
    this->linearSpeed = 0;
    this->angle = 0;
    this->hp = 30;
    this->player = this;
    std::cout << "starter pack B\n";
}

PenguinBody::~PenguinBody()
{
    this->player = nullptr;
}

void PenguinBody::Start()
{
    State *state = &Game::GetInstance()->GetState();
    GameObject *gameObjectPenguinCannon = new GameObject();
    PenguinCannon *penguinCannon = new PenguinCannon(*gameObjectPenguinCannon, state->GetObject(&associated));
    gameObjectPenguinCannon->AddComponent(penguinCannon);
    this->pcannon = state->AddObject(gameObjectPenguinCannon);
}

void PenguinBody::Update(float dt)
{
    if (this->hp <= 0)
    {
        associated.RequestDelete();
    }
    InputManager instance = InputManager::GetInstance();
    if (instance.IsKeyDown(W_KEY))
    {
        speed += Vec2(1, 0);
    }
    else if (instance.IsKeyDown(S_KEY))
    {
        speed -= Vec2(1, 0);
    }
    // else
    // {
    //     speed = Vec2(1, 0);
    // }
    if (instance.IsKeyDown(A_KEY))
    {
        speed += speed.GetRotated(M_PI/90);
    }
    if (instance.IsKeyDown(D_KEY))
    {
        speed += speed.GetRotated(-M_PI/90);
    }
    associated.box += speed * dt;
    associated.angleDeg = speed.atan() * 90 / M_PI;
}

void PenguinBody::Render()
{
}

bool PenguinBody::Is(std::string type)
{
    return (type == PenguinBody::type);
}
