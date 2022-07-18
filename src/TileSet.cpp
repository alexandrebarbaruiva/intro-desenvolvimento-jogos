/**
 * @file TileSet.cpp
 * @author Alexandre Augusto de Sá dos Santos (150056940@aluno.unb.br)
 * @brief TileSet class implementation file
 * @version 0.1
 * @date 2022-07-16
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "../include/TileSet.h"

TileSet::TileSet(int tileWidth, int tileHeight, std::string file)
{
    GameObject *gameObject = new GameObject();
    tileSet = new Sprite(*gameObject, file);
    gameObject->AddComponent(tileSet);

    if (tileSet->IsOpen())
    {
        // Set width and height
        this->tileWidth = tileWidth;
        this->tileHeight = tileHeight;

        // Set rows and columns based on tile dimensions and gameObject's box dimensions
        rows = tileSet->GetHeight() / tileHeight;
        columns = tileSet->GetWidth() / tileWidth;
    }
}

TileSet::~TileSet()
{
}

void TileSet::RenderTile(unsigned index, float x, float y)
{
    
    if (index < unsigned (rows * columns))
    {
        // Calculate position on player map
        int currentX = (index % columns) * tileWidth;
        int currentY = (index / columns) * tileHeight;

        // SetClip
        tileSet->SetClip(currentX, currentY, tileWidth, tileHeight);
        // Render with location
        tileSet->Render(x, y, tileWidth, tileHeight);
    }
}

int TileSet::GetTileWidth()
{
    return tileWidth;
}

int TileSet::GetTileHeight()
{
    return tileHeight;
}
