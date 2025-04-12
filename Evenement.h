#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <string>

class TravailleurSocialEvenementiel;  // Déclaration anticipée de la classe

class Evenement {
private:
    std::string date;
    std::string lieu;
    std::string description;
    TravailleurSocialEvenementiel* resp;

public:
    Evenement(const std::string& date, const std::string& lieu, const std::string& description, TravailleurSocialEvenementiel* resp);
    void afficherInfo() const;
    void saisirInfos(); // method for keyboard input

};

#endif // EVENEMENT_H
