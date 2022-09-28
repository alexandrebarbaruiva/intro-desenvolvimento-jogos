/**
 * @file Timer.h
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Timer class header file
 * @version 0.1
 * @date 2022-07-11
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef TIMER_HEADER
#define TIMER_HEADER

class Timer
{
private:
    float time;

public:
    Timer();
    void Update(float dt);
    void Restart();
    float Get();
};

#endif
