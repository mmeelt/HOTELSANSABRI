#include "../Headers/Receptioniste.h"


// Copy Constructor
Receptionniste::Receptionniste(const Receptionniste& other)
    : Utilisateur(other), poste(other.poste) {}

// Destructor
Receptionniste::~Receptionniste() {
    // No specific dynamic memory to manage separately
}

// CRUD Methods
void Receptionniste::modifierReceptionniste(vector<unique_ptr<Receptionniste>>& receptionnistes, int idRecherche) {
    for (auto& r : receptionnistes) {
        if (r->getId() == idRecherche) {
            cout << "Receptionniste found: " << *r << endl;
            cout << "Modify information:" << endl;
            cin >> *r;
            return;
        }
    }
    cout << "Receptionniste not found!" << endl;
}

void Receptionniste::supprimerReceptionniste(vector<unique_ptr<Receptionniste>>& receptionnistes, int idRecherche) {
    for (auto it = receptionnistes.begin(); it != receptionnistes.end(); ++it) {
        if ((*it)->getId() == idRecherche) {
            receptionnistes.erase(it);
            cout << "Receptionniste deleted!" << endl;
            return;
        }
    }
    cout << "Receptionniste not found!" << endl;
}

// Specific Methods
void Receptionniste::ajouterReservation(SansAbri* sansAbri, Chambre* chambre) {
    cout << "Reservation added for SansAbri and Chambre!" << endl;
}

void Receptionniste::libererChambre(Chambre* chambre) {
    cout << "Chambre liberated!" << endl;
}

void Receptionniste::verifierChambresDisponibles() {
    cout << "Checking available chambres..." << endl;
}

void Receptionniste::supprimerReservation(Reservation* reservation) {
    cout << "Reservation deleted!" << endl;
}

// Getter and Setter
string Receptionniste::getPoste() const {
    return poste;
}

void Receptionniste::setPoste(const string& poste) {
    this->poste = poste;
}

// Overloaded Operators
ostream& operator<<(ostream& os, const Receptionniste& r) {
    os << static_cast<const Utilisateur&>(r); // Reuse Utilisateur output
    os << "Poste: " << r.poste << endl;
    return os;
}

istream& operator>>(istream& is, Receptionniste& r) {
    cout << "Enter username: ";
    is >> r.username;
    cout << "Enter password: ";
    is >> r.mdp;
    cout << "Enter poste: ";
    is >> r.poste;
    return is;
}

// Override afficherProfil
void Receptionniste::afficherProfil() const {
    Utilisateur::afficherProfil(); // Call base version
    cout << "Poste: " << poste << endl;
}

// Save Receptionniste
void Receptionniste::ecrireDansFichier(std::ofstream& fichier) const {
    Utilisateur::ecrireDansFichier(fichier); // Save inherited fields
    fichier << poste << std::endl;            // Save poste
}

// Load Receptionniste
void Receptionniste::lireDepuisFichier(std::ifstream& fichier) {
    Utilisateur::lireDepuisFichier(fichier); // Load inherited fields
    fichier >> poste;                        // Load poste
}

// =================== FILE MANAGEMENT ===================

#include <fstream> // make sure you include it if not already

void Receptionniste::ecrireDansFichier(ofstream& fichier) const {
    Utilisateur::ecrireDansFichier(fichier); // Save inherited attributes
    if (fichier.is_open()) {
        fichier << poste << endl;
    } else {
        cerr << "Erreur : fichier non ouvert pour l'écriture." << endl;
    }
}

void Receptionniste::lireDepuisFichier(ifstream& fichier) {
    Utilisateur::lireDepuisFichier(fichier); // Load inherited attributes
    if (fichier.is_open()) {
        getline(fichier, poste);
    } else {
        cerr << "Erreur : fichier non ouvert pour la lecture." << endl;
    }
}
