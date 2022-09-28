/**
 * @file TileMap.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief TileMap class implementation file
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "TileMap.h"
#include "Camera.h"
#include <fstream>
#include <sstream>
#include <iostream>

TileMap::TileMap(GameObject &associated, std::string file, TileSet *tileSet) : Component(associated)
{
    Load(file);
    this->tileSet = tileSet;
}

void TileMap::Load(std::string file)
{
    std::ifstream tileFile(file);
    if (!tileFile.is_open())
    {
        SDL_LogError(0, "tileMap file not found");
    }

    std::stringstream tileContent;
    tileContent << tileFile.rdbuf();
    std::string token;

    std::getline(tileContent, token, ',');
    mapWidth = stoi((token));
    std::getline(tileContent, token, ',');
    mapHeight = stoi(token);
    std::getline(tileContent, token, ',');
    mapDepth = stoi(token);

    for (int currentDepth = 0; currentDepth < mapDepth; currentDepth++)
    {
        std::getline(tileContent, token, '\n');
        for (int tileCell = 0; tileCell < (mapWidth * mapHeight); tileCell++)
        {
            std::getline(tileContent, token, ',');
            int currentTile = stoi(token) - 1;
            tileMatrix.push_back(currentTile);
        }
    }
}

void TileMap::SetTileSet(TileSet *tileSet)
{
    this->tileSet = tileSet;
}

int &TileMap::At(int x, int y, int z)
{
    // Calculate tileMatrix location
    z = (z * mapWidth * mapHeight);
    y = (y * mapWidth);
    return tileMatrix.at((x + y + z));
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY)
{
    // Calculate Parallax
    int tileHeight = tileSet->GetTileHeight();
    int tileWidth = tileSet->GetTileWidth();

    for (int posY = 0; posY < this->GetHeight(); posY++)
    {
        for (int posX = 0; posX < this->GetWidth(); posX++)
        {
            int index = At(posX, posY, layer);
            int y = (posY * tileHeight) - cameraY;
            int x = (posX * tileWidth) - cameraX;
            tileSet->RenderTile(index, x, y);
        }
    }
}

void TileMap::Render()
{
    for (int layer = 0; layer < this->GetDepth(); layer++)
    {
        RenderLayer(
            layer,
            Camera::pos.x * ((layer * 0.25) + 1),
            Camera::pos.y * ((layer * 0.25) + 1));
    }
}

int TileMap::GetWidth()
{
    return mapWidth;
}

int TileMap::GetHeight()
{
    return mapHeight;
}

int TileMap::GetDepth()
{
    return mapDepth;
}

bool TileMap::Is(std::string type)
{
    return (type == TileMap::type);
}

void TileMap::Update(float dt)
{
}

void TileMap::NotifyCollision(GameObject &other)
{
}
