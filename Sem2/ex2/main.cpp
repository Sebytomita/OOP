#include <iostream>
#include "Masina.h"

int main() {
    Masina masina("Dacia", 50, 0.05f, 10000); // Creăm o instanță a clasei Masina

    // Afișăm informațiile inițiale ale mașinii
    std::cout << "Informatii masina:\n";
    std::cout << "Firma: " << masina.getFirma() << std::endl;
    std::cout << "Numar litri combustibil: " << masina.getNrLitriCombustibil() << std::endl;
    std::cout << "Consum: " << masina.getConsum() << " litri/km" << std::endl;
    std::cout << "Kilometraj: " << masina.getKilometraj() << " km" << std::endl;

    // Simulăm o cursă de 200 km
    masina.cursa(200);

    // Afișăm informațiile actualizate ale mașinii după cursă
    std::cout << "\nDupa cursa de 200 km:\n";
    std::cout << "Numar litri combustibil ramasi: " << masina.getNrLitriCombustibil() << std::endl;
    std::cout << "Kilometraj actualizat: " << masina.getKilometraj() << " km" << std::endl;

    // Aplicăm metoda bisnitar pentru a reduce kilometrajul cu 1000 km
    masina.bisnitar();

    // Afișăm informațiile după aplicarea metodei bisnitar
    std::cout << "\nDupa aplicarea metodei bisnitar:\n";
    std::cout << "Kilometraj actualizat: " << masina.getKilometraj() << " km" << std::endl;

    return 0;
}
