#include "Receptionniste.h"
#include <stdio.h>

Receptionniste::Receptionniste() : Utilisateur() {
    numeroPoste = 0;
}

Receptionniste::Receptionniste(const char* n, const char* p, int a, const char* r, const char* id, const char* mdp, int numPoste)
    : Utilisateur(n, p, a, r, id, mdp), numeroPoste(numPoste) {}

void Receptionniste::afficherInfos() {
    printf("--- R�ceptionniste ---\n");
    Utilisateur::afficherInfos();
    printf("Num�ro de poste: %d\n", numeroPoste);
}

void Receptionniste::definirPoste(int nouveauPoste) {
    numeroPoste = nouveauPoste;
}

int Receptionniste::getNumeroPoste() {
    return numeroPoste;
}
