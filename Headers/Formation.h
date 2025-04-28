#ifndef FORMATION_H
#define FORMATION_H

#include "Evenement.h"

class Personne; // Forward declaration pour éviter les problèmes de type incomplet

class Formation : public Evenement {
private:
    string theme;
    Personne* formateur;

public:
    // Constructeurs
    Formation();
    Formation(const string& date, const string& lieu, const string& description, TravailleurSocialEvenementiel* resp,
              const string& theme, Personne* formateur);
    Formation(const Formation& other);

    // Destructeur
    ~Formation();

    // Getters
    string getTheme() const;
    Personne* getFormateur() const;

    // Setters
    void setTheme(const string& theme);
    void setFormateur(Personne* formateur);

    // Méthodes
    void afficherInfo() const;

    // Surcharges
    friend ostream& operator<<(ostream& out, const Formation& f);
    friend istream& operator>>(istream& in, Formation& f);
};

#endif
