#pragma once

struct Vector2 {
	int x;
	int y;
	Vector2(int X, int Y) : x(X), y(Y) {};
	bool operator == (Vector2 vec) {
		if (x == vec.x && y == vec.y)
			return true;
		else
			return false;
	}
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