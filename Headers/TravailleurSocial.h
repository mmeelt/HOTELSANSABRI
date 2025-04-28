#ifndef TRAVAILLEURSOCIAL_H
#define TRAVAILLEURSOCIAL_H

#include "Utilisateur.h"
#include "SansAbri.h"
#include "Formation.h"
#include "Atelier.h"
#include "Evenement.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class TravailleurSocial : virtual public Utilisateur {
private:
    vector<unique_ptr<SansAbri>> sansAbris;
    vector<unique_ptr<Evenement>> evenements;

public:
    // Constructors
    TravailleurSocial();
    TravailleurSocial(string nom, string prenom, int age, int id, string& username, string& mdp);

    // Copy constructor
    TravailleurSocial(const TravailleurSocial& other) = delete; // Unique pointers cannot be copied

    // Move constructor
    TravailleurSocial(TravailleurSocial&& other) noexcept;

    // Destructor
    virtual ~TravailleurSocial();

    // Methods
    void evaluerBesoins(SansAbri* sansAbri);
    void remplirFormulaire(SansAbri* sansAbri, const string& informations);
    void modifierDossier(SansAbri* sansAbri, const string& nouvellesInfos);
    void supprimerSansAbri(int idSansAbri);
    void inscrireAUneFormation(SansAbri* sansAbri, Formation* formation);
    void inscrireAUneAtelier(SansAbri* sansAbri, Atelier* atelier);
    void planifierEvenement(Evenement* evenement);
    void annulerEvenement(Evenement* evenement);
    void modifierEvenement(Evenement* evenement);
    void ajouterEvenement(unique_ptr<Evenement> evenement);
    void supprimerEvenement(Evenement* evenement);

    
    // ... other declarations ...
    friend ostream& operator<<(ostream& os, const Utilisateur& utilisateur);
    friend istream& operator>>(istream& is, Utilisateur& utilisateur);
    // Operator Overloads
    friend ostream& operator<<(ostream& os, const TravailleurSocial& t);
    friend istream& operator>>(istream& is, TravailleurSocial& t);
};

#endif // TRAVAILLEURSOCIAL_H
