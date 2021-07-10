#pragma once
struct Vector2 {
	int x;
	int y;
	static int maxX;
	Vector2(int X = 0, int Y = 0) : x(X), y(Y) {};
	bool operator == (Vector2 vec) {
		if (x == vec.x && y == vec.y)
			return true;
		else
			return false;
	}
	bool operator != (Vector2 vec) {
		if (x != vec.x || y != vec.y)
			return true;
		else
			return false;
	}
	bool operator < (const Vector2& vec) const {
		if ((x + y) == (vec.x + vec.y)) {
			return (y < vec.y) ? true : false;
		}
		else {
			return (x + y < vec.x + vec.y) ? true : false;
		}
	}
	int ToInt() {
		return  maxX * y + x;
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