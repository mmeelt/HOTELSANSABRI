#include "RSEvenement.h"
#include <cstring>
#include <iostream>
using namespace std;

RSEvenement::RSEvenement()
    : Utilisateur() {
    strcpy(typeEvenement, "Inconnu");
}

RSEvenement::RSEvenement(const char* n, const char* p, int a, const char* r,
                         const char* id, const char* mdp, const char* typeEvt)
    : Utilisateur(n, p, a, r, id, mdp) {
    strcpy(typeEvenement, typeEvt);
}

void RSEvenement::afficherInfos() {
    cout << "--- Responsable Événementiel ---" << endl;
    Utilisateur::afficherInfos();
    cout << "Type d'événement : " << typeEvenement << endl;
}

void RSEvenement::definirTypeEvenement(const char* nouveauType) {
    strcpy(typeEvenement, nouveauType);
}

const char* RSEvenement::getTypeEvenement() {
    return typeEvenement;
}
