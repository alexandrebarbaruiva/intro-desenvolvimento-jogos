/**
 * @file GameObject.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief GameObject class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/GameObject.h"

GameObject::GameObject()
{
    isDead = false;
}

GameObject::~GameObject()
{
    for (auto cpt = components.end(); cpt > components.begin(); cpt--)
    {
        components.erase(cpt);
    }
    components.clear();
}

void GameObject::Update(float dt)
{
    for (int pos = 0; pos < (int)components.size(); pos++)
    {

        components[pos].get()->Update(dt);
    }
}

void GameObject::Render()
{
    for (int pos = 0; pos < (int)components.size(); pos++)
    {
        components[pos].get()->Render();
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
    // Assuming there's only one Component of type
    for (int pos = 0; pos < (int)components.size(); pos++)
    {
        if (components[pos].get()->Is(type))
        {
            return components[pos].get();
        }
    }
    return nullptr;
}

// Links
// https://www.geeksforgeeks.org/vector-in-cpp-stl/
// https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/
