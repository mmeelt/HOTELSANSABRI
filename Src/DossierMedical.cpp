#include "../Headers/DossierMedical.h"
#include <iostream>
using namespace std;

// Constructor
DossierMedical::DossierMedical(SansAbri* sansAbri, vector<string> historiqueMaladies, vector<string> traitementsEnCours, string dateDernierMisAJour)
    : historiqueMaladies(historiqueMaladies), traitementsEnCours(traitementsEnCours), dateDernierMisAJour(dateDernierMisAJour) {
    this->sansAbri = sansAbri; // Initialize the pointer to the homeless person
}

// Destructor
DossierMedical::~DossierMedical() {}

// Getters
std::string DossierMedical::getPatientName() const {
    return patientName;
}

int DossierMedical::getPatientID() const {
    return patientID;
}

std::vector<std::string> DossierMedical::getMedicalHistory() const {
    return historiqueMaladies;
}

std::vector<std::string> DossierMedical::getPrescriptions() const {
    return traitementsEnCours;
}

// Setters
void DossierMedical::setPatientName(const std::string &name) {
    patientName = name;
}

void DossierMedical::setPatientID(int id) {
    patientID = id;
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
    cout << "Patient Name: " << patientName << endl;
    cout << "Patient ID: " << patientID << endl;
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