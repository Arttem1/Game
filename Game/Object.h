#ifndef OBJECT_H
#define OBJECT_H

#include "Coordinate.h"
#include <Windows.h>  

namespace Game {

class Object 
{
public:
	Object (char theSymbol, int theColor);
	virtual ~Object() { }

    Coordinate* GetPosition() const;
    void SetPosition (Coordinate* theCoordination);

	virtual bool IsEaten (Object* theObject) = 0; // True if one object is eating an another
	void print();
	virtual bool stop();
    

protected:
	char mySymbol = '.';
	int myColor = 0;

private:
	Coordinate* myPosition = nullptr;
};

}

#endif
