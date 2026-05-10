#pragma once
#include <string>
#include <vector>
using namespace std;

//const int MAX_SKILL_FOR_HERO = 3;

class Hero {
public:
    string name;
    int hp, MaxHp;
    int damage;
    vector<string> skills;
    double balance;
    bool inShop;

    Hero(string name, int hp = 100);
    bool isAlive() const;
    void takeDamage(int dmg);
    void heal(int amount);
    void printStatus() const;
};

