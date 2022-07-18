/**
 * @file Main.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief Main file to run game
 * @version 0.1
 * @date 2022-06-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include "../include/Game.h"

int main(int argc, char **argv)
{
    Game *game = Game::GetInstance();
    game->Run();
    return 0;
}