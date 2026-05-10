#include "Shop.h"

void Shop::displayMenu() const {
    cout << "\n===== SHOP =====" << endl;
    cout << "1. Damage Upgrade - " << DAMAGE_UPGRADE_COST << " balance" << endl;
    cout << "2. Heal - " << HEAL_COST << " balance" << endl;
    cout << "3. Dodge Chance - " << DODGE_CHANCE_COST << " balance" << endl;
    cout << "4. Exit Shop" << endl;
    cout << "===============" << endl;
}

void Shop::buyDamageUpgrade(Hero& hero) {
    if (hero.balance >= DAMAGE_UPGRADE_COST) {
        hero.balance -= DAMAGE_UPGRADE_COST;
        hero.damage += 10;
        cout << "Damage upgraded! New damage: " << hero.damage << endl;
    } else {
        cout << "Not enough balance!" << endl;
    }
}

void Shop::buyHeal(Hero& hero) {
    if (hero.balance >= HEAL_COST) {
        hero.balance -= HEAL_COST;
        hero.heal(50);
        cout << "Healed! Current HP: " << hero.hp << endl;
    } else {
        cout << "Not enough balance!" << endl;
    }
}

void Shop::buyDodgeChance(Hero& hero) {
    if (hero.balance >= DODGE_CHANCE_COST) {
        hero.balance -= DODGE_CHANCE_COST;
        cout << "Dodge chance increased!" << endl;
    } else {
        cout << "Not enough balance!" << endl;
    }
}

void Shop::enterShop(Hero& hero) {
    hero.inShop = true;
    int choice = 0;
    while (true) {
        displayMenu();
        cout << "Current balance: " << hero.balance << endl;
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                buyDamageUpgrade(hero);
                break;
            case 2:
                buyHeal(hero);
                break;
            case 3:
                buyDodgeChance(hero);
                break;
            case 4:
                cout << "Exiting shop..." << endl;
                hero.inShop = false;
                return;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
