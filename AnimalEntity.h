#pragma once
#include "Entity.h"
#include "Terrain.h"

class AnimalEntity :
    virtual public Entity
{
public:
    void EntityFunction();
    char GetChar();
    int health;

    AnimalEntity(Vector2 position);
private:
    void Move(Vector2 newPos);
};

