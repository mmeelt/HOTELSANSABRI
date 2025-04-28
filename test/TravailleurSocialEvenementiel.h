#ifndef TRAVAILLEURSOCIALEVENEMENTIEL_H
#define TRAVAILLEURSOCIALEVENEMENTIEL_H

#include "TravailleurSocial.h"
#include "RespEvenementiel.h"
#include "SansAbri.h"
#include "Formation.h"
#include "Atelier.h"
#include "Evenement.h"

class TravailleurSocialEvenementiel : public TravailleurSocial, public RespEvenementiel {
public:
    // Inscription d'un SansAbri à une formation
    void inscrireAUneFormation(SansAbri* s, Formation* f);

    // Inscription d'un SansAbri à un atelier
    void inscrireAUneAtelier(SansAbri* s, Atelier* a);

    // Gestion des événements
    void planifierEvenement(Evenement* evenement);
    void annulerEvenement(Evenement* evenement);
    void modifierEvenement(Evenement* evenement);
    void ajouterEvenement(Evenement* evenement);
    void supprimerEvenement(Evenement* evenement);
};

#endif // TRAVAILLEURSOCIALEVENEMENTIEL_H