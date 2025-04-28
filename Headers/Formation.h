#ifndef FORMATION_H
#define FORMATION_H

#include "Evenement.h"
#include <memory> // For std::unique_ptr

class Personne; // Forward declaration pour éviter les problèmes de type incomplet

class Formation : public Evenement {
private:
    string theme;
    std::unique_ptr<Personne> formateur; // Use unique_ptr for better memory management

public:
    // Constructeurs
    Formation();
    Formation(const string& date, const string& lieu, const string& description, vector<unique_ptr<TravailleurSocialEvenementiel>> resp,
              const string& theme, std::unique_ptr<Personne> formateur);
    Formation(const Formation& other) = delete; // Delete copy constructor to avoid shallow copy issues
    Formation(Formation&& other) noexcept; // Move constructor

    // Destructeur
    ~Formation();

    // Getters
    string getTheme() const;
    Utilisateur* getFormateur() const; // Return a const pointer to prevent modification

    // Setters
    void setTheme(const string& theme);
    void setFormateur(std::unique_ptr<Utilisateur> formateur);

    // Méthodes
    void afficherInfo() const;

    void ajouterParticipant(unique_ptr<SansAbri> participant); // Ajouter un participant à la formation

    // Surcharges
    friend ostream& operator<<(ostream& out, const Formation& f);
    friend istream& operator>>(istream& in, Formation& f);
    bool operator==(const Formation& other) const;

};

#endif
