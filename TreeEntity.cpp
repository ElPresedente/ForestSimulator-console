#include "TreeEntity.h"
#include <cstdlib>
#include "Terrain.h"

TreeEntity::TreeEntity(Vector2 position) :
	Entity(position, EntityType::Tree) 
{}

void TreeEntity::EntityFunction() 
{
	int side = rand() % 4;
	Vector2 foodPos(Position);
	switch (side) {
		case 0:  //up
		{ 
			foodPos.y--;
			break;
		}
		case 1:  //rigth
		{
			foodPos.x++;
			break;
		}
		case 2:  //down
		{ 
			foodPos.y++;
			break;
		}
		case 3:  //left
		{
			foodPos.x--;
			break;
		}
	}
	if (Terrain::GetTile(foodPos).type == TileType::Grass && Terrain::FindEntity(foodPos) == nullptr)
	{
		Terrain::entities.push_back(new FoodEntity(foodPos));
	}
	return;
}

char TreeEntity::GetChar() 
{
	return '%';
}