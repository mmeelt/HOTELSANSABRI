#ifndef TRAVAILLEURSOCIAL_H
#define TRAVAILLEURSOCIAL_H

#include "Utilisateur.h"
#include "SansAbri.h"
#include "Formation.h"
#include "Atelier.h"
#include "Evenement.h"
#include <vector>
#include <iostream>

using namespace std;

class TravailleurSocial : virtual public Utilisateur {
private:
    vector<SansAbri*> sansAbris;
    vector<Evenement*> evenements;

public:
    // Constructors
    TravailleurSocial();
    TravailleurSocial(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp);

    // Copy constructor
    TravailleurSocial(const TravailleurSocial& other);

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
    void ajouterEvenement(Evenement* evenement);
    void supprimerEvenement(Evenement* evenement);

    // Operator Overloads
    friend ostream& operator<<(ostream& os, const TravailleurSocial& t);
    friend istream& operator>>(istream& is, TravailleurSocial& t);
};

#endif // TRAVAILLEURSOCIAL_H
