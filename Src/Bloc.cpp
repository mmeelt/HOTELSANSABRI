#include "../Headers/Bloc.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
Bloc::Bloc(int id, const string& nomBloc)
    : idBloc(id), nom(nomBloc), pourcentageSaturation(0.0f), capaciteTotale(0) {}

// Destructor
Bloc::~Bloc() {}

// Add a room
void Bloc::ajouterChambre(unique_ptr<Chambre> ch) {
    chambres.push_back(ch);
    capaciteTotale += ch->getCapacite();
    pourcentageSaturation = getTauxOccupation();
}

// Remove a room
Bloc Bloc::supprimerChambre(unique_ptr<Chambre> ch) {
    auto it = find(chambres.begin(), chambres.end(), ch);
    if (it != chambres.end()) {
        capaciteTotale -= (*it)->getCapacite();
        it->reset();
        chambres.erase(it);
        pourcentageSaturation = getTauxOccupation();
    }
}

// Update block information
void Bloc::updateInfo(int nouveauId, const string& nouveauNom) {
    idBloc = nouveauId;
    nom = nouveauNom;
}

// Get total capacity
int Bloc::getCapaciteTotale() const {
    return capaciteTotale;
}

// Get occupancy rate
float Bloc::getTauxOccupation() const {
    if (capaciteTotale == 0) return 0.0f;

    int totalOccupants = 0;
    for (const unique_ptr<Chambre>& chambre : chambres) {
        totalOccupants += chambre->getOccupants();
    }
    return (static_cast<float>(totalOccupants) / capaciteTotale) * 100.0f;
}

// Display block information
void Bloc::afficherInfos() const {
    cout << "Bloc ID: " << idBloc << endl;
    cout << "Nom: " << nom << endl;
    cout << "Capacite Totale: " << capaciteTotale << endl;
    cout << "Taux d'Occupation: " << pourcentageSaturation << "%" << endl;
    cout << "Chambres: " << endl;
    for (const unique_ptr<Chambre>& chambre : chambres) {
        chambre->afficherInfos();
    }
}