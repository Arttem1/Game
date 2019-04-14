#include "AutoMoveController.h"
#include "Object.h"
#include "World.h"
#include "Settings.h"

#include <random>
#include <time.h>
#include <chrono>

namespace Game {

AutoMoveController::AutoMoveController (World* theWorld)
	: Controller (theWorld)
{

}

void AutoMoveController::AddObject(Object* theObject)
{
	myObjects.push_back (theObject);
}

void AutoMoveController::run()
{
	std::srand(time(0));

    DoBackgroundWork ([this] () {
		while (myRunning) {
			for (int i = 0; i < Settings::MonstersCount / 3; i++) {
				auto aNumberX = std::rand() % 3 - 1;
				auto aNumberY = std::rand() % 3 - 1;

				auto index = std::rand() % myObjects.size();

				myWorld->MoveObject (static_cast<DirectionX> (aNumberX), static_cast<DirectionY> (aNumberY), myObjects[index]);
			}
			std::chrono::milliseconds aSleepTime (220);
			std::this_thread::sleep_for (aSleepTime);
		}
    });
}

}
