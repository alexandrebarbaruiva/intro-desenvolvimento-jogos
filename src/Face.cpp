/**
 * @file Face.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Face class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/Face.h"

Face::Face(GameObject &associated) : Component(associated)
{
    hitpoints = 30;
}

Face::~Face()
{
}

void Face::Damage(int damage)
{
    hitpoints -= damage;

    if (hitpoints <= 0)
    {
        // play sound here and destroy on state
        // RequestDelete must come first to avoid multiple sounds
        associated.RequestDelete();
        Sound *soundToRemove = (Sound *)associated.GetComponent("Sound");
        if (soundToRemove != nullptr)
        {
            soundToRemove->Play();
        }
    }
}

void Face::Update(float dt)
{
    InputManager instance = InputManager::GetInstance();
    bool clicked = instance.MousePress(LEFT_MOUSE_BUTTON);
    bool containsFace = associated.box.Contains(
        Vec2(
            (instance.GetMouseX() + Camera::pos.x),
            (instance.GetMouseY() + Camera::pos.y)));
    if (clicked && containsFace)
    {
        Damage(std::rand() % 10 + 10);
    }
}

void Face::Render()
{
}

bool Face::Is(std::string type)
{
    return (type == "Face");
}
