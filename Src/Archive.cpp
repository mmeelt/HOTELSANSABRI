#include "../Headers/Archive.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor
Archive::Archive(string dateDernierMisAJour) {}

// Destructor
Archive::~Archive() {}

// Add a medical record
void Archive::ajouterDossierMedical(DossierMedical* dm) {
    dossiersMedicaux.push_back(dm);
}

// Remove a medical record
void Archive::supprimerDossierMedical(DossierMedical dm) {
    dossiersMedicaux.erase(remove(dossiersMedicaux.begin(), dossiersMedicaux.end(), dm), dossiersMedicaux.end());
}

// Add a reservation
void Archive::ajouterReservation(Reservation* r) {
    reservations.push_back(r);
}

// Remove a reservation
void Archive::supprimerReservation(Reservation r) {
    reservations.erase(remove(reservations.begin(), reservations.end(), r), reservations.end());
}

// Add a homeless person
void Archive::ajouterSansAbri(SansAbri* s) {
    archiveSansAbri.push_back(s);
}

// Remove a homeless person
void Archive::supprimerSansAbri(SansAbri s) {
    archiveSansAbri.erase(remove(archiveSansAbri.begin(), archiveSansAbri.end(), s), archiveSansAbri.end());
}

// Display information
void Archive::afficherInfos() const {
    cout << "Nombre de dossiers médicaux : " << dossiersMedicaux.size() << endl;
    cout << "Nombre de réservations : " << reservations.size() << endl;
    cout << "Nombre de sans-abris archivés : " << archiveSansAbri.size() << endl;
}

// Consult the archive
void Archive::consulterArchive() const {
    cout << "Consultation des dossiers médicaux :" << endl;
    for (const auto& dm : dossiersMedicaux) {
        
    }

    cout << "Consultation des réservations :" << endl;
    for (const auto& r : reservations) {
        
    }

    cout << "Consultation des sans-abris archivés :" << endl;
    for (const auto& s : archiveSansAbri) {
        
    }
}

// Generate archive report
void Archive::generRapportArchive() const {
    cout << "Génération du rapport d'archive :" << endl;
    // Implement report generation logic here
}