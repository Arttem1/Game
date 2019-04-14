#include "Coordinate.h"
#include "Object.h"

namespace Game {

Coordinate::Coordinate()
    : myX (0), myY (0), myObject (nullptr)
{

}

Coordinate::Coordinate (int x, int y)
    : myObject (nullptr)
{
    myX = x;
    myY = y;
}

int Coordinate::GetposX() const
{
    return myX;
}

int Coordinate::GetposY() const
{
    return myY;
}

void Coordinate::SetposX(int theposX) 
{
    myX = theposX;
}

void Coordinate::SetposY(int theposY)
{
    myY = theposY;
}

void Coordinate::print()
{
    if (myObject) {
        myObject->print();
        return;
    }

    std::cout << ".";
}

Object* Coordinate::GetObj()
{
	return myObject;
}

void Coordinate::SetObject (Object* theObject)
{
	if (myObject) {
		myObject->SetPosition (nullptr);
	}
	this->myObject = theObject;
	if (theObject) {
		theObject->SetPosition (this);
	}
}

Coordinate::~Coordinate()
{
	delete myObject;
}

}
