/**
 * @file PenguinBody.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief PenguinBody class header file
 * @version 0.1
 * @date 2022-09-10
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef PENGUINBODY_HEADER
#define PENGUINBODY_HEADER
#include "Component.h"
#include "GameObject.h"
#include "PenguinCannon.h"
#include "Sprite.h"
#include "Collider.h"
#include "Text.h"
#include "Game.h"
#include "Camera.h"
#include "Bullet.h"
#include "Timer.h"
#include "Sound.h"
#include <vector>

class PenguinBody : public Component
{
private:
    std::weak_ptr<GameObject> pcannon;
    Vec2 speed;
    float linearSpeed;
    float angle;

public:
    static PenguinBody *player;
    std::string type = "PenguinBody";
    int hp;

    PenguinBody(GameObject &associated);
    ~PenguinBody();

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void NotifyCollision(GameObject &other);
};

#endif
