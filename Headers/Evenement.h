#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <string>
#include <iostream>
using namespace std;

class TravailleurSocialEvenementiel; // Forward declaration (important!)

class Evenement {
private:
    string date;
    string lieu;
    string description;
    TravailleurSocialEvenementiel* resp; // Responsable

public:
    // Constructeurs
    Evenement();
    Evenement(const string& date, const string& lieu, const string& description, TravailleurSocialEvenementiel* resp);
    Evenement(const Evenement& other); // Constructeur par recopie

    // Destructeur
    ~Evenement();

    // Getters
    string getDate() const;
    string getLieu() const;
    string getDescription() const;
    TravailleurSocialEvenementiel* getResponsable() const;

    // Setters
    void setDate(const string& date);
    void setLieu(const string& lieu);
    void setDescription(const string& description);
    void setResponsable(TravailleurSocialEvenementiel* resp);

    // Méthodes
    void afficherInfo() const;

    // Surcharges
    friend ostream& operator<<(ostream& out, const Evenement& e);
    friend istream& operator>>(istream& in, Evenement& e);
};

#endif
