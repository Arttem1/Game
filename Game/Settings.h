#ifndef SETTINGS_H
#define SETTINGS_H

#include <Windows.h>

namespace Game {

class Settings {
public:
	// Area size
	static const int ColumnSize    = 80;
	static const int RowSize       = 25;

	// Objects counts
	static const int MonstersCount = 30;
	static const int CoinsCount    = 2;

	// Colors
	static const int DefaultColor  = 7;
	static const int PlayerColor   = 14; // yellow
	static const int MonsterColor  = FOREGROUND_RED;
	static const int CoinColor     = FOREGROUND_GREEN;
};

}

#endif // SETTINGS_H
