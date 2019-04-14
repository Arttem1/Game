#include "Player.h"
#include "Monster.h"
#include "Coin.h"
#include "Settings.h"

namespace Game {

Player::Player()
	: Object('#', Settings::PlayerColor)
{

}

bool Player::IsEaten(Object* theObject)
{
	bool isMonster = dynamic_cast<Monster*> (theObject);
	bool isCoin = dynamic_cast<Coin*> (theObject);

	if (isCoin) {
		myCoinsCount++;
	}
	
	return isMonster || isCoin;
}

bool Player::stop()
{
	return myCoinsCount == Settings::CoinsCount;
}

int Player::CoinsCount() const
{
	return myCoinsCount;
}

}
