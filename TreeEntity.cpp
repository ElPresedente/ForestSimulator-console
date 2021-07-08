#include "TreeEntity.h"

TreeEntity::TreeEntity(Vector2 position) :
	Entity(position, EntityType::Tree) 
{}

void TreeEntity::EntityFunction() {
	return;
}

char TreeEntity::GetChar() {
	return '%';
}