#include "SansAbri.h"
#include <stdio.h>
#include <string.h>

SansAbri::SansAbri() : Personne() {
    id = 0;
    situationActuelle[0] = '\0';
    aBesoinSoins = false;
}

SansAbri::SansAbri(int identifiant, const char* n, const char* p, int a, const char* situation, bool soins)
    : Personne(n, p, a) {
    id = identifiant;
    strcpy(situationActuelle, situation);
    aBesoinSoins = soins;
}

void SansAbri::afficherInfos() {
    printf("--- Sans-Abri ---\n");
    printf("ID: %d\n", id);
    Personne::afficherInfos();
    printf("Situation actuelle: %s\n", situationActuelle);
    printf("Besoin de soins: %s\n", aBesoinSoins ? "Oui" : "Non");
}

void SansAbri::modifierSituation(const char* nouvelleSituation) {
    strcpy(situationActuelle, nouvelleSituation);
}

void SansAbri::definirBesoinSoins(bool besoin) {
    aBesoinSoins = besoin;
}

int SansAbri::getId() {
    return id;
}
