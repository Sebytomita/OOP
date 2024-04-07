#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "powerpuff.h"

int main() {
    srand(time(nullptr));
    Professor professor;
    std::vector<std::string> ingredients = {"sugar", "spice", "spice", "everything_nice", "sugar"};
    professor.receiveIngredients(ingredients);
    MojoJojo mojoJojo(25, 200);
    simulateBattle(professor, mojoJojo);
    return 0;
}
