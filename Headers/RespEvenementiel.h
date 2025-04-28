#ifndef RESPEVENEMENTIEL_H
#define RESPEVENEMENTIEL_H

#include "Utilisateur.h"
#include "SansAbri.h"
#include "Formation.h"
#include "Atelier.h"
#include "Evenement.h"
#include <vector>
#include <iostream>

using namespace std;

class RespEvenementiel : virtual public Utilisateur {
private:
    vector<Evenement*> evenements; // dynamic

public:
    // Constructors
    RespEvenementiel();
    RespEvenementiel(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp);

    // Copy Constructor
    RespEvenementiel(const RespEvenementiel& other);

    // Destructor
    virtual ~RespEvenementiel();

    // CRUD methods
    void modifierRespEvenementiel(vector<RespEvenementiel*>& respList, int idRecherche);
    void supprimerRespEvenementiel(vector<RespEvenementiel*>& respList, int idRecherche);

    // Specific Methods
    void inscrireAUneFormation(SansAbri s, Formation* f);
    void inscrireAUneAtelier(SansAbri s, Atelier* a);

    void planifierEvenement(Evenement* evenement);
    void annulerEvenement(Evenement* evenement);
    void modifierEvenement(Evenement* evenement);
    void ajouterEvenement(Evenement* evenement);
    void supprimerEvenement(Evenement* evenement);

    // Getters and Setters
    vector<Evenement*> getEvenements() const;
    void setEvenements(const vector<Evenement*>& evenements);

    // Operator Overloading
    friend ostream& operator<<(ostream& os, const RespEvenementiel& resp);
    friend istream& operator>>(istream& is, RespEvenementiel& resp);
};

#endif // RESPEVENEMENTIEL_H
