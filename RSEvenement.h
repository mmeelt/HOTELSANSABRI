#ifndef RSEVENEMENT_H
#define RSEVENEMENT_H

#include "Utilisateur.h"

class RSEvenement : public virtual Utilisateur {
private:
    char typeEvenement[50];

public:
    RSEvenement();
    RSEvenement(const char* n, const char* p, int a, const char* r,
                const char* id, const char* mdp, const char* typeEvt);

    void afficherInfos() override;
    void definirTypeEvenement(const char* nouveauType);
    const char* getTypeEvenement();
};

#endif
