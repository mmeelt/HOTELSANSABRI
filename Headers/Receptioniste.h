#ifndef RECEPTIONNISTE_H
#define RECEPTIONNISTE_H

#include "Utilisateur.h"
#include <vector>
#include <memory> // For std::unique_ptr
#include <iostream>
#include "Bloc.h"

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
    Receptionniste(std::string nom, std::string prenom, int age, int id, std::string& username, std::string& mdp): Utilisateur(nom, prenom, age, id, username, mdp) {};

    // Copy Constructor
    Receptionniste(const Receptionniste& other);

    // Destructor
    virtual ~Receptionniste();

    // CRUD Methods
    void modifierReceptionniste(vector<unique_ptr<Receptionniste>>& receptionnistes, int idRecherche);
    void supprimerReceptionniste(vector<unique_ptr<Receptionniste>>& receptionnistes, int idRecherche);

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
