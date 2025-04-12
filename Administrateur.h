#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include "Utilisateur.h"

class Administrateur : public virtual Utilisateur {
private:
    bool accesTotal;

public:
    Administrateur();
    Administrateur(const char* n, const char* p, int a, const char* r, const char* id, const char* mdp, bool acces);

    void afficherInfos() override;
    void definirAcces(bool acces);
    bool getAccesTotal();
};

#endif
