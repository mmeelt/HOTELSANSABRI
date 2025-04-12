#include "TravailleurSocial.h"
#include <cstring>
#include <iostream>
using namespace std;

TravailleurSocial::TravailleurSocial()
    : Utilisateur() {
    strcpy(secteur, "Inconnu");
}

TravailleurSocial::TravailleurSocial(const char* n, const char* p, int a, const char* r,
                                     const char* id, const char* mdp, const char* s)
    : Utilisateur(n, p, a, r, id, mdp) {
    strcpy(secteur, s);
}

void TravailleurSocial::afficherInfos() {
    cout << "--- Travailleur Social ---" << endl;
    Utilisateur::afficherInfos();
    cout << "Secteur : " << secteur << endl;
}

void TravailleurSocial::definirSecteur(const char* nouveauSecteur) {
    strcpy(secteur, nouveauSecteur);
}

const char* TravailleurSocial::getSecteur() {
    return secteur;
}
