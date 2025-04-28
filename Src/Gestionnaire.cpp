#include "../Headers/Gestionnaire.h"
#include <iostream>
#include <algorithm>
#include "vector"

using namespace std;


// Ajouter un bloc
void Gestionnaire::ajouterBloc(const Bloc &bloc) {
    blocs.push_back(bloc);
}

// Lire tous les blocs
vector<Bloc> Gestionnaire::lireBlocs() const {
    return blocs;
}

// Mettre à jour un bloc
void Gestionnaire::mettreAJourBloc(int blocId, const Bloc &bloc) {
    for (auto &b : blocs) {
        if (b.getId() == blocId) {
            b = bloc;
            return;
        }
    }
    cout << "Bloc avec ID " << blocId << " non trouvé." << endl;
}

// Supprimer un bloc
void Gestionnaire::supprimerBlocParId(int blocId) {
    blocs.erase(remove_if(blocs.begin(), blocs.end(),
                          [blocId](const Bloc &b) { return b.getId() == blocId; }),
                blocs.end());
}

// Gérer un bloc
void Gestionnaire::gererBloc(Bloc bloc) {
    // Implémentation spécifique pour gérer un bloc
}

// Supprimer un bloc par son ID
void Gestionnaire::supprimerBloc(int blocId) {
    supprimerBlocParId(blocId);
}

// Trouver un bloc par son ID
Bloc Gestionnaire::trouverBlocParId(int blocId) {
    for (const auto &b : blocs) {
        if (b.getId() == blocId) {
            return b;
        }
    }
    throw runtime_error("Bloc avec ID " + to_string(blocId) + " non trouvé.");
}

// Ajouter une chambre dans un bloc
void Gestionnaire::ajouterChambreDansBloc(int blocId, Chambre chambre) {
    for (auto &b : blocs) {
        if (b.getId() == blocId) {
            b.ajouterChambre(chambre);
            return;
        }
    }
    cout << "Bloc avec ID " << blocId << " non trouvé." << endl;
}

// Supprimer une chambre d'un bloc
void Gestionnaire::supprimerChambreDansBloc(int blocId, int chambreNumero) {
    for (auto &b : blocs) {
        if (b.getId() == blocId) {
            b.supprimerChambre(chambreNumero);
            return;
        }
    }
    cout << "Bloc avec ID " << blocId << " non trouvé." << endl;
}

// Afficher les chambres d'un bloc
void Gestionnaire::afficherChambresBloc(int blocId) {
    for (const auto &b : blocs) {
        if (b.getId() == blocId) {
            b.afficherChambres();
            return;
        }
    }
    cout << "Bloc avec ID " << blocId << " non trouvé." << endl;
}

// Afficher les statistiques de l'hôtel
void Gestionnaire::afficherStatistiquesHotel() {
    // Implémentation spécifique pour afficher les statistiques
}