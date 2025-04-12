#include "Reservation.h"
#include <stdio.h>
#include <string.h>

Reservation::Reservation() : chambreNumero(0), beneficiaireId(0) {
    strcpy(date, "01/01/2000");
}

Reservation::Reservation(int chambre, int beneficiaire, const char* d)
    : chambreNumero(chambre), beneficiaireId(beneficiaire) {
    strncpy(date, d, sizeof(date) - 1);
    date[sizeof(date) - 1] = '\0';
}

void Reservation::afficherInfos() {
    printf("Réservation - Chambre %d pour Bénéficiaire %d le %s\n", chambreNumero, beneficiaireId, date);
}
