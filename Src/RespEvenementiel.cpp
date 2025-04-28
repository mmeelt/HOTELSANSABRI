#include "RespEvenementiel.h"

// Constructors
RespEvenementiel::RespEvenementiel() : Utilisateur() {}

RespEvenementiel::RespEvenementiel(int idValue, const string& nom, const string& prenom, int age, const string& username, const string& mdp)
    : Utilisateur(idValue, nom, prenom, age, username, mdp) {}

// Copy Constructor
RespEvenementiel::RespEvenementiel(const RespEvenementiel& other)
    : Utilisateur(other) {
    for (auto ev : other.evenements) {
        evenements.push_back(new Evenement(*ev)); // Deep copy of Evenement
    }
}

// Destructor
RespEvenementiel::~RespEvenementiel() {
    for (auto ev : evenements) {
        delete ev;
    }
    evenements.clear();
}

// CRUD Methods
void RespEvenementiel::modifierRespEvenementiel(vector<RespEvenementiel*>& respList, int idRecherche) {
    for (auto& resp : respList) {
        if (*resp->getId()[0] == idRecherche) {
            cout << "RespEvenementiel found: " << *resp << endl;
            cout << "Modify information:" << endl;
            cin >> *resp;
            return;
        }
    }
    cout << "RespEvenementiel not found!" << endl;
}

void RespEvenementiel::supprimerRespEvenementiel(vector<RespEvenementiel*>& respList, int idRecherche) {
    for (auto it = respList.begin(); it != respList.end(); ++it) {
        if (*(*it)->getId()[0] == idRecherche) {
            delete *it;
            respList.erase(it);
            cout << "RespEvenementiel deleted!" << endl;
            return;
        }
    }
    cout << "RespEvenementiel not found!" << endl;
}

// Specific Methods
void RespEvenementiel::inscrireAUneFormation(SansAbri s, Formation* f) {
    cout << "Inscription de " << s.getNom() << " a la formation: " << f->getDescription() << endl;
}

void RespEvenementiel::inscrireAUneAtelier(SansAbri s, Atelier* a) {
    cout << "Inscription de " << s.getNom() << " a l'atelier: " << a->getDescription() << endl;
}

void RespEvenementiel::planifierEvenement(Evenement* evenement) {
    evenements.push_back(evenement);
    cout << "Evenement planifie: " << evenement->getDescription() << endl;
}

void RespEvenementiel::annulerEvenement(Evenement* evenement) {
    for (auto it = evenements.begin(); it != evenements.end(); ++it) {
        if (*it == evenement) {
            evenements.erase(it);
            cout << "Evenement annule: " << evenement->getDescription() << endl;
            return;
        }
    }
    cout << "Evenement non trouve !" << endl;
}

void RespEvenementiel::modifierEvenement(Evenement* evenement) {
    cout << "Modifier l'evenement: " << evenement->getDescription() << endl;
    // Exemple : on peut demander à l'utilisateur de saisir de nouvelles informations ici
}

void RespEvenementiel::ajouterEvenement(Evenement* evenement) {
    evenements.push_back(evenement);
    cout << "Evenement ajoute: " << evenement->getDescription() << endl;
}

void RespEvenementiel::supprimerEvenement(Evenement* evenement) {
    for (auto it = evenements.begin(); it != evenements.end(); ++it) {
        if (*it == evenement) {
            delete *it;
            evenements.erase(it);
            cout << "Evenement supprime!" << endl;
            return;
        }
    }
    cout << "Evenement non trouve !" << endl;
}

// Getters and Setters
vector<Evenement*> RespEvenementiel::getEvenements() const {
    return evenements;
}

void RespEvenementiel::setEvenements(const vector<Evenement*>& evenements) {
    this->evenements = evenements;
}

// Operator Overloading
ostream& operator<<(ostream& os, const RespEvenementiel& resp) {
    os << static_cast<const Utilisateur&>(resp); // Call parent operator<<
    os << "Nombre d'evenements planifies: " << resp.evenements.size() << endl;
    return os;
}

istream& operator>>(istream& is, RespEvenementiel& resp) {
    is >> static_cast<Utilisateur&>(resp); // Call parent operator>>
    return is;
}
