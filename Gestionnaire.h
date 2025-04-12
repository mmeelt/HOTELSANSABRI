#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "Administrateur.h"
#include "RespBloc.h"

class Gestionnaire : public Administrateur, public RespBloc {
public:
    Gestionnaire();
    Gestionnaire(const char* nom, const char* prenom, int age, const char* role,
                 const char* id, const char* mdp, bool acces, int blocId);

    void afficherInfos() override;
};

#endif
