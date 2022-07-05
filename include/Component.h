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
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "SDL_include.h"
#include "GameObject.h"
#include <string>

class GameObject;

class Component
{
protected:
    GameObject &associated;

private:
    /* data */
public:
    Component(GameObject &associated);

    virtual ~Component();

    std::string type;

    void virtual Update(float dt) = 0;
    void virtual Render() = 0;
    bool virtual Is(std::string type) = 0;
};

#endif

// Links
// https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
// https://www.geeksforgeeks.org/difference-between-virtual-function-and-pure-virtual-function-in-c/
// https://en.cppreference.com/w/cpp/language/constructor
