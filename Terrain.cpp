#include "Terrain.h"
int Terrain::x = 0;
int Terrain::y = 0;
Tile* Terrain::map = nullptr;
std::vector<Entity*> Terrain::entities = std::vector<Entity*>();

void Terrain::GenerateMap(int X, int Y, unsigned int keygen) {
	x = X; 
	y = Y;
	map = new Tile[X * Y];
	srand(keygen);
	for (int i = 0; i < x; i++) {
		map[i] = Tile(TileType::Rock);
	}
	for (int a = 1; a < y - 1; a++) {
		map[a * x] = Tile(TileType::Rock);
		for (int b = 1; b < x - 1; b++) {
			TileType type = GenereteTileType();
			map[a * x + b] = Tile(type);
			if (type == TileType::Grass){
				EntityType newEntity = GenerateEntity();
				switch (newEntity) {
					case EntityType::Animal:{
						entities.push_back(new AnimalEntity(Vector2(b, a)));
						break;
					}
					case EntityType::Food: {
						entities.push_back(new FoodEntity(Vector2(b, a)));
						break;
					}
					case EntityType::Tree: {
						entities.push_back(new TreeEntity(Vector2(b, a)));
						break;
					}
					default: {
						break;
					}
				}
			}
		}
		map[a * x + x - 1] = Tile(TileType::Rock);
	}
	for (int i = 0; i < x; i++) {
		map[i + x * (y - 1)] = Tile(TileType::Rock);
	}
	std::cout << entities.size() << '\n';
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
	std::string out;
	for (int a = 0; a < y; a++) {
		for (int b = 0; b < x; b++) {
			out += GetTile(b, a).GetChar();
		}
		out += '\n';
	}
	out += '\n';
	for (size_t i = 0; i < entities.size(); i++) {
		int x = entities[i]->Position.x;
		int y = entities[i]->Position.y;
		out[y * (Terrain::x + 1) + x] = entities[i]->GetChar();
	}
	std::cout << out;
}

EntityType Terrain::GenerateEntity() {
	int value = rand() % 1000;
	if (value >= 970) {
		return EntityType::Tree;
	}
	else if (value >= 950) {
		return EntityType::Food;
	}
	else if (value >= 940){
		return EntityType::Animal;
	}
	else {
		return EntityType::None;
	}
}

Entity* Terrain::FindEntity(Vector2 position)
{
	for (int i = 0; i < entities.size(); i++) 
	{
		if(entities[i]->Position == position)
		{
			return entities[i];
		}
	}
	return nullptr;
}