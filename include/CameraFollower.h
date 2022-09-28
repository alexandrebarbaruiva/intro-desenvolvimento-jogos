/**
 * @file CameraFollower.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief CameraFollower class header file
 * @version 0.1
 * @date 2022-07-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef CAMERA_FOLLOWER_HEADER
#define CAMERA_FOLLOWER_HEADER
#include "Camera.h"
#include "GameObject.h"
#include "Component.h"
#include <string>

class CameraFollower : public Component
{
private:
    /* data */
public:
    CameraFollower(GameObject &associated);

    std::string type = "CameraFollower";

    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject &other);
};

#endif
