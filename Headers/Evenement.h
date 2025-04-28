#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <string>
#include <vector>
#include <memory> // For std::unique_ptr
#include "TravailleurSocialEvenementiel.h"

using namespace std;

class Evenement {
private:
    string date;
    string lieu;
    string description;
    vector<unique_ptr<TravailleurSocialEvenementiel>> resp; // Use unique_ptr for better memory management

    static int nbEvenements; // Attribut statique pour compter les événements

public:
    Evenement();
    Evenement(const string& date, const string& lieu, const string& description, vector<unique_ptr<TravailleurSocialEvenementiel>> resp);
    Evenement(const Evenement& autre) = delete; // Delete copy constructor to avoid shallow copies
    Evenement(Evenement&& autre) noexcept; // Move constructor
    Evenement(const string& date, const string& lieu, const string& description, unique_ptr<TravailleurSocialEvenementiel> resp);
    ~Evenement();

    // Getters et setters
    string getDate() const;
    void setDate(const string& date);

    string getLieu() const;
    void setLieu(const string& lieu);

    string getDescription() const;
    void setDescription(const string& description);

    vector<unique_ptr<TravailleurSocialEvenementiel>> getResp() const;
    void setResp(vector<unique_ptr<TravailleurSocialEvenementiel>> resp);

    // Méthodes
    void afficherInfo() const;

    void planifier(const string& date, const string& lieu, const string& description);

    void annuler();
    void modifier(const string& date, const string& lieu, const string& description);
    void ajouter();
    // Méthode statique pour accéder au nombre total
    static int getNbEvenements();

    // Surcharges opérateurs
    friend ostream& operator<<(ostream& os, const Evenement& e);
    friend istream& operator>>(istream& is, Evenement& e);
    bool operator==(const Evenement& autre) const;
};

#endif
