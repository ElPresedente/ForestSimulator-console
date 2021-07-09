#include "FoodEntity.h"

FoodEntity::FoodEntity(Vector2 position) :
	Entity(position, EntityType::Food)
{
	foodAmount = rand() % 3;
}

void FoodEntity::EntityFunction() {
	
}
char FoodEntity::GetChar() {
	return '*';
}
