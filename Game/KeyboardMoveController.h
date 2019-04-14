#ifndef KEYBOARDMOVECONTROLLER_H
#define KEYBOARDMOVECONTROLLER_H

#include "Enums.h"
#include "Controller.h"
#include <thread>

namespace Game {

class Object;
class World;

class KeyboardMoveController : public Controller
{
public:
    KeyboardMoveController (World* theWorld, Object* theObject);

    void move (DirectionX theX, DirectionY theY);

    void run() override;

public:
    Object* myObject;
};

}

#endif // KEYBOARDMOVECONTROLLER_H
