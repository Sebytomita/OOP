#include "powerpuff.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Implementation of PowerPuffGirl methods
PowerPuffGirl::PowerPuffGirl(int dmg, int hp) : damage(dmg), health(hp) {}
PowerPuffGirl::~PowerPuffGirl() {}

int PowerPuffGirl::getDamage() const {
    return damage;
}

int PowerPuffGirl::getHealth() const {
    return health;
}

void PowerPuffGirl::takeDamage(int dmg) {
    health -= dmg;
}

bool PowerPuffGirl::isAlive() const {
    return health > 0;
}

// Implementation of Bubbles methods
Bubbles::Bubbles() : PowerPuffGirl(10, 100) {}
std::string Bubbles::getName() const {
    return "Bubbles";
}

void Bubbles::attack(MojoJojo& villain) const {
    villain.attack(const_cast<Bubbles*>(this));
}

// Implementation of Blossom methods
Blossom::Blossom() : PowerPuffGirl(15, 100) {}
std::string Blossom::getName() const {
    return "Blossom";
}

void Blossom::attack(MojoJojo& villain) const {
    villain.attack(const_cast<Blossom*>(this));
}

// Implementation of Buttercup methods
Buttercup::Buttercup() : PowerPuffGirl(20, 100) {}
std::string Buttercup::getName() const {
    return "Buttercup";
}

void Buttercup::attack(MojoJojo& villain) const {
    villain.attack(const_cast<Buttercup*>(this));
}

// Implementation of Professor methods
Professor::Professor() : sugar(0), spice(0), everythingNice(0) {}

void Professor::receiveIngredients(const std::vector<std::string>& ingredients) {
    for (const auto& ingredient : ingredients) {
        if (ingredient == "sugar") sugar++;
        else if (ingredient == "spice") spice++;
        else if (ingredient == "everything_nice") everythingNice++;
    }
}

PowerPuffGirl* Professor::createPowerPuffGirl() {
    if (sugar >= 1 && spice >= 1 && everythingNice >= 1) {
        sugar--;
        spice--;
        everythingNice--;
        int random = rand() % 3;
        if (random == 0) return new Buttercup();
        else if (random == 1) return new Blossom();
        else return new Bubbles();
    }
    return nullptr; // Not enough ingredients to create PowerPuffGirl
}

// Implementation of MojoJojo methods
MojoJojo::MojoJojo(int dmg, int hp) : damage(dmg), health(hp) {}

void MojoJojo::takeDamage(int dmg) {
    health -= dmg;
}

bool MojoJojo::isAlive() const {
    return health > 0;
}

int MojoJojo::getDamage() const {
    return damage;
}

void MojoJojo::attack(PowerPuffGirl* girl) {
    girl->takeDamage(damage);
}

// Function to simulate battle between MojoJojo and PowerPuffGirls
void simulateBattle(Professor& professor, MojoJojo& mojoJojo) {
    std::vector<PowerPuffGirl*> girls;
    while (true) {
        PowerPuffGirl* girl = professor.createPowerPuffGirl();
        if (girl == nullptr) break; // No more PowerPuffGirls can be created
        girls.push_back(girl);
    }
    std::cout << "PowerPuffGirls created: " << girls.size() << std::endl;
    
    while (mojoJojo.isAlive() && !girls.empty()) {
        for (auto& girl : girls) {
            mojoJojo.attack(girl);
            if (!mojoJojo.isAlive()) break;
        }
        if (!mojoJojo.isAlive()) break;
        
        int randomIndex = rand() % girls.size();
        PowerPuffGirl* targetGirl = girls[randomIndex];
        targetGirl->attack(mojoJojo);
        if (!targetGirl->isAlive()) {
            delete targetGirl;
            girls.erase(girls.begin() + randomIndex);
        }
    }
    
    std::cout << "Battle result:" << std::endl;
    if (mojoJojo.isAlive()) {
        std::cout << "MojoJojo wins!" << std::endl;
    } else {
        std::cout << "PowerPuffGirls win!" << std::endl;
    }
    
    std::cout << "Surviving PowerPuffGirls:" << std::endl;
    for (const auto& girl : girls) {
        std::cout << girl->getName() << " - Health: " << girl->getHealth() << std::endl;
        delete girl;
    }
}
