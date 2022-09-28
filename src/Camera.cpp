/**
 * @file Camera.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Camera class implementation file
 * @version 0.1
 * @date 2022-08-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Camera.h"
#include "InputManager.h"
#include "Game.h"

GameObject *Camera::focus;
Vec2 Camera::pos;
Vec2 Camera::speed;

void Camera::Follow(GameObject *newFocus)
{
    focus = newFocus;
}

void Camera::Unfollow()
{
    focus = nullptr;
}

void Camera::Reset()
{
    Camera::pos = {0, 0};
}

void Camera::Update(float dt)
{
    if (focus != nullptr)
    {
        pos.x = focus->box.Center().x - GAME_SCREEN_WIDTH / 2;
        pos.y = focus->box.Center().y - GAME_SCREEN_HEIGHT / 2;
    }
    else
    {
        InputManager *input = &InputManager::GetInstance();
        if (input->IsKeyDown(LEFT_ARROW_KEY))
        {
            speed += Vec2(-1, 0);
        }
        if (input->IsKeyDown(RIGHT_ARROW_KEY))
        {
            speed += Vec2(1, 0);
        }
        if (input->IsKeyDown(UP_ARROW_KEY))
        {
            speed += Vec2(0, -1);
        }
        if (input->IsKeyDown(DOWN_ARROW_KEY))
        {
            speed += Vec2(0, 1);
        }
        pos += speed * dt * 200;
    }
}