#include "../Headers/Chambre.h"
#include <iostream>

Chambre::Chambre(int numero, bool estLibre, const std::string& etat)
    : numero(numero), estLibre(estLibre), etat(etat) {}

Chambre::~Chambre() {}

void Chambre::attribuer(SansAbri* sansAbri) {
    if (estLibre) {
        estLibre = false;
        etat = "Occupée";
        std::cout << "Chambre " << numero << " attribuée à " << sansAbri->getNom() << "." << std::endl;
    } else {
        std::cout << "Chambre " << numero << " est déjà occupée." << std::endl;
    }
}

void Chambre::liberer() {
    if (!estLibre) {
        estLibre = true;
        etat = "Libre";
        std::cout << "Chambre " << numero << " est maintenant libre." << std::endl;
    } else {
        std::cout << "Chambre " << numero << " est déjà libre." << std::endl;
    }
}

std::string Chambre::getEtat() {
    return etat;
}