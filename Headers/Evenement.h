#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <string>
#include <vector>
#include "TravailleurSocialEvenementiel.h"

using namespace std;

class Evenement {
private:
    string date;
    string lieu;
    string description;
    vector<TravailleurSocialEvenementiel*> resp; // utiliser vector*

    static int nbEvenements; // Attribut statique pour compter les événements

public:
    Evenement();
    Evenement(const string& date, const string& lieu, const string& description, const vector<TravailleurSocialEvenementiel*>& resp);
    Evenement(const Evenement& autre);
    // Add this constructor to match the one in Atelier
    Evenement(const string& date, const string& lieu, const string& description, TravailleurSocialEvenementiel* resp);
    ~Evenement();

    // Getters et setters
    string getDate() const;
    void setDate(const string& date);

    string getLieu() const;
    void setLieu(const string& lieu);

    string getDescription() const;
    void setDescription(const string& description);

    vector<TravailleurSocialEvenementiel*> getResp() const;
    void setResp(const vector<TravailleurSocialEvenementiel*>& resp);

    // Méthodes
    void afficherInfo() const;

    // Méthode statique pour accéder au nombre total
    static int getNbEvenements();

    // Surcharges opérateurs
    friend ostream& operator<<(ostream& os, const Evenement& e);
    friend istream& operator>>(istream& is, Evenement& e);
    bool operator==(const Evenement& autre) const;
};

#endif
