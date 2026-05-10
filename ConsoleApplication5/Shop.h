#pragma once
#include <string>
#include <iostream>
#include "Hero.h"
using namespace std;

class Shop {
public:
    const int DAMAGE_UPGRADE_COST = 50;
    const int HEAL_COST = 30;
    const int DODGE_CHANCE_COST = 40;

    void displayMenu() const;
    void buyDamageUpgrade(Hero& hero);
    void buyHeal(Hero& hero);
    void buyDodgeChance(Hero& hero);
    void enterShop(Hero& hero);
};
