#include "Masina.h"

// Constructor
Masina::Masina(const std::string& firma, int nrLitriCombustibil, float consum, int kilometraj)
    : firma(firma), nrLitriCombustibil(nrLitriCombustibil), consum(consum), kilometraj(kilometraj) {}

// Getteri și setteri
void Masina::setFirma(const std::string& firma) {
     this->firma = firma; 
     }
std::string Masina::getFirma() const { 
    return firma; 
    }

void Masina::setNrLitriCombustibil(int nrLitriCombustibil) { 
    this->nrLitriCombustibil = nrLitriCombustibil; 
    }
int Masina::getNrLitriCombustibil() const { 
    return nrLitriCombustibil; 
    }

void Masina::setConsum(float consum) { 
    this->consum = consum; 
    }
float Masina::getConsum() const { 
    return consum; 
}

void Masina::setKilometraj(int kilometraj) { 
    this->kilometraj = kilometraj; }
int Masina::getKilometraj() const { return kilometraj; 
}

// Metoda pentru a reduce kilometrajul cu 1000 km
void Masina::bisnitar() { 
    kilometraj -= 1000; 
}

// Metoda pentru a simula parcurgerea unei curse
void Masina::cursa(float distanta) {
    kilometraj += static_cast<int>(distanta); // Incrementăm kilometrajul cu distanța parcursă
    nrLitriCombustibil -= static_cast<int>(distanta * consum); // Scădem combustibilul consumat
}
