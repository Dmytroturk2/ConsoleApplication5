#include "Hero.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Hero::Hero(string name, int hp) : name(name), hp(hp), MaxHp(hp), damage(10), balance(100), inShop(false) {
}

bool Hero::isAlive() const {
	return hp > 0;
}
void Hero::takeDamage(int dmg) {
	hp -= dmg;
	if (hp < 0) hp = 0;
}
void Hero::heal(int amount) {
	hp += amount;
	if (hp > MaxHp) hp = MaxHp;
}
void Hero::printStatus() const {
	cout << "Hero: " << name << endl;
	cout << "HP: " << hp << "/" << MaxHp << endl;
	cout << "Damage: " << damage << endl;
	cout << "Balance: " << balance << endl;
	cout << "Skills: ";
	for (const auto& skill : skills) {
		cout << skill << " ";
	}
	cout << endl;
}
