/**
 * @file CameraFollower.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief CameraFollower class implementation file
 * @version 0.1
 * @date 2022-08-06
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "CameraFollower.h"

CameraFollower::CameraFollower(GameObject &associated) : Component(associated)
{
}

void CameraFollower::Update(float dt)
{
    associated.box.SetOrigin(Camera::pos);
}

void CameraFollower::Render()
{
}

bool CameraFollower::Is(std::string type)
{
    return (type == CameraFollower::type);
}

void CameraFollower::NotifyCollision(GameObject &other)
{
}