#include "Bloc.h"
#include <stdio.h>
#include <string.h>

Bloc::Bloc() : id(0) {
    strcpy(nom, "Inconnu");
}

Bloc::Bloc(int id, const char* nom) : id(id) {
    strncpy(this->nom, nom, sizeof(this->nom) - 1);
    this->nom[sizeof(this->nom) - 1] = '\0';
}

void Bloc::afficherInfos() {
    printf("Bloc ID: %d\nNom: %s\n", id, nom);
}

int Bloc::getId() const {
    return id;
}
