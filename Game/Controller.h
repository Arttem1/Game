#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <thread>

namespace Game {

class World;

class Controller
{
public:
    Controller (World* theWorld);

    virtual void run() = 0;
	void Stop();
	void wait();

    template<typename Functor>
    void DoBackgroundWork (Functor f)
    {
        myThread = new std::thread (f);
    }

protected:
    World* myWorld;
    std::thread* myThread = nullptr;
	bool myRunning = true;
};

}

#endif // CONTROLLER_H
