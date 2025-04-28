#ifndef TRAVAILLEURSOCIALEVENEMENTIEL_H
#define TRAVAILLEURSOCIALEVENEMENTIEL_H

#include "TravailleurSocial.h"
#include "RespEvenementiel.h"
#include "SansAbri.h"
#include "Formation.h"
#include "Atelier.h"
#include "Evenement.h"
#include <vector>
#include <iostream>

using namespace std;

class TravailleurSocialEvenementiel : public TravailleurSocial, public RespEvenementiel {
public:
    // Constructors
    TravailleurSocialEvenementiel();
    TravailleurSocialEvenementiel(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp);

    // Copy Constructor
    TravailleurSocialEvenementiel(const TravailleurSocialEvenementiel& other);

    // Destructor
    virtual ~TravailleurSocialEvenementiel();

    // CRUD methods
    void modifierTravailleurSocialEvenementiel(vector<TravailleurSocialEvenementiel*>& list, int idRecherche);
    void supprimerTravailleurSocialEvenementiel(vector<TravailleurSocialEvenementiel*>& list, int idRecherche);

    // Specific Methods
    void inscrireAUneFormation(SansAbri s, Formation* f);
    void inscrireAUneAtelier(SansAbri s, Atelier* a);

    void planifierEvenement(Evenement* evenement);
    void annulerEvenement(Evenement* evenement);
    void modifierEvenement(Evenement* evenement);
    void ajouterEvenement(Evenement* evenement);
    void supprimerEvenement(Evenement* evenement);

    // Operator Overloading
    friend ostream& operator<<(ostream& os, const TravailleurSocialEvenementiel& tse);
    friend istream& operator>>(istream& is, TravailleurSocialEvenementiel& tse);
};

#endif // TRAVAILLEURSOCIALEVENEMENTIEL_H
