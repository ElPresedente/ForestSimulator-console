#pragma once
#include "Entity.h"
#include "Terrain.h"
#include <cstdlib>
#include <queue>
#include <set>
#include <map>
#include <Windows.h>

class AnimalEntity :
    virtual public Entity
{
public:
    void EntityFunction();
    char GetChar();
    int health;

    AnimalEntity(Vector2 position);
private:
    void RandomMovement();
    void Move(Vector2 newPos);
    Vector2 FindFood();
    void SetWay(Vector2 target, Vector2* searchMap);

    std::vector<Vector2>* animalPath;
};

