#include "Atelier.h"

// Constructeur par défaut
Atelier::Atelier() : Evenement(), sujet(""), duree(""), capacite(0) {}

// Constructeur paramétré
Atelier::Atelier(const string& date, const string& lieu, const string& description, TravailleurSocialEvenementiel* resp,
                 const string& sujet, const string& duree, int capacite)
    : Evenement(date, lieu, description, resp), sujet(sujet), duree(duree), capacite(capacite) {}

// Constructeur de recopie
Atelier::Atelier(const Atelier& other)
    : Evenement(other), sujet(other.sujet), duree(other.duree), capacite(other.capacite) {}

// Destructeur
Atelier::~Atelier() {}

// Getters
string Atelier::getSujet() const {
    return sujet;
}

string Atelier::getDuree() const {
    return duree;
}

int Atelier::getCapacite() const {
    return capacite;
}

// Setters
void Atelier::setSujet(const string& sujet) {
    this->sujet = sujet;
}

void Atelier::setDuree(const string& duree) {
    this->duree = duree;
}

void Atelier::setCapacite(int capacite) {
    this->capacite = capacite;
}

// Méthodes
void Atelier::afficherInfo() const {
    Evenement::afficherInfo();
    cout << "Sujet : " << sujet << endl;
    cout << "Durée : " << duree << endl;
    cout << "Capacité : " << capacite << endl;
}

// Surcharge de l'opérateur <<
ostream& operator<<(ostream& out, const Atelier& a) {
    out << (Evenement&)a << " " << a.sujet << " " << a.duree << " " << a.capacite;
    return out;
}

// Surcharge de l'opérateur >>
istream& operator>>(istream& in, Atelier& a) {
    in >> (Evenement&)a;
    cout << "Sujet: ";
    getline(in >> ws, a.sujet);
    cout << "Durée: ";
    getline(in, a.duree);
    cout << "Capacité: ";
    in >> a.capacite;
    return in;
}

// Surcharge de l'opérateur ==
bool Atelier::operator==(const Atelier& other) const {
    return Evenement::operator==(other) && sujet == other.sujet && duree == other.duree && capacite == other.capacite;
}
