#include "Monster.h"
#include "Player.h"
#include "Settings.h"

namespace Game {

Monster::Monster()
	: Object('%', Settings::MonsterColor)
{
}

bool Monster::IsEaten(Object* theObject)
{
	return dynamic_cast<Player*> (theObject);
}

}
