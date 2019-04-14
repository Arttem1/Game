#ifndef WORLD_H
#define WORLD_H

#include "Controller.h"
#include "Enums.h"

#include <conio.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

namespace Game {

class Coordinate;
class Object;

class World
{
public:
	World();

    void Run();
	void Stop();
    void Wait();
    
    void AddObject (Object* theObject, int x, int y);
    void AddController (Controller* theController);
    void MoveObject (DirectionX theValueX, DirectionY theValueY, Object* theObject);

	bool Result();

protected:
	void PrintWorld();

private:
    std::vector<std::vector<Coordinate*>> myMap;
    std::vector<Controller*> myControllers;
    std::thread* myPrintThread;
	bool myRunning = true;
	bool myResult = false;
	std::mutex myCoordinatesMutex;
};

}

#endif
