#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

namespace Game {

class Object;

class Coordinate
{
public:
	Coordinate();
    Coordinate(int , int);
    ~Coordinate();

	int GetposX() const;
	void SetposX(int);

	int GetposY() const;
	void SetposY(int);

    Object* GetObj();
	void SetObject(Object*);

    void print();

private:
    unsigned int myX;
    unsigned int myY;

    Object* myObject;
};

}

#endif
