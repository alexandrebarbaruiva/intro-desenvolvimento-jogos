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
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.h"
#include "Vec2.h"
#include <string>

class CameraFollower : public Component
{
private:
    /* data */
public:
    CameraFollower(GameObject &go);
    ~CameraFollower();

    void Update(float dt);
    void Render();
    bool Is(std::string type);
};

#endif
