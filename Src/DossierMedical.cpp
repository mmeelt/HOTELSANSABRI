#include "../Headers/DossierMedical.h"
#include <iostream>
using namespace std;

// Constructor
DossierMedical::DossierMedical(unique_ptr<SansAbri> sansAbri, vector<string> historiqueMaladies, vector<string> traitementsEnCours, string dateDernierMisAJour )
    : historiqueMaladies(historiqueMaladies), traitementsEnCours(traitementsEnCours), dateDernierMisAJour(dateDernierMisAJour) {
    this->sansAbri = std::move(sansAbri); // Initialize the pointer to the homeless person
}

// Destructor
DossierMedical::~DossierMedical() {}

// Getters
std::string DossierMedical::getPatientName() const {
    return this->sansAbri->getNom(); // Assuming SansAbri has a method getNom() to get the name
}



std::vector<std::string> DossierMedical::getMedicalHistory() const {
    return historiqueMaladies;
}

std::vector<std::string> DossierMedical::getPrescriptions() const {
    return traitementsEnCours;
}

// Setters
void DossierMedical::setPatientName(const std::string &name) {
    this->sansAbri->setNom(name) ;
}


// Methods to add records
void DossierMedical::addMedicalHistory(const std::string &record) {
    historiqueMaladies.push_back(record);
    dateDernierMisAJour = "Today"; // Placeholder for actual date logic
}

void DossierMedical::addPrescription(const std::string &prescription) {
    traitementsEnCours.push_back(prescription);
    dateDernierMisAJour = "Today"; // Placeholder for actual date logic
}

// Display method
void DossierMedical::displayDossier() const {
    cout << "Patient Name: " << this->getPatientName() << endl;
    cout << "Last Updated: " << dateDernierMisAJour << endl;

    cout << "Medical History:" << endl;
    for (const auto &record : historiqueMaladies) {
        cout << "- " << record << endl;
    }

    cout << "Prescriptions:" << endl;
    for (const auto &prescription : traitementsEnCours) {
        cout << "- " << prescription << endl;
    }
}