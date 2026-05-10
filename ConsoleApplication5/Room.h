#pragma once

class Hero;

enum class RoomType {
	Empty,
	Enemy,
	Shop,
	Treasure
};

enum RoomTypeWithEnemy {
	Goblin = 0,
	Orc = 1,
	Troll = 2
};

class Room {
public:
	RoomType type;
	RoomTypeWithEnemy enemyType;

	void enter(Hero& hero) const;
};