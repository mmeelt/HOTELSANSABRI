#include "Chambre.h"
#include <stdio.h>

Chambre::Chambre() : numero(0), blocId(0), estOccupee(false) {}

Chambre::Chambre(int numero, int blocId, bool occupee)
    : numero(numero), blocId(blocId), estOccupee(occupee) {}

void Chambre::afficherInfos() {
    printf("Chambre %d - Bloc %d - %s\n", numero, blocId, estOccupee ? "Occupée" : "Libre");
}

int Chambre::getNumero() const {
    return numero;
}

int Chambre::getBlocId() const {
    return blocId;
}

bool Chambre::estLibre() const {
    return !estOccupee;
}
