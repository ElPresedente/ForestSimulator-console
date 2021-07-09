#include "AnimalEntity.h"
#include <cstdlib>

AnimalEntity::AnimalEntity(Vector2 position) :
	Entity(position, EntityType::Animal)
{
	health = (rand() % 2) + 2;
}

void AnimalEntity::EntityFunction() {
	int side = rand() % 4;
	Vector2 nextPos(Position);
	switch (side) {
		case 0:  //up
		{
			nextPos.y--;
			break;
		}
		case 1:  //rigth
		{
			nextPos.x++;
			break;
		}
		case 2:  //down
		{
			nextPos.y++;
			break;
		}
		case 3:  //left
		{
			nextPos.x--;
			break;
		}
	}
	if (Terrain::GetTile(nextPos).type == TileType::Grass && Terrain::FindEntity(nextPos) == nullptr)
	{
		Move(nextPos);
	}
}
char AnimalEntity::GetChar() {
	return '^';
}

void AnimalEntity::Move(Vector2 newPos) {
	Position = newPos;
}
