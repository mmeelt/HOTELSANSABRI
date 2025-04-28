#ifndef RESPBLOC_H
#define RESPBLOC_H

#include "Utilisateur.h"
#include "Bloc.h"
#include <vector>

class RespBloc : virtual public Utilisateur {
protected:
    vector<Bloc*> blocs;
    float saturationGlobale;
    int capaciteGlobale;

public:
    // Constructor and Destructor
    RespBloc(string nom, string prenom, int age, int id, string& username, string& mdp, vector<Bloc*> blocs = {}) : 
        Utilisateur(nom, prenom, age, id, username, mdp), blocs(blocs) {};
    ~RespBloc();

    // Member functions
    void afficherInfos();
    void ajouterBloc(Bloc* b);
    void supprimerBloc(Bloc* b);
    Bloc* trouverBlocParId(int id);
    float getTauxOccupation() const;
    int getCapaciteGlobale() const;
    void updateSaturationGlobale();
    void updateCapaciteGlobale();
};

#endif // RESPBLOC_H