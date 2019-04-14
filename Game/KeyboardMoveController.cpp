#include "KeyboardMoveController.h"
#include "Object.h"
#include "World.h"

namespace Game {

KeyboardMoveController::KeyboardMoveController (World* theWorld, Object* theObject)
    : Controller (theWorld),
      myObject (theObject)
{

}

void KeyboardMoveController::move (DirectionX theX, DirectionY theY)
{
	if (!myObject->GetPosition()) { // i killed
		return;
	}
    myWorld->MoveObject (theX, theY, myObject);
}

void KeyboardMoveController::run()
{    
    DoBackgroundWork ([this] () {
        while (myRunning) {
            char symbol = _getch();
            if (symbol == -32) {
                char symbol = _getch();
                switch (symbol)
                {
                case 72:
                    move (DefaultX, Down);
                    break;
                case 75:
                    move (Left, DefaultY);
                    break;
                case 77:
                    move (Right, DefaultY);
                    break;
                case 80:
                    move (DefaultX, Up);
                    break;
                default:
                    break;
                }
            }
        }
    });
}

}
