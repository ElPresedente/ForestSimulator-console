#include "Tile.h"

Tile::Tile(Vector2 position, TileType type) :
	position(position), type(type) 
{};

char Tile::GetChar() {
	switch (type) {
		case TileType::Rock: {
			return '@';
			break;
		}
		case TileType::Grass: {
			return '.';
			break;
		}
		default:{
			return ' ';
			break;
		}
	}
}

bool Tile::operator<(const Tile& tile) {
	return true;
}
