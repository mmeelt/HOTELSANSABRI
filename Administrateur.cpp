#include "Administrateur.h"
#include <stdio.h>

Administrateur::Administrateur() : Utilisateur() {
    accesTotal = false;
}

Administrateur::Administrateur(const char* n, const char* p, int a, const char* r, const char* id, const char* mdp, bool acces)
    : Utilisateur(n, p, a, r, id, mdp), accesTotal(acces) {}

void Administrateur::afficherInfos() {
    printf("--- Administrateur ---\n");
    Utilisateur::afficherInfos();
    printf("Accès total: %s\n", accesTotal ? "Oui" : "Non");
}

void Administrateur::definirAcces(bool acces) {
    accesTotal = acces;
}

bool Administrateur::getAccesTotal() {
    return accesTotal;
}
