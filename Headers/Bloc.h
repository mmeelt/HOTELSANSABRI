#ifndef BLOC_H
#define BLOC_H

#include <string>
#include <vector>
#include <memory> // For std::unique_ptr
#include "Chambre.h"

class Bloc {
private:
    int idBloc;
    std::string nom;
    std::vector<std::unique_ptr<Chambre>> chambres; // Use unique_ptr for memory management
    float pourcentageSaturation;
    int capaciteTotale;

public:
    // Constructor
    Bloc(int id, const std::string& nomBloc);
    ~Bloc();
    // CRUD methods
    void ajouterChambre(std::unique_ptr<Chambre> ch); // Accept unique_ptr
    Bloc supprimerChambre(unique_ptr<Chambre> ch); // Use chambreNumero to identify the chambre to remove
    void updateInfo(int nouveauId, const std::string& nouveauNom);
    // Getters
    int getCapaciteTotale() const;
    float getTauxOccupation() const;
    int getId() const;
    // Display information
    void afficherInfos() const;
    Chambre* trouverChambreParNumero(int chambreNumero) const;
};

#endif // BLOC_H