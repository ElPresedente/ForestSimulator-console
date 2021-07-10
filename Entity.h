#pragma once
#include "DataStructures.h"
class Entity
{
public:
	Vector2 Position;
	EntityType Type;
	virtual void EntityFunction();
	virtual char GetChar();

	virtual ~Entity();
protected:
	Entity(Vector2 position, EntityType type = EntityType::None);
};

