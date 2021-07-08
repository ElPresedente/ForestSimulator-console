#include "Entity.h"

Entity::Entity(Vector2 position, EntityType type) : Position(position), Type(type) {
	
};

Entity::~Entity() {};

void Entity::EntityFunction() {

}

char Entity::GetChar() {
	return '2';
}