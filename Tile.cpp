#include "Tile.h"

Tile::Tile(TileType type) : type(type) {};

char Tile::GetChar() {
	switch (type) {
		case TileType::Rock: {
			return (char)64;
			break;
		}
		case TileType::Grass: {
			return (char)35;
			break;
		}
		default:{
			return (char)32;
			break;
		}
	}
}
