#pragma once
#include "Entity.h"
class TreeEntity :
    virtual public Entity
{
public:
    TreeEntity(Vector2 position);
    void EntityFunction();
    char GetChar();
};

