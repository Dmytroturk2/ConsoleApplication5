#include "Event.h"
#include "Hero.h"
#include "Enemy.h"
#include "Menu.h"
#include "Shop.h"
#include "Room.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

bool isGameRunning = false;

void displayGameMenu() {
	cout << "\n===== DUNGEON ADVENTURE =====" << endl;
	cout << "1. Enter next room" << endl;
	cout << "2. View status" << endl;
	cout << "3. Exit game" << endl;
	cout << "=============================" << endl;
}

Room createRandomRoom() {
	Room newRoom;
	int randomType = rand() % 10;
	
	if (randomType < 4) {
		newRoom.type = RoomType::Enemy;
		int randomEnemy = rand() % 3;
		newRoom.enemyType = static_cast<RoomTypeWithEnemy>(randomEnemy);
	}
	else if (randomType < 6) {
		newRoom.type = RoomType::Empty;
	}
	else if (randomType < 8) {
		newRoom.type = RoomType::Shop;
	}
	else {
		newRoom.type = RoomType::Treasure;
	}
	
	return newRoom;
}

void displayRoomType(const Room& room) {
	cout << "Room type: ";
	switch (room.type) {
	case RoomType::Empty:
		cout << "[Empty Room]" << endl;
		break;
	case RoomType::Enemy:
		cout << "[Enemy Room - ";
		if (room.enemyType == RoomTypeWithEnemy::Goblin) {
			cout << "Goblin]" << endl;
		}
		else if (room.enemyType == RoomTypeWithEnemy::Orc) {
			cout << "Orc]" << endl;
		}
		else if (room.enemyType == RoomTypeWithEnemy::Troll) {
			cout << "Troll]" << endl;
		}
		break;
	case RoomType::Shop:
		cout << "[Shop]" << endl;
		break;
	case RoomType::Treasure:
		cout << "[Treasure Room]" << endl;
		break;
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	
	cout << "===== WELCOME TO DUNGEON ADVENTURE =====" << endl;
	cout << "Enter your hero's name: ";
	string heroName;
	getline(cin, heroName);
	
	if (heroName.empty()) {
		heroName = "Hero";
	}
	
	Hero hero(heroName);
	isGameRunning = true;
	int roomCount = 0;
	
	cout << "\nGame Started!" << endl;
	hero.printStatus();
	
	while (isGameRunning && hero.isAlive()) {
		displayGameMenu();
		
		int choice;
		cout << "Your choice: ";
		cin >> choice;
		cin.ignore();
		
		switch (choice) {
		case 1: {
			roomCount++;
			cout << "\n--- Room " << roomCount << " ---" << endl;
			
			Room currentRoom = createRandomRoom();
			displayRoomType(currentRoom);
			
			currentRoom.enter(hero);
			
			if (!hero.isAlive()) {
				cout << "\nYou died..." << endl;
				cout << "You survived " << roomCount - 1 << " rooms." << endl;
				isGameRunning = false;
			}
			
			break;
		}
		case 2: {
			cout << endl;
			hero.printStatus();
			cout << "Rooms cleared: " << roomCount << endl;
			break;
		}
		case 3: {
			cout << "Thanks for playing!" << endl;
			isGameRunning = false;
			break;
		}
		default:
			cout << "Invalid choice!" << endl;
			break;
		}
	}
	
	if (!hero.isAlive()) {
		cout << "\n===== GAME OVER =====" << endl;
		cout << "Hero: " << hero.name << endl;
		cout << "Final HP: " << hero.hp << "/" << hero.MaxHp << endl;
		cout << "Rooms cleared: " << roomCount - 1 << endl;
		cout << "=====================" << endl;
	}
	
	return 0;
}
