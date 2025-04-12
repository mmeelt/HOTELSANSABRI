#ifndef EVENEMENTFORMATION_H
#define EVENEMENTFORMATION_H

#include "Evenement.h"

class EvenementFormation : public Evenement {
private:
    char formateur[50];

public:
    EvenementFormation();
    EvenementFormation(const std::string& t, const std::string& d, const std::string& a, TravailleurSocialEvenementiel* resp, const char* f);

    void afficherInfo() ;
};

#endif
