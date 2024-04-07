#ifndef POWERPUFF_H
#define POWERPUFF_H

#include <string>
#include <vector>

// Forward declaration of MojoJojo class
class MojoJojo;

// Abstract class for PowerPuffGirl
class PowerPuffGirl {
public:
    PowerPuffGirl(int dmg, int hp);
    virtual ~PowerPuffGirl();
    virtual std::string getName() const = 0;
    int getDamage() const;
    int getHealth() const;
    void takeDamage(int dmg);
    bool isAlive() const;
    virtual void attack(MojoJojo& villain) const = 0;
protected:
    int damage;
    int health;
};

// Derived class Bubbles
class Bubbles : public PowerPuffGirl {
public:
    Bubbles();
    std::string getName() const override;
    void attack(MojoJojo& villain) const override;
};

// Derived class Blossom
class Blossom : public PowerPuffGirl {
public:
    Blossom();
    std::string getName() const override;
    void attack(MojoJojo& villain) const override;
};

// Derived class Buttercup
class Buttercup : public PowerPuffGirl {
public:
    Buttercup();
    std::string getName() const override;
    void attack(MojoJojo& villain) const override;
};

// Professor class
class Professor {
public:
    Professor();
    void receiveIngredients(const std::vector<std::string>& ingredients);
    PowerPuffGirl* createPowerPuffGirl();
private:
    int sugar;
    int spice;
    int everythingNice;
};

// MojoJojo class
class MojoJojo {
public:
    MojoJojo(int dmg, int hp);
    void takeDamage(int dmg);
    bool isAlive() const;
    int getDamage() const;
    void attack(PowerPuffGirl* girl);
private:
    int damage;
    int health;
};

// Function to simulate battle between MojoJojo and PowerPuffGirls
void simulateBattle(Professor& professor, MojoJojo& mojoJojo);

#endif // POWERPUFF_H
