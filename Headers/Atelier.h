#ifndef ATELIER_H
#define ATELIER_H

#include "Evenement.h"

class Atelier : public Evenement {
private:
    string sujet;
    string duree;
    int capacite;

public:
    // Constructeurs
    Atelier();
    Atelier(const string& date, const string& lieu, const string& description, TravailleurSocialEvenementiel* resp,
            const string& sujet, const string& duree, int capacite);
    Atelier(const Atelier& other);

    // Destructeur
    ~Atelier();

    // Getters
    string getSujet() const;
    string getDuree() const;
    int getCapacite() const;

    // Setters
    void setSujet(const string& sujet);
    void setDuree(const string& duree);
    void setCapacite(int capacite);

    // Méthodes
    void afficherInfo() const;

    // Surcharges
    friend ostream& operator<<(ostream& out, const Atelier& a);
    friend istream& operator>>(istream& in, Atelier& a);
    bool operator==(const Atelier& other) const;  // Declaration of operator==
};

#endif
