#pragma once
#include "DataStructures.h"
class Entity
{
public:
	Vector2 Position;
	EntityType Type;
	void EntityFunction() {};
protected:
	Entity(Vector2 position, EntityType type = EntityType::None);
	virtual ~Entity();
};

