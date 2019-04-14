#include "Controller.h"

namespace Game {

Controller::Controller (World* theWorld)
    : myWorld (theWorld)
{
}

void Controller::Stop()
{
	myRunning = false;
}

void Controller::wait()
{
	myThread->join();
}

}
