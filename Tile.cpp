#include "Tile.h"

Tile::Tile(TileType type) : type(type) {};

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
