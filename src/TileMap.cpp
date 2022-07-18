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
#include "../include/TileMap.h"
#include <fstream>
#include <sstream>
#include <iostream>

TileMap::TileMap(GameObject &associated, std::string file, TileSet *tileSet) : Component(associated)
{
    this->Load(file);
    this->tileSet = tileSet;
}

TileMap::~TileMap()
{
}

void TileMap::Load(std::string file)
{
    std::ifstream tileFile(file);
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
            int y = posY * tileHeight;
            int x = posX * tileWidth;
            tileSet->RenderTile(index, x, y);
        }
    }
}

void TileMap::Render()
{
    for (int layer = 0; layer < this->GetDepth(); layer++)
    {
        RenderLayer(layer, associated.box.x, associated.box.y);
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
    return (type == "TileMap");
}

void TileMap::Update(float dt)
{
}
