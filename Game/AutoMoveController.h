#ifndef AUTOMOVECONTROLLER_H
#define AUTOMOVECONTROLLER_H

#include "Enums.h"
#include "Controller.h"
#include <thread>
#include <vector>

namespace Game {

class Object;
class World;

class AutoMoveController : public Controller
{
public:
	AutoMoveController (World* theWorld);

    void run() override;

	void AddObject (Object* theObject);

public:
	std::vector<Object*> myObjects;
};

}

#endif // AUTOMOVECONTROLLER_H
