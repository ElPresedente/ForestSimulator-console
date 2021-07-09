#pragma once
#include "Entity.h"
class FoodEntity :
    virtual public Entity
{
public:
    FoodEntity(Vector2 position);
    void EntityFunction();
    char GetChar();
};

