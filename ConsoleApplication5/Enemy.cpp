#include "Enemy.h"
#include <iostream>
using namespace std;

Enemy::Enemy(int h, int d, const string& n) : hp(h), damage(d), name(n) {}

bool Enemy::IsAlive() const {
	return hp > 0;
}
int Enemy::damageToHero(int dmg) const {
	return dmg;
}
void Enemy::printInfo() const {
	cout << "Enemy: " << name << endl;
	cout << "HP: " << hp << endl;
	cout << "Damage: " << damage << endl;
	//cout << "Skill: " << Skill << endl;
}