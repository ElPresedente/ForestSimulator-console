#include "Terrain.h"
int Terrain::x = 0;
int Terrain::y = 0;
Tile* Terrain::map = nullptr;
std::vector<Entity*> Terrain::entities = std::vector<Entity*>();

int Vector2::maxX = 0; // господи я ужасен, но делать срр только для одной строки я не буду

void Terrain::GenerateMap(int X, int Y, unsigned int keygen) {
	x = X; 
	y = Y;
	Vector2::maxX = x;
	map = new Tile[X * Y];
	srand(keygen);
	for (int i = 0; i < x; i++) {
		map[i] = Tile(Vector2(i, 0), TileType::Rock);
	}
	int j = 0;
	for (int a = 1; a < y - 1; a++) {
		map[a * x] = Tile(Vector2(0, a), TileType::Rock);
		for (int b = 1; b < x - 1; b++) {
			TileType type = GenereteTileType();
			map[a * x + b] = Tile(Vector2(b, a), type);
			if (type == TileType::Grass){
				j++;
				switch (j) {
					case 5: {
						entities.push_back(new AnimalEntity(Vector2(b, a)));
						break;
					}
					case 30: {
						entities.push_back(new FoodEntity(Vector2(b, a)));
						break;
					}
				}
				//EntityType newEntity = GenerateEntity();
				//switch (newEntity) {
				//	case EntityType::Animal:{
				//		entities.push_back(new AnimalEntity(Vector2(b, a)));
				//		break;
				//	}
				//	case EntityType::Food: {
				//		entities.push_back(new FoodEntity(Vector2(b, a)));
				//		break;
				//	}
				//	case EntityType::Tree: {
				//		entities.push_back(new TreeEntity(Vector2(b, a)));
				//		break;
				//	}
				//	default: {
				//		break;
				//	}
				//}
			}
		}
		map[a * x + x - 1] = Tile(Vector2(x-1, a), TileType::Rock);
	}
	for (int i = 0; i < x; i++) {
		map[i + x * (y - 1)] = Tile(Vector2(i, y-1), TileType::Rock);
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
	if (value >= 985) {
		return EntityType::Tree;
	}
	else if (value >= 970) {
		return EntityType::Food;
	}
	else if (value >= 960){
		return EntityType::Animal;
	}
	else {
		return EntityType::None;
	}
}

Entity* Terrain::FindEntity(Vector2 position)
{
	for (size_t i = 0; i < entities.size(); i++) 
	{
		if(entities[i]->Position == position)
		{
			return entities[i];
		}
	}
	return nullptr;
}