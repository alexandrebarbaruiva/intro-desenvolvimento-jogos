/**
 * @file Component.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Component class implementation file
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/Component.h"

Component::Component(GameObject &associated) : associated(associated)
{
}

Component::~Component()
{
}

void Component::Update(float dt)
{
}

void Component::Render()
{
}
