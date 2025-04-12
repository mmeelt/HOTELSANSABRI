#ifndef RESPBLOC_H
#define RESPBLOC_H

#include "Utilisateur.h"

class RespBloc : public virtual Utilisateur {
private:
    int blocId;

public:
    RespBloc();
    RespBloc(const char* nom, int age, int blocId);

    void afficherInfos() override;
    int getBlocId() const;  // Getter ajouté
};

#endif
