#pragma once
#include <string>
using namespace std;

class Enemy {
public:
	int hp;
	int damage;
	string name;
	//string Skill;

	Enemy(int h, int d, const string& n);

	bool IsAlive() const;
	int damageToHero(int dmg) const;
	void printInfo() const;
};

