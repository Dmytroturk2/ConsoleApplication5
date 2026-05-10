#pragma once
#include <string>
#include <iostream>
#include "Hero.h"
#include "Enemy.h"
using namespace std;

class Event {
public:
	int shield;
	int trap;
	int dmg;

	Enemy enemy;

	Event();
	int ifUsedShieldYou() const;
	int ifUsedShieldEnemy() const;
	int ifYouTrapped() const;
	int damageToHero(int dmg) const;
	void fight(Hero& hero);
};

