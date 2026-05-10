#pragma once
#include <string>
#include <iostream>
class Menu {
public:
	int choice;

	void startGame();
	void ExitGame() const;
	void printStatus() const;
	void displayMainMenu() const;
	int getUserChoice() const;
};

