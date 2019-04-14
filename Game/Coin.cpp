#include "Coin.h"
#include "Settings.h"

namespace Game {

Coin::Coin()
	: Object ('$', Settings::CoinColor)
{

}

bool Coin::IsEaten (Object* theObject)
{
	return false;
}

}
