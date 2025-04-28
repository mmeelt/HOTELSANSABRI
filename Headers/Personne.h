#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>
#include <string>
using namespace std;



class Personne {
protected:   
    std::string nom; // Name of the person
    std::string prenom; // Surname of the person
    int age; // Age of the person
public:
    // Constructor and Destructor
    Personne(string name, string surname, int age);
    virtual void afficherProfil() const = 0; 
    virtual ~Personne() = default;

};

#endif // PERSONNE_H