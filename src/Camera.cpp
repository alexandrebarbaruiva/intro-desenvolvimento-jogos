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
#include "../include/Camera.h"
#include "../include/Game.h"
#include "../include/InputManager.h"

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

void Camera::Update(float dt)
{
    InputManager instance = InputManager::GetInstance();
    speed = Vec2();
    if (focus != nullptr)
    {
        // Screen is 1024 x 600
        pos = focus->box.Center() - Vec2(GAME_SCREEN_WIDTH / 2, GAME_SCREEN_HEIGHT / 2);
    }
    else
    {
        if (instance.IsKeyDown(LEFT_ARROW_KEY))
        {
            speed += Vec2(-1, 0);
        }
        if (instance.IsKeyDown(RIGHT_ARROW_KEY))
        {
            speed += Vec2(1, 0);
        }
        if (instance.IsKeyDown(UP_ARROW_KEY))
        {
            speed += Vec2(0, -1);
        }
        if (instance.IsKeyDown(DOWN_ARROW_KEY))
        {
            speed += Vec2(0, 1);
        }
        pos += speed * dt * 200;
    }
}
