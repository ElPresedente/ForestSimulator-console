#pragma once
#include "Tile.h"
#include "DataStructures.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "TreeEntity.h"
#include "AnimalEntity.h"
#include "FoodEntity.h"
class Terrain
{
public:
	//Terrain(int x, int y, unsigned int keygen);
	//~Terrain();
	static Tile GetTile(int x, int Y);
	static Tile GetTile(Vector2 vector);

	static void GenerateMap(int x, int y, unsigned int keygen);
	static void DrawFrame();

	static Entity* FindEntity(Vector2 position);

	static std::vector<Entity*> entities;
private:
	static int x;
	static int y;

	static Tile* map;


	static TileType GenereteTileType();
	static EntityType GenerateEntity();
};

