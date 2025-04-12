#ifndef EVENEMENTATELIER_H
#define EVENEMENTATELIER_H

#include "Evenement.h"

class EvenementAtelier : public Evenement {
private:
    char activitePrincipale[50];

public:
    EvenementAtelier();
    EvenementAtelier(const std::string& t, const std::string& d, const std::string& a, TravailleurSocialEvenementiel* resp);

    void afficherInfo();
};

#endif
