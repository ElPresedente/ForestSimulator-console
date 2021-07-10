#include "AnimalEntity.h"


AnimalEntity::AnimalEntity(Vector2 position) :
	Entity(position, EntityType::Animal)
{
	hunger = 0;
	animalPath = nullptr;
}

void AnimalEntity::EntityFunction() {
	hunger += ((rand() % 1000) > 750) ? 1 : 0;
	if (hunger <= 0) {
		RandomMovement();
		return;
	}
	if (animalPath == nullptr) {
		Vector2 foodCoord = FindFood();
		if (foodCoord == Vector2()) {
			RandomMovement();
		}
	}
	else {
		bool foodAviable = CheckFood();
		if (foodAviable) {

			Move(animalPath->back());
			/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, 6);
			SetConsoleCursorPosition(hConsole, { (short)animalPath->at(0).x, (short)animalPath->at(0).y });
			SetConsoleTextAttribute(hConsole, 7);
			std::cout << '&';
			Sleep(300);*/
			if (Position == animalPath->at(1)) {
				Entity* foodEntity = Terrain::FindEntity(animalPath->at(0));
				FoodEntity* ptr = dynamic_cast<FoodEntity*>(foodEntity);
				hunger -= ptr->foodAmount;
				Terrain::DeleteEntity(foodEntity);
				delete animalPath;
				animalPath = nullptr;
				return;
			}
			else {
				animalPath->pop_back();
			}
		}
		else {
			delete animalPath;
			FindFood();
		}

	}
}

bool AnimalEntity::CheckFood() {
	Entity* foodEnt = Terrain::FindEntity(animalPath->at(0));
	if (foodEnt == nullptr || foodEnt->Type != EntityType::Food) {
		return false;
	}
	else {
		return true;
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
				Entity* ent = Terrain::FindEntity(neighbors[i].position);
				if (ent != nullptr && ent->Type != EntityType::Food) {
					continue;
				}
				elements.push(neighbors[i]);
				searchMap[neighbors[i].position.ToInt()] = current.position;
				visited.insert(neighbors[i].position);
				
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
	delete searchMap;
	return Vector2();
}

void AnimalEntity::SetWay(Vector2 target, Vector2* searchMap) {
	animalPath = new std::vector<Vector2>();
	Vector2 current = target;
	while (current != Position) {
		std::cout << current.x << ' ' << current.y << '\n';
		/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsole, { (short)current.x, (short)current.y });
		SetConsoleTextAttribute(hConsole, 6);
		std::cout << '&';
		SetConsoleCursorPosition(hConsole, { 0, 15 });
		SetConsoleTextAttribute(hConsole, 7);*/
		animalPath->push_back(current);
		current = searchMap[current.ToInt()];
		
		//Sleep(500);
	}
	animalPath->push_back(Position);
	delete searchMap;
}