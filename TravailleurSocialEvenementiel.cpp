#include "TravailleurSocialEvenementiel.h"
#include <iostream>
using namespace std;

TravailleurSocialEvenementiel::TravailleurSocialEvenementiel()
    : Utilisateur(), TravailleurSocial(), RSEvenement() {}

TravailleurSocialEvenementiel::TravailleurSocialEvenementiel(
    const char* n, const char* p, int a, const char* r,
    const char* id, const char* mdp,
    const char* secteur, const char* typeEvt)
    : Utilisateur(n, p, a, r, id, mdp),
      TravailleurSocial(n, p, a, r, id, mdp, secteur),
      RSEvenement(n, p, a, r, id, mdp, typeEvt) {}

void TravailleurSocialEvenementiel::afficherInfos() {
    cout << "--- Travailleur Social Événementiel ---" << endl;
    Utilisateur::afficherInfos();
    cout << "Secteur : " << getSecteur() << endl;
    cout << "Type d'événement : " << getTypeEvenement() << endl;
}
