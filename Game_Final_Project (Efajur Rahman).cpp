#include "GameMaker.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main()
{
	GameMaker obj;
	ifstream fin("level1.txt");
	obj.read(fin);
	obj.display();
	ifstream fin1("level1.txt");
	obj.seacrh(fin1);
	obj.play();
}