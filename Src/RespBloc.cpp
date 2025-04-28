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
    for (const auto& bloc : blocs) {
        if (bloc) {
            bloc->afficherInfos(); // Assuming Bloc has an afficherInfos() method
        }
    }
}

// Add a Bloc to the list
void RespBloc::ajouterBloc(std::unique_ptr<Bloc> b) {
    if (b) {
        capaciteGlobale += b->getCapaciteTotale(); // Assuming Bloc has a getCapacite() method
        saturationGlobale += b->getTauxOccupation() * b->getCapaciteTotale(); // Assuming Bloc has a getTauxOccupation() method
        blocs.push_back(std::move(b));
    }
}

// Remove a Bloc from the list
void RespBloc::supprimerBloc(int id) {
    auto it = find_if(blocs.begin(), blocs.end(), 
        [id](const auto& bloc) { return bloc && bloc->getId() == id; });
    if (it != blocs.end()) {
        capaciteGlobale -= (*it)->getCapaciteTotale();
        saturationGlobale -= (*it)->getTauxOccupation() * (*it)->getCapaciteTotale();
        blocs.erase(it);
    }
}

// Find a Bloc by its ID
Bloc* RespBloc::trouverBlocParId(int id) const {
    for (const auto& bloc : blocs) {
        if (bloc && bloc->getId() == id) { // Assuming Bloc has a getId() method
            return bloc.get();
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