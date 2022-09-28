/**
 * @file Component.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Component class header file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef COMPONENT_HEADER
#define COMPONENT_HEADER
#include "GameObject.h"
#include <string>

class Component
{
protected:
    GameObject &associated;

public:
    Component(GameObject &associated);

    virtual ~Component();

    std::string type;

    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool Is(std::string type) = 0;
    virtual void Start();
    virtual void NotifyCollision(GameObject &other);
};

#endif
