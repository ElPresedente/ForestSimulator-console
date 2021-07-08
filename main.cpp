#include <iostream>
#include "Terrain.h"
using namespace std;
#include <cstdlib>



int main() {
	int x, y;
	cout << "Type x & y\n";
	cin >> x >> y;
	cout << "Type keygen (uint)\n";
	unsigned int key;
	cin >> key;


	system("cls");
	Terrain::GenerateMap(x, y, key);

	Terrain::DrawFrame();
	return 0;
}