#include "../Headers/Personne.h" // Include the header file for the Personne class
#include <iostream>

#include <string>
using namespace std;

Personne::Personne(string name, string surname, int age) {
    this->name = name; // Initialize the name
    this->surname = surname; // Initialize the surname
    this->age = age; // Initialize the age
}
void Personne::displayInfo() const {
    // Display the person's information
    cout << "Name: " << name << endl;
    cout << "Surname: " << surname << endl;
    cout << "Age: " << age << endl;
}