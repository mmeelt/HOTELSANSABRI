#include "EvenementAtelier.h"
#include "Evenement.cpp"
#include <cstring>
#include <cstdio>

EvenementAtelier::EvenementAtelier()
    : Evenement("", "", "", nullptr) {  // Call constructor of Evenement with default values
    strcpy(activitePrincipale, "Non spécifiée");
}

EvenementAtelier::EvenementAtelier(const std::string& t, const std::string& d, const std::string& a, TravailleurSocialEvenementiel* resp)
    : Evenement(t, d, a, resp) {  // Call Evenement constructor with the provided values
    strncpy(activitePrincipale, a.c_str(), sizeof(activitePrincipale) - 1);
    activitePrincipale[sizeof(activitePrincipale) - 1] = '\0';
}

void EvenementAtelier::afficherInfo() {
    printf("--- Atelier ---\n");
    Evenement::afficherInfo();  // Corrected method name to match the Evenement class
    printf("Activité principale: %s\n", activitePrincipale);
}
