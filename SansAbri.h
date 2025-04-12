#ifndef SANSABRI_H
#define SANSABRI_H

#include "Personne.h"

class SansAbri : public Personne {
private:
    int id;
    char situationActuelle[100];
    bool aBesoinSoins;

public:
    SansAbri();
    SansAbri(int identifiant, const char* n, const char* p, int a, const char* situation, bool soins);

    void afficherInfos() override;
    void modifierSituation(const char* nouvelleSituation);
    void definirBesoinSoins(bool besoin);
    int getId();
};

#endif
