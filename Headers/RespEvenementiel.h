#ifndef RESPEVENEMENTIEL_H
#define RESPEVENEMENTIEL_H

#include "Utilisateur.h"
#include "SansAbri.h"
#include "Formation.h"
#include "Atelier.h"
#include "Evenement.h"

class RespEvenementiel : public Utilisateur {
public:
    // Method to register a homeless person for a training
    void inscrireAUneFormation(SansAbri* s, Formation* f);

    // Method to register a homeless person for a workshop
    void inscrireAUneAtelier(SansAbri* s, Atelier* a);

    // Method to plan an event
    void planifierEvenement(Evenement* evenement);

    // Method to cancel an event
    void annulerEvenement(Evenement* evenement);

    // Method to modify an event
    void modifierEvenement(Evenement* evenement);

    // Method to add an event
    void ajouterEvenement(Evenement* evenement);

    // Method to delete an event
    void supprimerEvenement(Evenement* evenement);
};

#endif // RESPEVENEMENTIEL_H