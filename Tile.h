#pragma once
#include "DataStructures.h"
#include <string>
#include "Entity.h"
class Tile
{
public:
	Tile(TileType type = TileType::None);
	TileType type;
	char GetChar();
	Entity* currentEntity;
};

