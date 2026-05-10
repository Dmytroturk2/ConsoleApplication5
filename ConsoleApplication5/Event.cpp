#include "Event.h"
#include "Hero.h"
#include "Enemy.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Event::Event() : shield(0), trap(0), dmg(30), enemy(0, 0, "") {
}

int Event::ifUsedShieldYou() const {
	return rand() % 2;
}

int Event::ifUsedShieldEnemy() const {
	return rand() % 2;
}

int Event::ifYouTrapped() const {
	return rand() % 2;
}

int Event::damageToHero(int dmg) const {
	return dmg;
}

void Event::fight(Hero& hero) {
	int heroDamage = 0;
	int hitChance = 0;
	bool confirmed = false;
	
	// Выбор урона героем
	while (!confirmed) {
		cout << "Enter damage (1-" << enemy.hp << "): ";
		cin >> heroDamage;
		cin.ignore();
		
		if (heroDamage < 1 || heroDamage > enemy.hp) {
			cout << "Invalid damage! Enter from 1 to " << enemy.hp << endl;
			continue;
		}
		
		// Чем больше урона, тем меньше шанс
		hitChance = 95 - heroDamage;
		if (hitChance < 5) hitChance = 5;
		
		cout << "\nDamage: " << heroDamage << endl;
		cout << "Hit chance: " << hitChance << "%" << endl;
		cout << "1. Confirm attack  2. Change damage: ";
		int choice;
		cin >> choice;
		cin.ignore();
		
		if (choice == 1) {
			confirmed = true;
		}
	}
	
	// Атака героя на врага
	cout << "\nYou attack!" << endl;
	int random = rand() % 100;
	
	if (random < hitChance) {
		int damageDealt = heroDamage;
		
		// Проверка щита врага
		if (ifUsedShieldEnemy() == 1) {
			cout << "Enemy raised shield! Damage reduced by 50%." << endl;
			damageDealt = heroDamage / 2;
		}
		
		cout << "Hit! You dealt " << damageDealt << " damage!" << endl;
		enemy.hp -= damageDealt;
		cout << "Enemy HP: " << enemy.hp << endl;
	}
	else {
		cout << "Miss!" << endl;
	}
	
	// Атака врага на героя
	cout << "\nEnemy attacks!" << endl;
	int damageToHero = enemy.damage;
	
	// Проверка щита героя
	if (ifUsedShieldYou() == 1) {
		cout << "You raised shield! Damage reduced by 50%." << endl;
		damageToHero = enemy.damage / 2;
	}
	
	hero.takeDamage(damageToHero);
	cout << "You took " << damageToHero << " damage!" << endl;
	cout << "Your HP: " << hero.hp << endl;
}


