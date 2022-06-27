#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include "catch.hpp"
#include "../src/Game.h"

std::string GetGameInstanceTitle()
{
    Game *game = Game::GetInstance();
    return game->title();
}

TEST_CASE("Singleton Game has only one instance", "[game]")
{
    std::string firstInstance = GetGameInstanceTitle();
    std::string secondInstance = GetGameInstanceTitle();

    REQUIRE(firstInstance == secondInstance);
}