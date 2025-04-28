#ifndef BLOC_H
#define BLOC_H

#include <string>
#include <vector>
#include "Chambre.h"

class Bloc {
private:
    int idBloc;
    string nom;
    vector<Chambre*> chambres;
    float pourcentageSaturation;
    int capaciteTotale;

public:
    // Constructor
    Bloc(int id, const string& nomBloc);
    ~Bloc();
    // CRUD methods
    void ajouterChambre(Chambre* ch);
    void supprimerChambre(Chambre* ch);
    void updateInfo(int nouveauId, string nouveauNom);    // Getters
    int getCapaciteTotale() const;
    float getTauxOccupation() const;
    int getId() const;
    // Display information
    void afficherInfos() const;
};

#endif // BLOC_H