#include "AnimalEntity.h"


AnimalEntity::AnimalEntity(Vector2 position) :
	Entity(position, EntityType::Animal)
{
	health = (rand() % 2) + 2;
	animalPath = nullptr;
}

void AnimalEntity::EntityFunction() {
	Vector2 foodcoord = FindFood();
	Sleep(500);
	std::cout << foodcoord.x << ' ' << foodcoord.y << std::endl;
	if (foodcoord == Vector2()) {
		RandomMovement();
	}
	else {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, {(short)foodcoord.x, (short)foodcoord.y});
		SetConsoleTextAttribute(hConsole, 6);
		std::cout << '*';
		SetConsoleCursorPosition(hConsole, { 0, 15 });
		SetConsoleTextAttribute(hConsole, 7);

	}
}
char AnimalEntity::GetChar() {
	return '^';
}

void AnimalEntity::RandomMovement() {
	int side = rand() % 4;
	Vector2 nextPos(Position);
	switch (side) {
	case 0:  //up
	{
		nextPos.y--;
		break;
	}
	case 1:  //rigth
	{
		nextPos.x++;
		break;
	}
	case 2:  //down
	{
		nextPos.y++;
		break;
	}
	case 3:  //left
	{
		nextPos.x--;
		break;
	}
	}
	if (Terrain::GetTile(nextPos).type == TileType::Grass && Terrain::FindEntity(nextPos) == nullptr)
	{
		Move(nextPos);
	}
}

void AnimalEntity::Move(Vector2 newPos) {
	Position = newPos;
}

Vector2 AnimalEntity::FindFood() {
	std::queue<Tile> elements;
	std::set<Vector2> visited;
	Vector2* searchMap = new Vector2[Terrain::x * Terrain::y];
	Tile tile = Terrain::GetTile(Position);
	elements.push(tile);
	visited.insert(tile.position);
	while (!elements.empty()) 
	{
		Tile current = elements.front();
		elements.pop();
		Tile neighbors[4];
		neighbors[0] = Terrain::GetTile(Vector2(current.position.x, current.position.y - 1));
		neighbors[1] = Terrain::GetTile(Vector2(current.position.x + 1, current.position.y));
		neighbors[2] = Terrain::GetTile(Vector2(current.position.x, current.position.y + 1));
		neighbors[3] = Terrain::GetTile(Vector2(current.position.x - 1, current.position.y));
		for (int i = 0; i < 4; i++) {
			if (!visited.count(neighbors[i].position) && neighbors[i].type != TileType::Rock) 
			{
				elements.push(neighbors[i]);
				searchMap[neighbors[i].position.ToInt()] = current.position;
				visited.insert(neighbors[i].position);
				Entity* ent = Terrain::FindEntity(neighbors[i].position);
				if (ent == nullptr)
				{ 
					continue;
				}
				if (ent->Type == EntityType::Food)
				{
					SetWay(ent->Position, searchMap);
					return ent->Position;
				}
			}
			
		}
	}
	return Vector2();
}

void AnimalEntity::SetWay(Vector2 target, Vector2* searchMap) {
	animalPath = new std::vector<Vector2>();
	Vector2 current = target;
	while (current != Position) {
		std::cout << current.x << ' ' << current.y << '\n';
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, { (short)current.x, (short)current.y });
		SetConsoleTextAttribute(hConsole, 6);
		std::cout << '&';
		SetConsoleCursorPosition(hConsole, { 0, 15 });
		SetConsoleTextAttribute(hConsole, 7);
		animalPath->push_back(current);
		current = searchMap[current.ToInt()];
		
		Sleep(500);
	}
	std::cout << animalPath->size();
}