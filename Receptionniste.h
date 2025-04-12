#ifndef RECEPTIONNISTE_H
#define RECEPTIONNISTE_H

#include "Utilisateur.h"

class Receptionniste : public Utilisateur {
private:
    int numeroPoste;

public:
    Receptionniste();
    Receptionniste(const char* n, const char* p, int a, const char* r, const char* id, const char* mdp, int numPoste);

    void afficherInfos() override;
    void definirPoste(int nouveauPoste);
    int getNumeroPoste();
};

#endif
