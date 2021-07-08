#pragma once
#include "Tile.h"
#include "DataStructures.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "TreeEntity.h"
class Terrain
{
public:
	//Terrain(int x, int y, unsigned int keygen);
	//~Terrain();
	static Tile GetTile(int x, int Y);
	static Tile GetTile(Vector2 vector);

	static void GenerateMap(int x, int y, unsigned int keygen);
	static void DrawFrame();
private:
	static int x;
	static int y;

	static Tile* map;
	static std::vector<Entity*> entities;


	static TileType GenereteTileType();
	static bool GenerateTree();
};

