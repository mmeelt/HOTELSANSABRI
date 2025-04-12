#ifndef TRAVAILLEURSOCIALEVENEMENTIEL_H
#define TRAVAILLEURSOCIALEVENEMENTIEL_H

#include "TravailleurSocial.h"
#include "RSEvenement.h"

class TravailleurSocialEvenementiel : public TravailleurSocial, public RSEvenement {
public:
    TravailleurSocialEvenementiel();
    TravailleurSocialEvenementiel(
        const char* n, const char* p, int a, const char* r,
        const char* id, const char* mdp,
        const char* secteur, const char* typeEvt);

    void afficherInfos() override;
};

#endif
