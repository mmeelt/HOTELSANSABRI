#include "Evenement.h"
#include "TravailleurSocialEvenementiel.h" // Inclure car on utilise TravailleurSocialEvenementiel

// Constructeur par défaut
Evenement::Evenement() : date(""), lieu(""), description(""), resp(nullptr) {}

// Constructeur paramétré
Evenement::Evenement(const string& date, const string& lieu, const string& description, TravailleurSocialEvenementiel* resp)
    : date(date), lieu(lieu), description(description), resp(resp) {}

// Constructeur par recopie
Evenement::Evenement(const Evenement& other)
    : date(other.date), lieu(other.lieu), description(other.description), resp(other.resp) {}

// Destructeur
Evenement::~Evenement() {}

// Getters
string Evenement::getDate() const {
    return date;
}

string Evenement::getLieu() const {
    return lieu;
}

string Evenement::getDescription() const {
    return description;
}

TravailleurSocialEvenementiel* Evenement::getResponsable() const {
    return resp;
}

// Setters
void Evenement::setDate(const string& date) {
    this->date = date;
}

void Evenement::setLieu(const string& lieu) {
    this->lieu = lieu;
}

void Evenement::setDescription(const string& description) {
    this->description = description;
}

void Evenement::setResponsable(TravailleurSocialEvenementiel* resp) {
    this->resp = resp;
}

// Méthode afficherInfo
void Evenement::afficherInfo() const {
    cout << "Date : " << date << endl;
    cout << "Lieu : " << lieu << endl;
    cout << "Description : " << description << endl;
    if (resp)
        cout << "Responsable : [Présent]" << endl;
    else
        cout << "Responsable : [Aucun]" << endl;
}

// Surcharge de l'opérateur <<
ostream& operator<<(ostream& out, const Evenement& e) {
    out << e.date << " " << e.lieu << " " << e.description;
    return out;
}

// Surcharge de l'opérateur >>
istream& operator>>(istream& in, Evenement& e) {
    cout << "Date: ";
    getline(in, e.date);
    cout << "Lieu: ";
    getline(in, e.lieu);
    cout << "Description: ";
    getline(in, e.description);
    e.resp = nullptr; // Pas de saisie de pointeur via clavier ici
    return in;
}
