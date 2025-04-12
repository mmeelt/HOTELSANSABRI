#include "Personne.h"
#include <stdio.h>
#include <string.h>

Personne::Personne() {
    nom[0] = '\0';
    prenom[0] = '\0';
    age = 0;
}

Personne::Personne(const char* n, const char* p, int a) {
    strcpy(nom, n);
    strcpy(prenom, p);
    age = a;
}
void Personne::saisirInfos() {
    printf("Entrez le nom: ");
    scanf("%s", nom);
    printf("Entrez le pr�nom: ");
    scanf("%s", prenom);
    printf("Entrez l'�ge: ");
    scanf("%d", &age);
}


void Personne::afficherInfos() {
    printf("Nom: %s\n", nom);
    printf("Prenom: %s\n", prenom);
    printf("Age: %d\n", age);
}

void Personne::modifierInfos(const char* nouveauNom, const char* nouveauPrenom, int nouvelAge) {
    strcpy(nom, nouveauNom);
    strcpy(prenom, nouveauPrenom);
    age = nouvelAge;
}
