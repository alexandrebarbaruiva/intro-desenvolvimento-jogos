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
#include <iostream>
#include "../include/Alien.h"
#include "../include/Game.h"

Alien::Action::Action(ActionType type, float x, float y)
{
    this->type = type;
    pos = Vec2(x, y);
}

Alien::Alien(GameObject &associated, int nMinions) : Component(associated)
{
    Sprite *sprite = new Sprite(associated, "assets/img/alien.png");
    associated.AddComponent(sprite);
    hp = 30;
    speed = Vec2();
    minions = nMinions;
}

Alien::~Alien()
{
}

void Alien::Start()
{
    for (int i = 0; i < minions; i++)
    {
        State *state = &Game::GetInstance()->GetState();
        std::weak_ptr<GameObject> alienCenter = state->GetObject(&associated);

        GameObject *gameObject = new GameObject();
        float minionDegree = (M_PI * i * 360 / this->minions) / 180;
        Minion *minion = new Minion(*gameObject, alienCenter, minionDegree);
        this->minionArray.push_back(state->AddObject(gameObject));
        gameObject->AddComponent(minion);
    }
}

void Alien::Update(float dt)
{
    if (this->hp <= 0)
    {
        associated.RequestDelete();
    }
    InputManager instance = InputManager::GetInstance();
    bool clickToShoot = instance.MousePress(LEFT_MOUSE_BUTTON);
    bool clickToMove = instance.MousePress(RIGHT_MOUSE_BUTTON);
    int clickPosX = instance.GetMouseX() + Camera::pos.x;
    int clickPosY = instance.GetMouseY() + Camera::pos.y;
    if (clickToMove)
    {
        taskQueue.push(Action(Action::ActionType::MOVE, clickPosX, clickPosY));
    }
    if (clickToShoot)
    {
        taskQueue.push(Action(Action::ActionType::SHOOT, clickPosX, clickPosY));
    }
    associated.angleDeg += M_PI * dt * 6;
    // Reset speed
    speed = Vec2();
    if (taskQueue.size() > 0)
    {
        Action currentAction = taskQueue.front();
        if (currentAction.type == Action::ActionType::MOVE)
        {
            Vec2 destination = currentAction.pos - (associated.box.measures() / 2);
            Vec2 currentPos = associated.box.toVec2();

            speed = (destination - currentPos).normalize();
            associated.box.setPosition(associated.box.toVec2() + (speed * dt * 300));

            bool tooClose = (std::abs((destination - currentPos).magnitude()) < 10);
            if (tooClose)
            {
                associated.box.setPosition(destination);
                taskQueue.pop();
            }
        }
        if (currentAction.type == Action::ActionType::SHOOT)
        {
            int closestMinion = Alien::GetClosestMinion(currentAction.pos);
            std::shared_ptr<GameObject> objectPointer = minionArray[closestMinion].lock();
            Minion *minionObject = (Minion *)objectPointer->GetComponent("Minion");
            minionObject->Shoot(currentAction.pos);
            taskQueue.pop();
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

int Alien::GetClosestMinion(Vec2 actionPos)
{
    int closestMinion = 0;
    float minDistance = MAXFLOAT;
    for (int mini = 0; mini < (int)minionArray.size(); mini++)
    {
        std::shared_ptr<GameObject> minionObject = minionArray[mini].lock();
        float minionDistance = minionObject->box.toVec2().distanceTo(actionPos);
        if (minionDistance < minDistance)
        {
            closestMinion = mini;
            minDistance = minionDistance;
        }
    }
    return closestMinion;
}
