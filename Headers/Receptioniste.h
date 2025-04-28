#ifndef RECEPTIONISTE_H
#define RECEPTIONISTE_H

#include <string>
#include "Utilisateur.h" // Assuming Utilisateur is defined in this header file
#include "SansAbri.h"    // Assuming SansAbri is defined in this header file
#include "Chambre.h"     // Assuming Chambre is defined in this header file
#include "Reservation.h" // Assuming Reservation is defined in this header file

class Receptioniste : public Utilisateur {

public:
    // Constructor
    Receptioniste(const std::string& nom, const std::string& prenom, int id);

    // Getters
    std::string getNom() const;
    std::string getPrenom() const;
    int getId() const;

    // Setters
    void setNom(const std::string& nom);
    void setPrenom(const std::string& prenom);
    void setId(int id);

    // Other member functions
    void afficherDetails() const;

    // New member functions
    void ajouterReservation(SansAbri* sansAbri, Chambre* chambre);
    void libererChambre(Chambre* chambre);
    void verifierChambresDisponibles();
    void supprimerReservation(Reservation* reservation);
};

#endif // RECEPTIONISTE_H