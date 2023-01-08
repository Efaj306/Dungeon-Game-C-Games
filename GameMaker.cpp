#include "GameMaker.h"


GameMaker::GameMaker()
{
	cout << "                  *****        WELCOME TO TREASURE HUNT       *****               " << endl;
	cout << "            *****       ENTERED INTO MAGICAL DUNGEON,GOOD LUCK!           *****" << endl;
	currPositionI = 0;
	currPositionJ = 0;
	energy = 100;
	points = 0;
	level = 1;
	height = 0;
	width = 0;
	mon = 0;
	end = 0;
	map = new char*[height];
	for (int i = 0; i < width; i++)
	{
		map[i] = new char[width];
	}
}

void GameMaker::display()
{

	cout << "LEVEL"<<level<<" ENERGY:" << energy << "%;Points:" << points << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
void GameMaker::seacrh(ifstream& fin)
{
	char temp = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == 'P')
			{
				currPositionI = i;
			
				currPositionJ = j;
			
				break;
			}
		}
	}
	cout << "current Position" << currPositionI << ":" << currPositionJ << endl;
}
void GameMaker::read(ifstream& fin)
{
	fin >> width;
	fin >> height;
	map = new char*[height];
	for (int i = 0; i < width; i++)
	{
		map[i] = new char[width];
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			fin >> map[i][j];

		}
	}
}
void GameMaker::play()
{
	char temp = '\0';
	while (1)
	{
		
		
			cout << "PLEASE SELECT ACTION(move with wasd or Q to escape):";
			cin >> temp;
			if (temp == 'Q')
			{
				cout << "                           YOU QUIT THE GAME" << endl;
				cout << "                             TOTAL POINTS:" << points << endl;
				cout << "                      TOTAL MONSTERS YOU KILLED:" << mon << endl;
				cout << "                         TOTAL APPLES YOU EAT:" << apple << endl;
				cout << "                       TOTAL GEMS YOU COLLECTED:" << gem << endl;
				cout << "                         TOTAL LEVELS YOU WON:" << level - 1 << endl;
				end++;
				break;
			}
			if (end > 1)
			{
				break;
			}
			else if (temp == 'w')
			{
				cout << "moved up" << endl;
				map[currPositionI][currPositionJ] = '.';
				currPositionI--;
				if (map[currPositionI][currPositionJ] == 'X')
				{
					cout << "cann not move,moved back" << endl;
					currPositionI++;
				}

			}
			else if (temp == 's')
			{
				cout << "moved down" << endl;
				map[currPositionI][currPositionJ] = '.';
				currPositionI++;
				if (map[currPositionI][currPositionJ] == 'X')
				{
					cout << "cann not move,moved back" << endl;
					currPositionI--;
				}

			}
			else if (temp == 'a')
			{
				cout << "moved left" << endl;
				map[currPositionI][currPositionJ] = '.';
				currPositionJ--;
				if (map[currPositionI][currPositionJ] == 'X')
				{
					cout << "cann not move,moved back" << endl;
					currPositionJ++;
				}


			}
			else if (temp == 'd')
			{
				cout << "moved right" << endl;
				map[currPositionI][currPositionJ] = '.';
				currPositionJ++;
				if (map[currPositionI][currPositionJ] == 'X')
				{
					cout << "cann not move,moved back" << endl;
					currPositionJ--;
				}

			}
		
			else
			{
				cout << "Invalid input" << endl;
			}

			while (1)
			{

				if (temp == 'Q')
				{
					break;
				}
				else if (map[currPositionI][currPositionJ] == '.')
				{
					map[currPositionI][currPositionJ] = 'P';
					energy = energy - 5;
					break;
				}
				else if (map[currPositionI][currPositionJ] == 'M')
				{
					cout << "Monster Warning!!!" << endl;
					if (energy >= 50)
					{
						map[currPositionI][currPositionJ] = 'P';
						energy = energy - 20;
						mon++;
					}
					else if (energy < 50)
					{
						cout << "                        YOU LOST,BETTER LUCK NEXT TIME" << endl;
						cout << "                             TOTAL POINTS:" << points << endl;
						cout << "                      TOTAL MONSTERS YOU KILLED:" << mon << endl;
						cout << "                         TOTAL APPLES YOU EAT:" << apple << endl;
						cout << "                       TOTAL GEMS YOU COLLECTED:" << gem << endl;
						cout << "                         TOTAL LEVELS YOU WON:" << level - 1 << endl;
						temp = 'Q';
					}
					break;
				}
				else if (map[currPositionI][currPositionJ] == 'G')
				{
					cout << "FOUND GEM,HURRAY!" << endl;
					map[currPositionI][currPositionJ] = 'P';
					energy = energy - 5;
					points = points + 100;
					gem++;
					break;
				}
				else if (map[currPositionI][currPositionJ] == 'A')
				{
					cout << "FOUND APPLE,HURRAY!" << endl;
					map[currPositionI][currPositionJ] = 'P';
					energy = energy + 10;
					apple++;
					break;
				}
				else if (map[currPositionI][currPositionJ] == 'S')
				{
					cout << "SECRET PASSAGE FOUND,HURRAY!" << endl;
					map[currPositionI][currPositionJ] = 'P';
					level++;
					points = points + 1000;
					if (level > 5)
					{
						cout << "        ***    CONGRATULATIONS YOU HAVE COMPLETED ALL LEVELS,HURRAY!   ***         " << endl;
						cout << "                             TOTAL POINTS:" << points << endl;
						cout << "                      TOTAL MONSTERS YOU KILLED:" << mon << endl;
						cout << "                         TOTAL APPLES YOU EAT:" << apple << endl;
						cout << "                       TOTAL GEMS YOU COLLECTED:" << gem << endl;
						cout << "                         TOTAL LEVELS YOU WON:" << level - 1 << endl;
						break;
					}
					else if (temp == 'Q')
					{
						break;
					}
					else
					{
						energy = 100;
						cout << "            ***    WELCOME TO LEVEL:" << level << "   ***                 " << endl;
						cout << "    ***   BE CAREFUL,IT IT DIFFICULT THEN BEFORE,GOOD LUCK!   ***       " << endl;
						string s = "level";
						string s1 = to_string(level);
						string s2 = ".txt";
						s = s + s1 + s2;
						ifstream fin3;
						fin3.open(s);
						read(fin3);
						display();
						seacrh(fin3);
						play();
						break;
					}
					break;
				}
			
				else
				{
					break;
				}
				if (energy <= 0)
				{
					cout << "                        YOU LOST,BETTER LUCK NEXT TIME" << endl;
					cout << "                             TOTAL POINTS:" << points << endl;
					cout << "                      TOTAL MONSTERS YOU KILLED:" << mon << endl;
					cout << "                         TOTAL APPLES YOU EAT:" << apple << endl;
					cout << "                       TOTAL GEMS YOU COLLECTED:" << gem << endl;
					cout << "                         TOTAL LEVELS YOU WON:" << level - 1 << endl;
					break;
				}
				if (end > 0)
					break;
			}
		if (temp == 'Q')
		{
			break;
		}
		if (energy <= 0)
		{
			cout << "                        YOU LOST,BETTER LUCK NEXT TIME" << endl;

			cout << "                             TOTAL POINTS:" << points << endl;
			cout << "                      TOTAL MONSTERS YOU KILLED:" << mon << endl;
			cout << "                         TOTAL APPLES YOU EAT:" << apple << endl;
			cout << "                       TOTAL GEMS YOU COLLECTED:" << gem << endl;
			cout << "                         TOTAL LEVELS YOU WON:" << level - 1 << endl;
			break;
		}
		if (level > 5)
		{
			break;
		}
		if (end > 0)
			break;
		display();
	}
}
GameMaker::~GameMaker()
{
	delete *map;
	map = nullptr;
}
