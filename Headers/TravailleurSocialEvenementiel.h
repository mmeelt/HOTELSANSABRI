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
#include <memory> // For std::unique_ptr
using namespace std;

class TravailleurSocialEvenementiel : public TravailleurSocial, public RespEvenementiel {
private:
    std::unique_ptr<Formation> formation;
    std::unique_ptr<Atelier> atelier;

public:
    // Constructors
    TravailleurSocialEvenementiel() = default;

    TravailleurSocialEvenementiel(string nom, string prenom, int age, int id, string& username, string& mdp);

    // Move Constructor
    TravailleurSocialEvenementiel(TravailleurSocialEvenementiel&& other) noexcept = default;

    // Destructor
    virtual ~TravailleurSocialEvenementiel() = default;

    // Deleted copy constructor and assignment
    TravailleurSocialEvenementiel(const TravailleurSocialEvenementiel&) = delete;
    TravailleurSocialEvenementiel& operator=(const TravailleurSocialEvenementiel&) = delete;

    // CRUD methods
    void modifierTravailleurSocialEvenementiel(std::vector<TravailleurSocialEvenementiel>& list, int idRecherche);
    void supprimerTravailleurSocialEvenementiel(std::vector<TravailleurSocialEvenementiel>& list, int idRecherche);

    // Specific Methods
    void inscrireAUneFormation(SansAbri& s, Formation& f);
    void inscrireAUneAtelier(SansAbri& s, Atelier& a);

    void planifierEvenement(Evenement& evenement, const string& date, const string& lieu, const string& description, const vector<unique_ptr<TravailleurSocialEvenementiel>>& responsable);
    void annulerEvenement(Evenement& evenement);
    void modifierEvenement(Evenement& evenement);
    void ajouterEvenement(Evenement& evenement);
    void supprimerEvenement(Evenement& evenement);

    // Operator Overloading
    friend std::ostream& operator<<(std::ostream& os, const TravailleurSocialEvenementiel& tse);
    friend std::istream& operator>>(std::istream& is, TravailleurSocialEvenementiel& tse);

    // Operator ==
    bool operator==(const TravailleurSocialEvenementiel& other) const;
};

#endif // TRAVAILLEURSOCIALEVENEMENTIEL_H
