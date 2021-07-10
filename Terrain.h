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

	static void DeleteEntity(Entity* ent);

	static Entity* FindEntity(Vector2 position);

	static std::vector<Entity*> entities;

	static int GetMapSizeX() {
		return x;
	}
	static int GetMapSizeY() {
		return y;
	}
	static int x;
	static int y;

private:
	static Tile* map;


	static TileType GenereteTileType();
	static EntityType GenerateEntity();
};

