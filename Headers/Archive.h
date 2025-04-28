#ifndef ARCHIVE_H
#define ARCHIVE_H
#include <map>
#include <string>
#include <vector>
#include <memory> // Include memory for smart pointers
#include "DossierMedical.h"
#include "SansAbri.h"
#include "Reservation.h"
#include "Bloc.h"
#include "Utilisateur.h"
using namespace std;

class Archive
{
private:
    vector<unique_ptr<DossierMedical>> dossiersMedicaux; // List of medical records
    vector<unique_ptr<Reservation>> reservations;        // List of reservations
    vector<unique_ptr<SansAbri>> archiveSansAbri;        // List of homeless people
    vector<unique_ptr<Bloc>> blocs;                      // List of blocs
    vector<unique_ptr<Utilisateur>> userDatabase;        // List of instances of the User class
public:
    // Access control map
    map<pair<string, string>, string> accessControlMap; // Map to manage access control (username, password) -> role
    // Constructor
    Archive(string dateDernierMisAJour);
    ~Archive();
    // CRUD operations
    void ajouterDossierMedical(unique_ptr<DossierMedical> dm);
    void supprimerDossierMedical(const DossierMedical& dm);
    void ajouterReservation(unique_ptr<Reservation> r);
    void supprimerReservation(const Reservation& r);
    void ajouterSansAbri(unique_ptr<SansAbri> s);
    void supprimerSansAbri(const SansAbri& s);

    // Manage access control
    void ajouterUtilisateur(const string &username, const string &password, const string &role);
    void supprimerUtilisateur(const string &username, const string &password);
    string obtenirRole(const string &username, const string &password) const;

    // Consult the archive
    void consulterArchive() const;

    // Generate archive report
    void generRapportArchive() const;

    unique_ptr<Bloc> retrieveBlocFromArchive (int id) const; // Mark as const since it doesn't modify the object

    // Methods to access userDatabase
    void ajouterUtilisateurDansDatabase(unique_ptr<Utilisateur> utilisateur);
    void supprimerUtilisateurDeDatabase(unique_ptr<Utilisateur> utilisateur); // Use const reference
    vector<Utilisateur *> obtenirTousLesUtilisateurs() const;
    unique_ptr<Utilisateur> trouverUtilisateurParNom(const string &username) const;

    void afficherInfos() const; // Display information about the archive

    
};

#endif // ARCHIVE_H