#include "DataStructures.h"
#include "Terrain.h"
#include <cstdlib>
#include <Windows.h>
#include <string>

using namespace std;


int main() {
	int x, y; 
	//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleCursorPosition(hConsole, { 0,0 });
	//int k = 6;
	//SetConsoleTextAttribute(hConsole, k);
	
	cout << "Type x & y\n";
	//cin >> x >> y;
	x = 20; y = 10;
	//SetConsoleTextAttribute(hConsole, 7);
	cout << "Type keygen (uint)\n";
	unsigned int key;
	//cin >> key;
	key = 1111;
	Terrain::GenerateMap(x, y, key);

	system("cls");
	Terrain::DrawFrame();

	//for (int n = 0; n < 10; n++) {
	Sleep(100);
		for (size_t i = 0; i < Terrain::entities.size(); i++) { //main events loop
			Terrain::entities[i]->EntityFunction();
		}
	
	//	system("cls");
	//	Terrain::DrawFrame(); //draw new frame
	//	Sleep(1000);
	//}
	
	return 0;
}