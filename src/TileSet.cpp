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
#include "TileSet.h"

TileSet::TileSet(GameObject &associated, int tileWidth, int tileHeight, std::string file) : tileSet(associated, file, 1, 1.0)
{
    this->tileHeight = tileHeight;
    this->tileWidth = tileWidth;
    this->columns = tileSet.GetWidth() / tileWidth;
    this->rows = tileSet.GetHeight() / tileHeight;
}

void TileSet::RenderTile(unsigned index, float x, float y)
{
    if (index < unsigned(rows * columns))
    {
        // Calculate position on player map
        int currentX = (index % columns) * tileWidth;
        int currentY = (index / columns) * tileHeight;

        // SetClip
        tileSet.SetClip(currentX, currentY, tileWidth, tileHeight);
        // Render with location
        tileSet.Render(x, y);
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
