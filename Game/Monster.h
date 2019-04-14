#ifndef MONSTER_H
#define MONSTER_H

#include "Object.h"

namespace Game {

class Monster :public Object
{
public:
    Monster();
	bool IsEaten(Object* theObject) override;
};

}

#endif
