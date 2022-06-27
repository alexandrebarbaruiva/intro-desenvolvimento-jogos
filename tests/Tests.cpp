#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include <iostream>
#include "catch.hpp"
#include "../src/Game.cpp"


TEST_CASE("Singleton Game has only one instance", "[game]")
{
    Game *game1 = Game::GetInstance();
    Game *game2 = Game::GetInstance();

    REQUIRE(game1 == game2);
}