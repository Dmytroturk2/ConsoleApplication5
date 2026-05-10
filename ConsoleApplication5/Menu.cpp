#include "Menu.h"
#include "Hero.h"
#include <iostream>
using namespace std;

void Menu::displayMainMenu() const {
	cout << "===== MAIN MENU =====" << endl;
	cout << "1. Start Game" << endl;
	cout << "2. Exit Game" << endl;
	cout << "3. Print Status" << endl;
	cout << "4. Exit game" << endl;
	cout << "=====================" << endl;
}
