#ifndef RESPBLOC_H
#define RESPBLOC_H

#include "Utilisateur.h"
#include "Bloc.h"
#include <vector>
#include <memory> // For std::unique_ptr

class RespBloc : virtual public Utilisateur {
protected:
    std::vector<std::unique_ptr<Bloc>> blocs; // Use unique_ptr for ownership
    float saturationGlobale;
    int capaciteGlobale;

public:
    // Constructor and Destructor
    RespBloc(std::string nom, std::string prenom, int age, int id, std::string& username, std::string& mdp, std::vector<std::unique_ptr<Bloc>> blocs = {}) : 
        Utilisateur(nom, prenom, age, id, username, mdp), blocs(std::move(blocs)) {};
    ~RespBloc() = default; // Default destructor is sufficient with unique_ptr

    // Member functions
    void afficherInfos();
    void ajouterBloc(std::unique_ptr<Bloc> b); // Accept unique_ptr for adding a Bloc
    void supprimerBloc(int id); // Use id to identify and remove a Bloc
    Bloc* trouverBlocParId(int id) const; // Return raw pointer for non-owning access
    float getTauxOccupation() const;
    int getCapaciteGlobale() const;
    void updateSaturationGlobale();
    void updateCapaciteGlobale();
};

#endif // RESPBLOC_H