#ifndef SANSABRI_H
#define SANSABRI_H

#include "Personne.h"
#include "DossierMedical.h" // Include the DossierMedical class
#include <vector>
#include <memory> // For std::unique_ptr

class SansAbri : public Personne
{
    string situation;
    vector<string> historiqueSejour; // List of needs of the homeless person
    std::unique_ptr<DossierMedical> dossierMedical; // Medical record of the homeless person
public:
    // Constructor
    SansAbri(const string &nom, const string &prenom, int age, const string &situation,
             vector<string> historiqueSejour = {}, std::unique_ptr<DossierMedical> dossierMedical = nullptr);

    // Destructor
    ~SansAbri();

    // Getters
    int getId() const; // Assuming Personne has a getId() method
    string getNom() const;
    string getPrenom() const;
    int getAge() const;
    string getSituation() const;
    vector<string> getHistoriqueSejour() const;
    const DossierMedical* getDossierMedical() const;

    // Setters
    void setNom(const string &nom);
    void setPrenom(const string &prenom);
    void setAge(int age);
    void setSituation(const string &situation);
    void addHistoriqueSejour(const string &sejour);
    void setDossierMedical(std::unique_ptr<DossierMedical> dossier);

    // CRUD operations
    void createHistoriqueSejour(const string &sejour);
    void readHistoriqueSejour() const;
    void updateHistoriqueSejour(int index, const string &sejour);
    void deleteHistoriqueSejour(int index);

    void afficherProfil() const override; // Override the displayInfo method from Personne
    void modifierInfo(); // Method to modify the information of the homeless person
    void consulterDossierMedical() const; // Method to consult the medical record
};

#endif // SANSABRI_H