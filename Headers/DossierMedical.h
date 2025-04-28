#ifndef DOSSIER_MEDICAL_H
#define DOSSIER_MEDICAL_H

#include <string>
#include <vector>
#include <memory> // For std::unique_ptr
#include "SansAbri.h"
using namespace std;

class DossierMedical
{
    unique_ptr<SansAbri> sansAbri; // Unique pointer to the homeless person
    vector<string> historiqueMaladies; // Medical history of the patient
    vector<string> traitementsEnCours; // List of prescriptions
    string dateDernierMisAJour; // Date of the last update

public:
    // Constructor
    DossierMedical(unique_ptr<SansAbri> sansAbri, vector<string> historiqueMaladies = {}, vector<string> traitementsEnCours = {}, string dateDernierMisAJour = "Today");
    // Destructor
    ~DossierMedical();
    // Getters
    std::string getPatientName() const;
    std::vector<std::string> getMedicalHistory() const;
    std::vector<std::string> getPrescriptions() const;

    // Setters
    void setPatientName(const std::string &name);

    // Methods to add records
    void addMedicalHistory(const std::string &record);
    void addPrescription(const std::string &prescription);

    // Display method
    void displayDossier() const;
};

#endif // DOSSIER_MEDICAL_H