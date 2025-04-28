#include "../Headers/Personne.h" // Include the header file for the Personne class
#include <iostream>

#include <string>
using namespace std;

Personne::Personne(string name, string surname, int age) {
    this->nom = name; // Initialize the name
    this->prenom = surname; // Initialize the surname
    this->age = age; // Initialize the age
}
void Personne::afficherProfil() const {
    // Display the person's information
    cout << "Name: " << nom << endl;
    cout << "Surname: " << prenom << endl;
    cout << "Age: " << age << endl;
}