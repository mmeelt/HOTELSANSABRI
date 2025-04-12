#include "Utilisateur.h"
#include <stdio.h>
#include <string.h>

Utilisateur::Utilisateur() : Personne() {
    role[0] = '\0';
    identifiant[0] = '\0';
    motDePasse[0] = '\0';
}

Utilisateur::Utilisateur(const char* n, const char* p, int a, const char* r, const char* id, const char* mdp)
    : Personne(n, p, a) {
    strcpy(role, r);
    strcpy(identifiant, id);
    strcpy(motDePasse, mdp);
}
void Utilisateur::saisirInfos() {
    Personne::saisirInfos();
    printf("Entrez le rôle: ");
    scanf("%s", role);
    printf("Entrez l'identifiant: ");
    scanf("%s", identifiant);
    printf("Entrez le mot de passe: ");
    scanf("%s", motDePasse);
}


void Utilisateur::afficherInfos() {
    printf("--- Utilisateur ---\n");
    Personne::afficherInfos();
    printf("Role: %s\n", role);
    printf("Identifiant: %s\n", identifiant);
}

void Utilisateur::modifierIdentifiants(const char* nouveauId, const char* nouveauMdp) {
    strcpy(identifiant, nouveauId);
    strcpy(motDePasse, nouveauMdp);
}

const char* Utilisateur::getIdentifiant() {
    return identifiant;
}

const char* Utilisateur::getRole() {
    return role;
}
