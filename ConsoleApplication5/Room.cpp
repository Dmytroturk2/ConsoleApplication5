#include "Room.h"
#include "Hero.h"
#include "Enemy.h"
#include "Shop.h"
#include "Event.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

void Room::enter(Hero& hero) const {
	switch (type) {
	case RoomType::Empty:
		cout << "You entered an empty room. Nothing happens." << endl;
		break;
	case RoomType::Enemy: {
		Enemy enemy(0, 0, "");
		
		if (enemyType == RoomTypeWithEnemy::Goblin) {
			enemy = Enemy(100, 10 + rand() % 31, "Goblin");
			cout << "\nYou encountered a Goblin!" << endl;
		}
		else if (enemyType == RoomTypeWithEnemy::Orc) {
			enemy = Enemy(110, 10 + rand() % 41, "Orc");
			cout << "\nYou encountered an Orc!" << endl;
		}
		else if (enemyType == RoomTypeWithEnemy::Troll) {
			enemy = Enemy(150, 30 + rand() % 31, "Troll");
			cout << "\nYou encountered a Troll!" << endl;
		}
		
		enemy.printInfo();
		
		// Боевой цикл
		Event event;
		event.enemy = enemy;
		
		while (hero.isAlive() && event.enemy.IsAlive()) {
			cout << "\n--- Battle ---" << endl;
			cout << "Your HP: " << hero.hp << endl;
			cout << "Enemy HP: " << event.enemy.hp << endl;
			cout << endl;
			
			event.fight(hero);
		}
		
		if (event.enemy.IsAlive()) {
			cout << "\nYou lost the battle..." << endl;
		}
		else {
			cout << "\nYou won! Enemy defeated!" << endl;
			int goldReward = 50 + (rand() % 100);
			hero.balance += goldReward;
			cout << "Reward: " << goldReward << " gold" << endl;
		}
		
		break;
	}
	case RoomType::Shop: {
		Shop shop;
		cout << "\nYou entered a shop." << endl;
		shop.enterShop(hero);
		break;
	}
	case RoomType::Treasure: {
		cout << "\nYou found a treasure room!" << endl;
		int goldFound = 50 + (rand() % 150);
		hero.balance += goldFound;
		cout << "You found " << goldFound << " gold!" << endl;
		break;
	}
	}
}
