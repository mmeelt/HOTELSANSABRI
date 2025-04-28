#ifndef ARCHIVE_H
#define ARCHIVE_H
#include <map>
#include <string>
#include <vector> // Include vector
#include "DossierMedical.h"
#include "SansAbri.h"    // Include the SansAbri class
#include "Reservation.h" // Include the Reservation class
#include "Bloc.h"        // Include the Bloc class
#include "Utilisateur.h" // Include the Utilisateur class
using namespace std;

class Archive
{
private:
    vector<DossierMedical *> dossiersMedicaux; // List of medical records
    vector<Reservation *> reservations;        // List of reservations
    vector<SansAbri *> archiveSansAbri;        // List of homeless people
    vector<Bloc *> blocs;                      // List of blocs
    vector<Utilisateur *> userDatabase;        // List of instances of the User class
public:
    // Access control map
    map<pair<string, string>, string> accessControlMap; // Map to manage access control (username, password) -> role
    // Constructor
    Archive(string dateDernierMisAJour);
    ~Archive();
    // CRUD operations
    void ajouterDossierMedical(DossierMedical* dm);
    void supprimerDossierMedical(DossierMedical dm);
    void ajouterReservation(Reservation* r);
    void supprimerReservation(Reservation r);
    void ajouterSansAbri(SansAbri* s);
    void supprimerSansAbri(SansAbri s);

    // Manage access control
    void ajouterUtilisateur(const string &username, const string &password, const string &role);
    void supprimerUtilisateur(const string &username, const string &password);
    string obtenirRole(const string &username, const string &password) const;

    // Consult the archive
    void consulterArchive() const;

    // Generate archive report
    void generRapportArchive() const;

    Bloc *retrieveBlocFromArchive(int id);

    // Methods to access userDatabase
    void ajouterUtilisateurDansDatabase(Utilisateur *utilisateur);
    void supprimerUtilisateurDeDatabase(Utilisateur *utilisateur);
    vector<Utilisateur *> obtenirTousLesUtilisateurs() const;
    Utilisateur *trouverUtilisateurParNom(const string &username) const;

    void afficherInfos() const; // Display information about the archive
};

#endif // ARCHIVE_H