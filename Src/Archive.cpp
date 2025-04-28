#include "../Headers/Archive.h"
#include <iostream>
#include <algorithm>
#include <memory> // For smart pointers

using namespace std;

// Constructor
Archive::Archive(string dateDernierMisAJour) {}

// Destructor
Archive::~Archive() {}

// Add a medical record
void Archive::ajouterDossierMedical(unique_ptr<DossierMedical> dm) {
    dossiersMedicaux.push_back(move(dm));
}

// Add a reservation
void Archive::ajouterReservation(unique_ptr<Reservation> r) {
    reservations.push_back(move(r));
}

// Remove a reservation
void Archive::supprimerReservation(const Reservation &r) {
    reservations.erase(remove_if(reservations.begin(), reservations.end(),
                                 [&r](const shared_ptr<Reservation>& ptr) { return *ptr == r; }),
                       reservations.end());
}

// Add a homeless person
void Archive::ajouterSansAbri(unique_ptr<SansAbri> s) {
    archiveSansAbri.push_back(move(s));
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
        // Add logic to display details of each medical record
    }

    cout << "Consultation des réservations :" << endl;
    for (const auto& r : reservations) {
        // Add logic to display details of each reservation
    }

    cout << "Consultation des sans-abris archivés :" << endl;
    for (const auto& s : archiveSansAbri) {
        // Add logic to display details of each homeless person
    }
}

// Generate archive report
void Archive::generRapportArchive() const {
    cout << "Génération du rapport d'archive :" << endl;
    // Implement report generation logic here
}