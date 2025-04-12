#ifndef TRAVAILLEURSOCIAL_H
#define TRAVAILLEURSOCIAL_H

#include "Utilisateur.h"

class TravailleurSocial : public virtual Utilisateur {
private:
    char secteur[50];

public:
    TravailleurSocial();
    TravailleurSocial(const char* n, const char* p, int a, const char* r,
                      const char* id, const char* mdp, const char* s);

    void afficherInfos() override;
    void definirSecteur(const char* nouveauSecteur);
    const char* getSecteur();
};

#endif
