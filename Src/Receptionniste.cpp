#include "Receptionniste.h"

// Constructors
Receptionniste::Receptionniste() : Utilisateur(), poste("") {}

Receptionniste::Receptionniste(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp, const string& poste)
    : Utilisateur(idValue, nom, prenom, age, username, mdp), poste(poste) {}

// Copy Constructor
Receptionniste::Receptionniste(const Receptionniste& other)
    : Utilisateur(other), poste(other.poste) {}

// Destructor
Receptionniste::~Receptionniste() {
    // No specific dynamic memory to manage separately
}

// CRUD Methods
void Receptionniste::modifierReceptionniste(vector<Receptionniste*>& receptionnistes, int idRecherche) {
    for (auto& r : receptionnistes) {
        if (*r->getId()[0] == idRecherche) {
            cout << "Receptionniste found: " << *r << endl;
            cout << "Modify information:" << endl;
            cin >> *r;
            return;
        }
    }
    cout << "Receptionniste not found!" << endl;
}

void Receptionniste::supprimerReceptionniste(vector<Receptionniste*>& receptionnistes, int idRecherche) {
    for (auto it = receptionnistes.begin(); it != receptionnistes.end(); ++it) {
        if (*(*it)->getId()[0] == idRecherche) {
            delete *it;
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
