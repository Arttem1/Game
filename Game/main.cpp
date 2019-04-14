#include "World.h"
#include "Coin.h"
#include "Settings.h"
#include "KeyboardMoveController.h"
#include "AutoMoveController.h"
#include "Player.h"
#include "Monster.h"

#include <random>
#include <time.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;
using namespace Game;

struct XY {
	XY(int theX, int theY) : x(theX), y(theY) { }

	bool operator== (const XY& theOther) const
	{
		return x == theOther.x && y == theOther.y;
	}

	bool operator!= (const XY& theOther) const
	{
		return !(*this == theOther);
	}

	int x;
	int y;
};

// true if theTarget exist in theSource container
bool ExistIn (const std::vector<XY>& theSource, const XY& theXY)
{
	auto anIt = std::find(theSource.begin(), theSource.end(), theXY);
	return anIt != theSource.end();
}

// third parameter theExclude allows to provide a position to avoid to genegate
void GenerateRandomCoordinates (std::vector<XY>& theResult, int theNumber, const std::vector<XY>& theExclude = std::vector<XY>())
{
	XY aPos(0, 0);
	for (int i = 0; i < theNumber; i++) {
		while (true) {
			aPos = XY(std::rand() % Settings::ColumnSize, // x
					  std::rand() % Settings::RowSize);   // y

			if (!ExistIn (theResult, aPos)     // exclude my positions
				&& !ExistIn (theExclude, aPos) // exclude another positions
				&& aPos != XY (0, 0)) {        // exclude player position
				break;
			}
		}
		
		theResult.push_back (aPos);
	}
}

int main(int argc, char *argv[]) 
{
    setlocale(0, "rus");
	std::srand(time(0));

    World h;
	
	// 1. Add player
    auto aPlayer = new Player();
    auto aPlayerController = new KeyboardMoveController (&h, aPlayer);
	h.AddObject(aPlayer, 0, 0);
	h.AddController(aPlayerController);

	// 2. Add monsters

	// 2.1. Add create and attach to world an auto move controller
	auto anMonstersController = new AutoMoveController(&h);
	h.AddController (anMonstersController);

	// 2.2 Generate positions
	std::vector<XY> aMonstersCoordinates;
	GenerateRandomCoordinates (aMonstersCoordinates, Settings::MonstersCount);

	// 2.3 Create and add monsters to world and controller
	for (int i = 0; i < Settings::MonstersCount; i++)
	{
		auto aMonster = new Monster();
		auto anXY = aMonstersCoordinates[i];
		h.AddObject(aMonster, anXY.x, anXY.y);
		anMonstersController->AddObject(aMonster);
	}

	// 3. Add coins
	std::vector<XY> aCoinsCoordinates;
	GenerateRandomCoordinates (aCoinsCoordinates, Settings::CoinsCount, aMonstersCoordinates); // exclude monster positions

	// 3.1 Add coins to world
	for (int i = 0; i < Settings::CoinsCount; i++)
	{
		auto aCoin = new Coin();
		auto anXY = aCoinsCoordinates[i];
		h.AddObject(aCoin, anXY.x, anXY.y);
	}

	// 4. Run and wait

    h.Run();
    h.Wait();

	// 5. Print game result
	std::cout << "*********" << std::endl;
	if (h.Result()) {
		std::cout << "Game is WIN!" << std::endl;
	}
	else {
		std::cout << "Game is LOST!" << std::endl;
	}
	std::cout << "Coins count: " << aPlayer->CoinsCount() << std::endl;
	std::cout << "*********" << std::endl;

	// 6. Pause
	system("pause");

	return 0;
}
