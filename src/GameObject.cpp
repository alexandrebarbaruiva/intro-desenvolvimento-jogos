/**
 * @file GameObject.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief GameObject class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "GameObject.h"
#include "Component.h"

GameObject::GameObject()
{
    this->started = false;
    this->angleDeg = 0;
    this->isDead = false;
}

GameObject::~GameObject()
{
    components.clear();
}

void GameObject::Start()
{
    for (int pos = 0; pos < (int)components.size(); pos++)
    {
        components[pos]->Start();
    }
    started = true;
}

void GameObject::Update(float dt)
{
    for (int pos = 0; pos < (int)components.size(); pos++)
    {
        components[pos]->Update(dt);
    }
}

void GameObject::Render()
{
    for (int pos = 0; pos < (int)components.size(); pos++)
    {
        components[pos]->Render();
    }
}

bool GameObject::IsDead()
{
    return isDead;
}

void GameObject::RequestDelete()
{
    isDead = true;
}

void GameObject::AddComponent(Component *cpt)
{
    components.emplace_back(cpt);
    if (started)
    {
        cpt->Start();
    }
}

void GameObject::RemoveComponent(Component *cpt)
{
    for (int pos = 0; pos < (int)components.size(); pos++)
    {
        if (components[pos].get() == cpt)
        {
            components.erase(components.begin() + pos);
        }
    }
}

Component *GameObject::GetComponent(std::string type)
{
    for (int pos = 0; pos < (int)components.size(); pos++)
    {
        if (components[pos].get()->Is(type))
        {
            return components[pos].get();
        }
    }
    return nullptr;
}

void GameObject::NotifyCollision(GameObject &other)
{
    for (int pos = 0; pos < (int)components.size(); pos++)
    {
        components[pos]->NotifyCollision(other);
    }
}