#include "World.h"
#include "Coordinate.h"
#include "Coin.h"
#include "Settings.h"

#include <mutex>

using namespace std;

namespace Game {



World::World()
    : myMap (Settings::RowSize, std::vector<Coordinate*> (Settings::ColumnSize, nullptr)),
      myPrintThread (nullptr)
{
    for (int y = 0; y < Settings::RowSize; y++) {
        for (int x = 0; x < Settings::ColumnSize; x++) {
            myMap[y][x] = new Coordinate (x, y);
        }
    }
}

void World::Run()
{
    //Functor f (this);
    //std::thread aPrintThread (f);
    myPrintThread = new std::thread ([this] () {
        while (myRunning) {
			system("CLS");
            PrintWorld();
            std::chrono::milliseconds aSleepTime (200);
            std::this_thread::sleep_for (aSleepTime);
        }
    });

    for (auto aController : myControllers) {
        aController->run();
    }
}

void World::Wait()
{
    myPrintThread->join();

	for (auto aController : myControllers) {
		aController->wait();
	}
}

void World::PrintWorld()
{
    for (auto aRow : myMap) {
        for (auto aCoordinate : aRow) {
            aCoordinate->print();
        }
        std::cout << std::endl;
    }
}

void World::AddObject (Object* theObject, int x, int y)
{
    auto aCoordination = myMap[y][x];
    aCoordination->SetObject (theObject);
}

void World::AddController (Controller* theController)
{
    myControllers.push_back (theController);
}

void World::MoveObject (DirectionX theValueX, DirectionY theValueY, Object* theObject)
{
	std::lock_guard<std::mutex> aLock (myCoordinatesMutex);
	auto aPreviousPosition = theObject->GetPosition();
    auto aNewY = aPreviousPosition->GetposY() + theValueY;
    auto aNewX = aPreviousPosition->GetposX() + theValueX;

    if (aNewY < 0 || aNewY >= Settings::RowSize) {
        return;
    }

    if (aNewX < 0 || aNewX >= Settings::ColumnSize) {
        return;
    }

	auto anObjectInNewPosition = myMap[aNewY][aNewX]->GetObj();

	if (!theObject) {
		return;
	}

	bool isEaten = theObject->IsEaten (anObjectInNewPosition);
	bool isEatenACoin = dynamic_cast<Coin*> (anObjectInNewPosition);

	if (anObjectInNewPosition && !isEaten) {
		return;
	}

    // Reset object in previous coorinate object
	aPreviousPosition->SetObject (nullptr);
    myMap[aNewY][aNewX]->SetObject (theObject);

	if ((isEaten && !isEatenACoin)) {
		myResult = false;
		Stop();
	}
	else if (theObject->stop()) {
		myResult = true;
		Stop();
	}
}

void World::Stop()
{
	for (auto aController : myControllers) {
		aController->Stop();
	}
	myRunning = false;
}

bool World::Result()
{
	return myResult;
}

}
