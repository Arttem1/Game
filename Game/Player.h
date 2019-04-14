#ifndef PLAYER_H
#define PLAYER_H

#include "Object.h"

namespace Game {

class Player : public Object
{
public:
    Player();
	bool IsEaten(Object* theObject) override;
	bool stop() override;
	int CoinsCount() const;
private:
	int myCoinsCount = 0;
};

}

#endif
