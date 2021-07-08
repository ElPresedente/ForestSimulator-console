#include "Terrain.h"

void Terrain::GenerateMap(int X, int Y, unsigned int keygen) {
	x = X; y = Y;
	map = new Tile[X * Y];
	srand(keygen);
	for (int i = 0; i < x; i++) {
		map[i] = Tile(TileType::Rock);
	}
	for (int a = 1; a < y - 1; a++) {
		map[a * x] = Tile(TileType::Rock);
		for (int b = 1; b < x - 1; b++) {
			map[a * x + b] = Tile(GenereteTileType());
			if (map[a * x + b].type != TileType::Rock && GenerateTree()) {
				Entity* tree = new TreeEntity(Vector2(b, a));
			}
		}
		map[a * x + x - 1] = Tile(TileType::Rock);
	}
	for (int i = 0; i < x; i++) {
		map[i + x * (y - 1)] = Tile(TileType::Rock);
	}
}

Tile Terrain::GetTile(int X, int Y) {
	return map[X + Y * x];
}
Tile Terrain::GetTile(Vector2 vector) {
	return map[vector.x + vector.y * x];
}

TileType Terrain::GenereteTileType() {
	int value = rand() % 1000;
	if (value <= 950) {
		return TileType::Grass;
	}
	else {
		return TileType::Rock;
	}
}
void Terrain::DrawFrame() {
	for (int a = 0; a < y; a++) {
		for (int b = 0; b < x; b++) {
			std::cout << GetTile(b, a).GetChar();
		}
		std::cout << '\n';
	}
}

bool Terrain::GenerateTree() {
	int value = rand() % 1000;
	return (value >= 970) ? true : false;
}