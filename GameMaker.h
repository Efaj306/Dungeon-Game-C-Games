#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class GameMaker
{
protected:
	
	int height;//height of map
	int width;//width of map
	char** map;//2d map
	int currPositionI;//current position of player in y axis
	int currPositionJ;//current p[osition of player in x axis
	int energy;//energy storing variable
	int points;//points storing variable
	int level;//level varaible
	int mon;//total monsters you kill
	int gem;
	int apple;
	int end;
public:
	GameMaker();//will create 2d map and store the values in variables
	void display();//to display map ,energy and points on console
	void seacrh(ifstream& fin);//to search the position of player
	void read(ifstream& fin);//to read different level maps from file to array
	void play();//to run the game
	~GameMaker();//destrcutor
};
