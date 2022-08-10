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
    for (int i = 0; i < 6; i++)
    {
        mouseUpdate[i] = 0;
        mouseState[i] = false;
    }
    updateCounter = 0;
    quitRequested = false;
    mouseX = 0;
    mouseY = 0;
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
    updateCounter++;
    SDL_Event event;
    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequested = false;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            if (event.key.repeat)
            {
                break;
            }
            keyState[event.key.keysym.sym] = true;
            keyUpdate[event.key.keysym.sym] = updateCounter;
            break;

        case SDL_KEYUP:
            keyState[event.key.keysym.sym] = false;
            keyUpdate[event.key.keysym.sym] = updateCounter;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event.key.repeat)
            {
                break;
            }
            mouseState[event.button.button] = true;
            mouseUpdate[event.button.button] = updateCounter;
            break;

        case SDL_MOUSEBUTTONUP:
            mouseState[event.button.button] = false;
            mouseUpdate[event.button.button] = updateCounter;
            break;

        case SDL_QUIT:
            quitRequested = true;
            break;

        default:
            break;
        }
    }
}

bool InputManager::KeyPress(int key)
{
    std::unordered_map<int, int>::const_iterator foundKey = keyUpdate.find(key);
    if (foundKey != keyUpdate.end())
    {
        if (foundKey->second == updateCounter)
        {
            return keyState.find(key)->second;
        }
    }

    return false;
}

bool InputManager::KeyRelease(int key)
{
    std::unordered_map<int, int>::const_iterator foundKey = keyUpdate.find(key);
    if (foundKey != keyUpdate.end() && foundKey->second == updateCounter)
    {
        std::cout << "key released\n";
        return !keyState.find(key)->second;
    }

    return false;
}

bool InputManager::IsKeyDown(int key)
{
    std::unordered_map<int, bool>::const_iterator foundKey = keyState.find(key);

    if (foundKey != keyState.end())
    {
        return keyState.find(key)->second;
    }

    return false;
}

bool InputManager::MousePress(int button)
{
    if (mouseUpdate[button] == updateCounter)
    {
        return IsMouseDown(button);
    }

    return false;
}

bool InputManager::MouseRelease(int button)
{
    if (mouseUpdate[button] == updateCounter)
    {
        return !IsMouseDown(button);
    }
    return false;
}

bool InputManager::IsMouseDown(int button)
{
    return mouseState[button];
}

int InputManager::GetMouseX()
{
    return mouseX;
}

int InputManager::GetMouseY()
{
    return mouseY;
}

bool InputManager::QuitRequested()
{
    return quitRequested;
}
