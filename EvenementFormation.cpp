#include "EvenementFormation.h"

#include <stdio.h>
#include <string.h>

EvenementFormation::EvenementFormation()
    : Evenement("", "", "", nullptr) {
    strcpy(formateur, "Inconnu");
}

EvenementFormation::EvenementFormation(const std::string& t, const std::string& d, const std::string& a, TravailleurSocialEvenementiel* resp, const char* f)
    : Evenement(t, d, a, resp) {
    strncpy(formateur, f, sizeof(formateur) - 1);
    formateur[sizeof(formateur) - 1] = '\0';
}

void EvenementFormation::afficherInfo() {
    printf("--- Formation ---\n");
    Evenement::afficherInfo();
    printf("Formateur: %s\n", formateur);
}
