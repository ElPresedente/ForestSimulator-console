#pragma once
#include "Entity.h"
#include <cstdlib>
class FoodEntity :
    virtual public Entity
{
public:
    FoodEntity(Vector2 position);
    void EntityFunction();
    char GetChar();

    int foodAmount;
};

