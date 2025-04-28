#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <iostream>

using namespace std;

class Personne {
protected:
    string nom;
    string prenom;
    int age;

public:
    // Constructors
    Personne() : nom(""), prenom(""), age(0) {}
    Personne(const string& nom, const string& prenom, int age) : nom(nom), prenom(prenom), age(age) {}

    // Getter and Setter
    string getNom() const { return nom; }
    void setNom(const string& nom) { this->nom = nom; }

    string getPrenom() const { return prenom; }
    void setPrenom(const string& prenom) { this->prenom = prenom; }

    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    // Pure Virtual Method (abstract class)
    virtual void afficherInfos() const = 0;

    // Virtual Destructor
    virtual ~Personne() {}
};

#endif // PERSONNE_H
