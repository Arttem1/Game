#include "Object.h"
#include "Settings.h"

#include <Windows.h>

namespace Game {


void SetColor(int text, int bg)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}


Object::Object(char theSymbol, int theColor)
	: mySymbol (theSymbol), myColor (theColor)
{

}

void Object::print()
{
	SetColor(myColor, 0);
	std::cout << mySymbol;
	SetColor(Settings::DefaultColor, 0);
}

bool Object::stop()
{
	return false;
}

void Object::SetPosition (Coordinate* theCoordination)
{
    myPosition = theCoordination;
}

Coordinate* Object::GetPosition() const
{
	return myPosition;
}

}
