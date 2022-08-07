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

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

InputManager &InputManager::GetInstance()
{
    // Meyer's Singleton
    static InputManager instance;
    return instance;
}

void InputManager::Update()
{
}

bool InputManager::KeyPress(int key)
{
    return true;
}

bool InputManager::KeyRelease(int key)
{
    return true;
}

bool InputManager::IsKeyDown(int key)
{
    return true;
}

bool InputManager::MousePress(int button)
{
    return true;
}

bool InputManager::MouseRelease(int button)
{
    return true;
}

bool InputManager::IsMouseDown(int button)
{
    return true;
}

int InputManager::GetMouseX()
{
    return 0;
}

int InputManager::GetMouseY()
{
    return 0;
}

bool InputManager::QuitRequested()
{
    return true;
}
