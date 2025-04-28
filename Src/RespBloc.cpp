#include "../Headers/RespBloc.h"
#include <iostream>
#include <algorithm>

using namespace std;



// Display information about the RespBloc
void RespBloc::afficherInfos() {
    cout << "Responsable de Bloc:" << endl;
    cout << "Capacité Globale: " << capaciteGlobale << endl;
    cout << "Taux d'Occupation Global: " << getTauxOccupation() * 100 << "%" << endl;
    cout << "Blocs gérés: " << endl;
    for (Bloc* bloc : blocs) {
        if (bloc) {
            bloc->afficherInfos(); // Assuming Bloc has an afficherInfos() method
        }
    }
}

// Add a Bloc to the list
void RespBloc::ajouterBloc(Bloc* b) {
    if (b) {
        blocs.push_back(b);
        capaciteGlobale += b->getCapaciteTotale(); // Assuming Bloc has a getCapacite() method
        saturationGlobale += b->getTauxOccupation() * b->getCapaciteTotale(); // Assuming Bloc has a getTauxOccupation() method
    }
}

// Remove a Bloc from the list
void RespBloc::supprimerBloc(Bloc* b) {
    auto it = find(blocs.begin(), blocs.end(), b);
    if (it != blocs.end()) {
        capaciteGlobale -= (*it)->getCapaciteTotale();
        saturationGlobale -= (*it)->getTauxOccupation() * (*it)->getCapaciteTotale();
        blocs.erase(it);
        delete b; // Free memory if the Bloc is dynamically allocated
    }
}

// Find a Bloc by its ID
Bloc* RespBloc::trouverBlocParId(int id) {
    for (Bloc* bloc : blocs) {
        if (bloc && bloc->getId() == id) { // Assuming Bloc has a getId() method
            return bloc;
        }
    }
    return nullptr;
}

// Get the global occupation rate
float RespBloc::getTauxOccupation() const {
    if (capaciteGlobale == 0) {
        return 0.0f;
    }
    return saturationGlobale / capaciteGlobale;
}

// Get the global capacity
int RespBloc::getCapaciteGlobale() const {
    return capaciteGlobale;
}