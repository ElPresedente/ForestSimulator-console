#include <iostream>
#include "Terrain.h"
using namespace std;
#include <cstdlib>
#include <Windows.h>


int main() {
	int x, y;
	cout << "Type x & y\n";
	cin >> x >> y;
	cout << "Type keygen (uint)\n";
	unsigned int key;
	cin >> key;


	system("cls");
	Terrain::GenerateMap(x, y, key);
	for (int n = 0; n < 10; n++) {
		
		for (size_t i = 0; i < Terrain::entities.size(); i++) { //main events loop
			Terrain::entities[i]->EntityFunction();
		}

		system("cls");
		Terrain::DrawFrame(); //draw new frame
		Sleep(1000);
	}
	
	return 0;
}