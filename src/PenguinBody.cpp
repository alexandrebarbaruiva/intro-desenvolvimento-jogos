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
#include "PenguinBody.h"

PenguinBody *PenguinBody::player;
PenguinBody::PenguinBody(GameObject &associated) : Component(associated)
{
    this->player = this;
    this->hp = PENGUIN_HP;
    this->angle = 0;
    this->linearSpeed = 0;
    this->speed = {1, 0};
    associated.AddComponent(new Sprite(associated, "assets/img/penguin.png", 1, 1.0));
    associated.AddComponent(new Collider(associated));
}

PenguinBody::~PenguinBody()
{
    this->player = nullptr;
}

void PenguinBody::Start()
{
    GameObject *go = new GameObject();
    go->AddComponent(
        new PenguinCannon(
            *go, Game::GetInstance().GetCurrentState().GetObjectPtr(&associated)));
    this->pcannon = Game::GetInstance().GetCurrentState().AddObject(go);
}

void PenguinBody::Update(float dt)
{
    if (InputManager::GetInstance().IsKeyDown(W_KEY))
    {
        linearSpeed = std::min(linearSpeed + 5, float(300));
    }
    else if (InputManager::GetInstance().IsKeyDown(S_KEY))
    {
        linearSpeed = std::max(linearSpeed - 5, float(-300));
    }
    else
    {
        linearSpeed = std::max(linearSpeed - 5, float(0));
    }
    if (InputManager::GetInstance().IsKeyDown(A_KEY))
    {
        speed = Vec2::Rotate(speed, -PI / 64);
    }
    if (InputManager::GetInstance().IsKeyDown(D_KEY))
    {
        speed = Vec2::Rotate(speed, PI / 64);
    }

    Rect newPos = associated.box + (speed * (linearSpeed * dt));
    if (newPos.x > -40 && newPos.x < 1340 && newPos.y > -10 && newPos.y < 1280)
    {
        associated.box = newPos;
    }
    associated.angleDeg = speed.Atan2() * 180 / PI;
}

void PenguinBody::NotifyCollision(GameObject &other)
{
    State *state = &Game::GetInstance().GetCurrentState();
    if (other.GetComponent("Bullet") != nullptr)
    {
        Bullet *bullet = (Bullet *)other.GetComponent("Bullet");
        if (bullet->targetsPlayer)
        {
            this->hp -= bullet->GetDamage();
            GameObject *penguinText = new GameObject();
            penguinText->box.x = associated.box.x;
            penguinText->box.y = associated.box.y;
            std::string penguinLifeText = std::to_string(this->hp);
            penguinText->AddComponent(new Text(*penguinText, "assets/font/Call me maybe.ttf", 50, Text::SOLID, penguinLifeText, {255, 0, 0, 255}, 0.05, 0.5));
            state->AddObject(penguinText);

            if (this->hp <= 0)
            {
                Camera::Unfollow();
                associated.RequestDelete();
                pcannon.lock()->RequestDelete();

                GameObject *penguinDeath = new GameObject();
                penguinDeath->AddComponent(new Sprite(*penguinDeath, "assets/img/penguindeath.png", 5, 0.1f, 0.5f));
                Sound *sound = new Sound(*penguinDeath, "assets/audio/boom.wav");
                sound->Play();
                penguinDeath->AddComponent(sound);
                penguinDeath->box.SetCenter(associated.box.Center());
                state->AddObject(penguinDeath);
            }
        }
    }
    else if (other.GetComponent("HealthBox") != nullptr)
    {
        this->hp += HEALTH_BOX;
        GameObject *penguinText = new GameObject();
        penguinText->box.x = associated.box.x - 10;
        penguinText->box.y = associated.box.y - 10;
        std::string penguinLifeText = std::to_string(this->hp);
        penguinText->AddComponent(new Text(*penguinText, "assets/font/Call me maybe.ttf", 50, Text::SOLID, penguinLifeText, {0, 60, 0, 255}, 0, 0.3));
        state->AddObject(penguinText);
    }
}

void PenguinBody::Render()
{
}

bool PenguinBody::Is(std::string type)
{
    return (type == PenguinBody::type);
}
