#include "FoodEntity.h"

FoodEntity::FoodEntity(Vector2 position) :
	Entity(position, EntityType::Food)
{}

void FoodEntity::EntityFunction() {
	
}
char FoodEntity::GetChar() {
	return '*';
}
