#pragma once

struct Vector2 {
	int x;
	int y;
	Vector2(int X, int Y) : x(X), y(Y) {};
};

enum class TileType {
	None,
	Rock,
	Grass
};

enum class EntityType {
	None,
	Food,
	Tree,
	Animal
};