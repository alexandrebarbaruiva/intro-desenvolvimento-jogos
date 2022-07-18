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
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "Component.h"
#include "Rect.h"
#include <vector>
#include <memory>
#include <iostream>

class Component;

class GameObject
{
private:
    std::vector<std::unique_ptr<Component>> components;
    bool isDead;

public:
    Rect box;

    GameObject(/* args */);
    ~GameObject();

    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component *cpt);
    void RemoveComponent(Component *cpt);
    Component *GetComponent(std::string type);
};

#endif

// Links
// https://stackoverflow.com/questions/6876751/differences-between-unique-ptr-and-shared-ptr
// https://stackoverflow.com/questions/2133250/x-does-not-name-a-type-error-in-c
// https://www.cppstories.com/2014/05/vector-of-objects-vs-vector-of-pointers/
