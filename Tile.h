#pragma once
#include "DataStructures.h"
#include <string>
#include "Entity.h"

class Tile
{
public:
	Tile(Vector2 position = Vector2(0,0), TileType type = TileType::None);
	TileType type;
	char GetChar();
	Vector2 position;
	bool operator<(const Tile& tile);
};

