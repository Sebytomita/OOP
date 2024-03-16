#include "Math.h"
#include <iostream>

using namespace std;

int main() {
    // Example usage of all methods
    cout << "Add(1, 2) = " << Math::Add(1, 2) << '\n';
    cout << "Add(1, 2, 3) = " << Math::Add(1, 2, 3) << '\n';
    cout << "Add(1.1, 2.2) = " << Math::Add(1.1, 2.2) << '\n';
    cout << "Add(1.1, 2.2, 3.3) = " << Math::Add(1.1, 2.2, 3.3) << '\n';
    cout << "Mul(1, 2) = " << Math::Mul(1, 2) << '\n';
    cout << "Mul(1, 2, 3) = " << Math::Mul(1, 2, 3) << '\n';
    cout << "Mul(1.1, 2.2) = " << Math::Mul(1.1, 2.2) << '\n';
    cout << "Mul(1.1, 2.2, 3.3) = " << Math::Mul(1.1, 2.2, 3.3) << '\n';

    cout << "suma pt: 1, 2, 3, 4, 5 = " << Math::Add(5, 1, 2, 3, 4, 5) << '\n';

    char* prop = Math::Add("buna", " ziua");
    if (prop != nullptr) {
        cout << "propozitie finala " << prop << '\n';
        delete[] prop;
    } 
    else {
        cout << "eroare" << '\n';
    }

    return 0;
}
