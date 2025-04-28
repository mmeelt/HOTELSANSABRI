#ifndef RECEPTIONNISTE_H
#define RECEPTIONNISTE_H

#include "Utilisateur.h"
#include <vector>
#include <iostream>

using namespace std;

// Forward declarations
class SansAbri;
class Chambre;
class Reservation;

class Receptionniste : public Utilisateur {
private:
    string poste; // Specific attribute for Receptionniste

public:
    // Constructors
    Receptionniste();
    Receptionniste(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp, const string& poste);

    // Copy Constructor
    Receptionniste(const Receptionniste& other);

    // Destructor
    virtual ~Receptionniste();

    // CRUD Methods
    void modifierReceptionniste(vector<Receptionniste*>& receptionnistes, int idRecherche);
    void supprimerReceptionniste(vector<Receptionniste*>& receptionnistes, int idRecherche);

    // Specific Methods
    void ajouterReservation(SansAbri* sansAbri, Chambre* chambre);
    void libererChambre(Chambre* chambre);
    void verifierChambresDisponibles();
    void supprimerReservation(Reservation* reservation);

    // Getter and Setter
    string getPoste() const;
    void setPoste(const string& poste);

    // Overloaded Operators
    friend ostream& operator<<(ostream& os, const Receptionniste& r);
    friend istream& operator>>(istream& is, Receptionniste& r);

    // Override afficherProfil
    void afficherProfil() const override;
};

#endif // RECEPTIONNISTE_H
