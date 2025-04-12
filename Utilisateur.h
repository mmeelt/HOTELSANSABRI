// === Fichier: Utilisateur.h ===
#ifndef UTILISATEUR_H
#define UTILISATEUR_H

#include "Personne.h"

class Utilisateur : public Personne {
private:
    char role[30];
    char identifiant[20];
    char motDePasse[20];

public:
    Utilisateur();
    Utilisateur(const char* n, const char* p, int a, const char* r, const char* id, const char* mdp);
    void saisirInfos() override;

    void afficherInfos() override;
    void modifierIdentifiants(const char* nouveauId, const char* nouveauMdp);
    const char* getIdentifiant();
    const char* getRole();
};

#endif
