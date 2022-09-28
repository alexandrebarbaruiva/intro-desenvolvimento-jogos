/**
 * @file Alien.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Alien class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Alien.h"

int Alien::alienCount = 0;
Alien::Alien(GameObject &associated, float timeOffset) : Component(associated)
{
    associated.AddComponent(new Sprite(associated, "assets/img/alien.png", 1, 1.0));
    associated.AddComponent(new Collider(associated));
    this->hp = ALIEN_HP;
    this->speed = {100, 100};
    this->state = AlienState::RESTING;
    this->timeOffset = timeOffset;
    Alien::alienCount++;
}

Alien::~Alien()
{
    minionArray.clear();
    Alien::alienCount--;
}

void Alien::Start()
{
    GameObject *minionGO;
    Minion *minion;
    int maxMinions = (int)(((float)rand() / RAND_MAX) * (8 - 1) + 1);
    State *state = &Game::GetInstance().GetCurrentState();
    std::weak_ptr<GameObject> alienObject = state->GetObjectPtr(&associated);

    for (int i = 0; i < maxMinions; i++)
    {
        minionGO = new GameObject();
        float minionDegree = (PI * i * 2 / maxMinions);
        minion = new Minion(*minionGO, alienObject, minionDegree);
        minionGO->AddComponent(minion);
        minionArray.push_back(state->AddObject(minionGO));
    }
}

void Alien::Update(float dt)
{
    associated.angleDeg -= (180 / 124);

    if (state == AlienState::RESTING)
    {
        if (restTimer.Get() >= 0.5f)
        {
            destination = Camera::pos + Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 2);
            Vec2 direction = destination - associated.box.Center();
            speed = Vec2::Rotate(speed, Vec2::Atan2(direction, speed));
            state = AlienState::MOVING;
        }
        restTimer.Update(dt + timeOffset);
    }
    else if (Vec2::Distance(associated.box.Center(), destination) < 10)
    {
        destination = Camera::pos + Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 2);
        std::weak_ptr<GameObject> closestMinion = Alien::GetClosestMinion();

        ((Minion *)(closestMinion.lock()->GetComponent("Minion")))->Shoot(destination);

        state = AlienState::RESTING;
        restTimer.Restart();
    }
    associated.box = associated.box + speed * dt;
}

void Alien::NotifyCollision(GameObject &other)
{
    Bullet *bullet = (Bullet *)other.GetComponent("Bullet");
    if (bullet != nullptr && !bullet->targetsPlayer)
    {
        this->hp -= bullet->GetDamage();
        if (this->hp <= 0)
        {
            associated.RequestDelete();

            GameObject *alienDeath = new GameObject();
            alienDeath->AddComponent(new Sprite(*alienDeath, "assets/img/aliendeath.png", 4, 0.1, 0.4));
            Sound *sound = new Sound(*alienDeath, "assets/audio/boom.wav");
            sound->Play();
            alienDeath->AddComponent(sound);
            alienDeath->box.SetCenter(associated.box.Center());
            Game::GetInstance().GetCurrentState().AddObject(alienDeath);
        }
    }
}

void Alien::Render()
{
}

bool Alien::Is(std::string type)
{
    return (type == Alien::type);
}

std::weak_ptr<GameObject> Alien::GetClosestMinion()
{
    int closestDistance = INT_MAX;

    std::weak_ptr<GameObject> closestMinion;
    for (auto minion : minionArray)
    {
        float distance = Vec2::Distance(minion.lock()->box.Center(), this->destination);
        if (distance < closestDistance)
        {
            closestMinion = minion;
            closestDistance = distance;
        }
    }
    return closestMinion;
}
