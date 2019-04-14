#ifndef COIN_H
#define COIN_H

#include "Object.h"

namespace Game {

class Coin :public Object
{
public:
	Coin();
	bool IsEaten (Object* /*theObject*/) override;
};

}

#endif //COIN_H
