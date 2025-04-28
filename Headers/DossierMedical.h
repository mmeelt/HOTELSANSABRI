#ifndef DOSSIER_MEDICAL_H
#define DOSSIER_MEDICAL_H

#include <string>
#include <vector>
#include "SansAbri.h"
using namespace std;

class DossierMedical
{
    SansAbri *sansAbri; // Pointer to the homeless person
    vector<string> historiqueMaladies; // Medical history of the patient
    vector<string> traitementsEnCours; // List of prescriptions
    string dateDernierMisAJour; // Date of the last update

public:
    // Constructor
    DossierMedical(SansAbri* sansAbri, vector<string> historiqueMaladies = {}, vector<string> traitementsEnCours = {}, string dateDernierMisAJour = "Today");
    // Destructor
    ~DossierMedical();
    // Getters
    std::string getPatientName() const;
    int getPatientID() const;
    std::vector<std::string> getMedicalHistory() const;
    std::vector<std::string> getPrescriptions() const;

    // Setters
    void setPatientName(const std::string &name);
    void setPatientID(int id);

    // Methods to add records
    void addMedicalHistory(const std::string &record);
    void addPrescription(const std::string &prescription);

    // Display method
    void displayDossier() const;
};

#endif // DOSSIER_MEDICAL_H