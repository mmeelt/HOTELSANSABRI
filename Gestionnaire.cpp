#include "Gestionnaire.h"
#include <iostream>
using namespace std;

Gestionnaire::Gestionnaire()
    : Utilisateur(), Administrateur(), RespBloc() {}

Gestionnaire::Gestionnaire(const char* nom, const char* prenom, int age, const char* role,
                           const char* id, const char* mdp, bool acces, int blocId)
    : Utilisateur(nom, prenom, age, role, id, mdp),
      Administrateur(nom, prenom, age, role, id, mdp, acces),
      RespBloc(nom, age, blocId) {}

void Gestionnaire::afficherInfos() {
    cout << "--- Gestionnaire ---" << endl;
    Utilisateur::afficherInfos();
    cout << "Accès total : " << (getAccesTotal() ? "Oui" : "Non") << endl;
    cout << "Bloc ID : " << getBlocId() << endl;  // Ajoute getBlocId() dans RespBloc
}
