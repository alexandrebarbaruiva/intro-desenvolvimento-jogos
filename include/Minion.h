/**
 * @file Minion.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Minion class header file
 * @version 0.1
 * @date 2022-08-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef MINION_HEADER
#define MINION_HEADER
#include "Component.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Vec2.h"
#include "Bullet.h"
#include <vector>
#include <queue>
#include <string>

class Minion : public Component
{
private:
    std::weak_ptr<GameObject> alienCenter;
    float arc;

public:
    Minion(GameObject &associated, std::weak_ptr<GameObject> alienCenter, float arcOffsetDeg = 0);
    ~Minion();

    std::string type = "Minion";

    void Start();
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    void Shoot(Vec2 target);
};

#endif
