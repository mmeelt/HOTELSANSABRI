// === Fichier: DossierMedical.cpp ===
#include "DossierMedical.h"
#include <stdio.h>
#include <string.h>

DossierMedical::DossierMedical() {
    idDossier = 0;
    diagnostics[0] = '\0';
    traitements[0] = '\0';
    dateDerniereMaj[0] = '\0';
}

DossierMedical::DossierMedical(int id, const char* diag, const char* trait, const char* dateMaj) {
    idDossier = id;
    strcpy(diagnostics, diag);
    strcpy(traitements, trait);
    strcpy(dateDerniereMaj, dateMaj);
}

void DossierMedical::afficherDossier() {
    printf("--- Dossier Médical ---\n");
    printf("ID Dossier: %d\n", idDossier);
    printf("Diagnostics: %s\n", diagnostics);
    printf("Traitements: %s\n", traitements);
    printf("Derniere mise à jour: %s\n", dateDerniereMaj);
}

void DossierMedical::mettreAJour(const char* nouveauDiag, const char* nouveauTrait, const char* nouvelleDate) {
    strcpy(diagnostics, nouveauDiag);
    strcpy(traitements, nouveauTrait);
    strcpy(dateDerniereMaj, nouvelleDate);
}

int DossierMedical::getIdDossier() {
    return idDossier;
}
