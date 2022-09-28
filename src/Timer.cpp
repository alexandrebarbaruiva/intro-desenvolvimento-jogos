/**
 * @file Timer.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Timer class implementation file
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "Timer.h"

Timer::Timer()
{
    this->time = 0;
}

void Timer::Update(float dt)
{
    time += dt;
}

void Timer::Restart()
{
    time = 0;
}

float Timer::Get()
{
    return time;
}