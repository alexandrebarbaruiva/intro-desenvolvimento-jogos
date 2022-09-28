/**
 * @file GameObject.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief GameObject class header file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef GAMEOBJ_HEADER
#define GAMEOBJ_HEADER
#define INCLUDE_SDL_IMAGE
#include "SDL_include.h"
#include "Rect.h"
#include <vector>
#include <memory>
#include <string>

class Component;

class GameObject
{
private:
    std::vector<std::unique_ptr<Component>> components;
    bool isDead;

public:
    Rect box;
    double angleDeg;
    bool started;

    GameObject(/* args */);
    ~GameObject();

    void Start();

    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component *cpt);
    void RemoveComponent(Component *cpt);
    Component *GetComponent(std::string type);
    void NotifyCollision(GameObject &other);
};

#endif
