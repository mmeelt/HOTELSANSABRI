#include "TravailleurSocial.h"

// Constructors
TravailleurSocial::TravailleurSocial() : Utilisateur() {}

TravailleurSocial::TravailleurSocial(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp)
    : Utilisateur(idValue, nom, prenom, age, username, mdp) {}

// Copy Constructor
TravailleurSocial::TravailleurSocial(const TravailleurSocial& other)
    : Utilisateur(other) {
    sansAbris = other.sansAbris;
    evenements = other.evenements;
}

// Destructor
TravailleurSocial::~TravailleurSocial() {
    // No need to manually delete because vectors store pointers
    // If you are responsible for SansAbris and Evenements memory, you need to delete them here
}

// Methods

void TravailleurSocial::evaluerBesoins(SansAbri* sansAbri) {
    cout << "Évaluation des besoins pour le sans-abri." << endl;
}

void TravailleurSocial::remplirFormulaire(SansAbri* sansAbri, const string& informations) {
    cout << "Formulaire rempli avec informations: " << informations << endl;
}

void TravailleurSocial::modifierDossier(SansAbri* sansAbri, const string& nouvellesInfos) {
    cout << "Dossier modifié avec nouvelles informations: " << nouvellesInfos << endl;
}

void TravailleurSocial::supprimerSansAbri(int idSansAbri) {
    for (auto it = sansAbris.begin(); it != sansAbris.end(); ++it) {
        if (*((*it)->getId()[0]) == idSansAbri) {
            sansAbris.erase(it);
            cout << "Sans-abri supprimé." << endl;
            return;
        }
    }
    cout << "Sans-abri non trouvé." << endl;
}

void TravailleurSocial::inscrireAUneFormation(SansAbri* sansAbri, Formation* formation) {
    cout << "Sans-abri inscrit à une formation." << endl;
}

void TravailleurSocial::inscrireAUneAtelier(SansAbri* sansAbri, Atelier* atelier) {
    cout << "Sans-abri inscrit à un atelier." << endl;
}

void TravailleurSocial::planifierEvenement(Evenement* evenement) {
    cout << "Événement planifié." << endl;
}

void TravailleurSocial::annulerEvenement(Evenement* evenement) {
    cout << "Événement annulé." << endl;
}

void TravailleurSocial::modifierEvenement(Evenement* evenement) {
    cout << "Événement modifié." << endl;
}

void TravailleurSocial::ajouterEvenement(Evenement* evenement) {
    evenements.push_back(evenement);
    cout << "Événement ajouté." << endl;
}

void TravailleurSocial::supprimerEvenement(Evenement* evenement) {
    for (auto it = evenements.begin(); it != evenements.end(); ++it) {
        if (*it == evenement) {
            evenements.erase(it);
            cout << "Événement supprimé." << endl;
            return;
        }
    }
    cout << "Événement non trouvé." << endl;
}

// Operator Overloads

ostream& operator<<(ostream& os, const TravailleurSocial& t) {
    os << static_cast<const Utilisateur&>(t);  // Cast to print Utilisateur info
    os << "TravailleurSocial (nombre de sans-abris suivis): " << t.sansAbris.size() << endl;
    return os;
}

istream& operator>>(istream& is, TravailleurSocial& t) {
    is >> static_cast<Utilisateur&>(t);  // Read Utilisateur fields first
    return is;
}
