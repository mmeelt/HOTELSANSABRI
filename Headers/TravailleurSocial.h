#ifndef TRAVAILLEURSOCIAL_H
#define TRAVAILLEURSOCIAL_H

#include "Utilisateur.h"
#include "SansAbri.h"
#include "Formation.h"
#include "Atelier.h"
#include "Evenement.h"
#include <string>

class TravailleurSocial : public Utilisateur {
public:
    // Évaluer les besoins d'un sans-abri
    void evaluerBesoins(SansAbri* sansAbri);

    // Remplir un formulaire pour un sans-abri
    void remplirFormulaire(SansAbri* sansAbri, const std::string& information);

    // Modifier le dossier d'un sans-abri
    void modifierDossier(SansAbri* s, const std::string& nouvellesInfos);

    // Supprimer un sans-abri par son ID
    void supprimerSansAbri(int idSansAbri);

    // Inscrire un sans-abri à une formation
    void inscrireAUneFormation(SansAbri* s, Formation* f);

    // Inscrire un sans-abri à un atelier
    void inscrireAUneAtelier(SansAbri* s, Atelier* a);

    // Planifier un événement
    void planifierEvenement(Evenement* evenement);

    // Annuler un événement
    void annulerEvenement(Evenement* evenement);

    // Modifier un événement
    void modifierEvenement(Evenement* evenement);

    // Ajouter un événement
    void ajouterEvenement(Evenement* evenement);

    // Supprimer un événement
    void supprimerEvenement(Evenement* evenement);
};

#endif // TRAVAILLEURSOCIAL_H