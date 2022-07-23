/**
 * @file InputManager.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief InputManager class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/InputManager.h"

InputManager::InputManager() : Component(associated)
{
}

InputManager::~InputManager()
{
}

void InputManager::Damage(int damage)
{
}

void InputManager::Update(float dt)
{
}

void InputManager::Render()
{
}

bool InputManager::Is(std::string type)
{
    return (type == "InputManager");
}
