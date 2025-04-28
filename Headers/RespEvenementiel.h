#ifndef RESPEVENEMENTIEL_H
#define RESPEVENEMENTIEL_H

#include "Utilisateur.h"
#include "SansAbri.h"
#include "Formation.h"
#include "Atelier.h"
#include "Evenement.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class RespEvenementiel : virtual public Utilisateur {
private:
    vector<unique_ptr<Evenement>> evenements; // Use unique_ptr for dynamic memory management

public:
    // Constructors
    RespEvenementiel();
    RespEvenementiel(string nom, string prenom, int age, int id, string& username, string& mdp, vector<unique_ptr<Evenement>> evenements = {})
        : Utilisateur(nom, prenom, age, id, username, mdp), evenements(std::move(evenements)) {};

    // Copy Constructor
    RespEvenementiel(const RespEvenementiel& other) = delete; // Deleted because unique_ptr cannot be copied

    // Move Constructor
    RespEvenementiel(RespEvenementiel&& other) noexcept = default;

    // Destructor
    virtual ~RespEvenementiel() = default;

    // CRUD methods
    void modifierRespEvenementiel(vector<RespEvenementiel*>& respList, int idRecherche);
    void supprimerRespEvenementiel(vector<RespEvenementiel*>& respList, int idRecherche);

    // Specific Methods
    void inscrireAUneFormation(SansAbri s, Formation* f);
    void inscrireAUneAtelier(SansAbri s, Atelier* a);

    void planifierEvenement(unique_ptr<Evenement> evenement);
    void annulerEvenement(Evenement* evenement);
    void modifierEvenement(Evenement* evenement);
    void ajouterEvenement(unique_ptr<Evenement> evenement);
    void supprimerEvenement(Evenement* evenement);

    // Getters and Setters
    vector<Evenement*> getEvenements() const; // Return raw pointers for read-only access
    void setEvenements(vector<unique_ptr<Evenement>> evenements);

    // Operator Overloading
    friend ostream& operator<<(ostream& os, const RespEvenementiel& resp);
    friend istream& operator>>(istream& is, RespEvenementiel& resp);
};

#endif // RESPEVENEMENTIEL_H
