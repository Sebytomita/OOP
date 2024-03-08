#ifndef MASINA_H
#define MASINA_H

#include <string>

class Masina {
private:
    std::string firma;
    int nrLitriCombustibil;
    float consum;
    int kilometraj;

public:
    // Constructor
    Masina(const std::string& firma, int nrLitriCombustibil, float consum, int kilometraj);

    // Getteri și setteri
    void setFirma(const std::string& firma);
    std::string getFirma() const;

    void setNrLitriCombustibil(int nrLitriCombustibil);
    int getNrLitriCombustibil() const;

    void setConsum(float consum);
    float getConsum() const;

    void setKilometraj(int kilometraj);
    int getKilometraj() const;

    // Metoda pentru a reduce kilometrajul cu 1000 km
    void bisnitar();

    // Metoda pentru a simula parcurgerea unei curse
    void cursa(float distanta);
};

#endif // MASINA_H
