/**
 * @file Music.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Music class implementation file
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/Music.h"

Music::Music(/* args */)
{
}

Music::~Music()
{
}

bool Music::IsOpen()
{
    if (music != nullptr)
    {
        return true;
    }
    return false;
}