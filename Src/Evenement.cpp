#include "Evenement.h"
#include <iostream>

using namespace std;

// Initialisation de l'attribut statique
int Evenement::nbEvenements = 0;

// Constructeurs
Evenement::Evenement() : date(""), lieu(""), description(""), resp() {
    nbEvenements++;
}

Evenement::Evenement(const string& date, const string& lieu, const string& description, const vector<TravailleurSocialEvenementiel*>& resp)
    : date(date), lieu(lieu), description(description), resp(resp) {
    nbEvenements++;
}

Evenement::Evenement(const Evenement& autre)
    : date(autre.date), lieu(autre.lieu), description(autre.description), resp(autre.resp) {
    nbEvenements++;
}
Evenement::Evenement(const string& date, const string& lieu, const string& description, TravailleurSocialEvenementiel* resp)
    : date(date), lieu(lieu), description(description), resp(resp) {
    // Initialization or other logic, if necessary
}


Evenement::~Evenement() {
    nbEvenements--;
}

// Getters et Setters
string Evenement::getDate() const {
    return date;
}

void Evenement::setDate(const string& date) {
    this->date = date;
}

string Evenement::getLieu() const {
    return lieu;
}

void Evenement::setLieu(const string& lieu) {
    this->lieu = lieu;
}

string Evenement::getDescription() const {
    return description;
}

void Evenement::setDescription(const string& description) {
    this->description = description;
}

vector<TravailleurSocialEvenementiel*> Evenement::getResp() const {
    return resp;
}

void Evenement::setResp(const vector<TravailleurSocialEvenementiel*>& resp) {
    this->resp = resp;
}

// Méthode statique
int Evenement::getNbEvenements() {
    return nbEvenements;
}

// Méthodes
void Evenement::afficherInfo() const {
    cout << "Date: " << date << endl;
    cout << "Lieu: " << lieu << endl;
    cout << "Description: " << description << endl;
    cout << "Nombre de responsables: " << resp.size() << endl;
}

// Surcharges d'opérateurs
ostream& operator<<(ostream& os, const Evenement& e) {
    os << e.date << " " << e.lieu << " " << e.description << " " << e.resp.size();
    return os;
}

istream& operator>>(istream& is, Evenement& e) {
    cout << "Entrez la date : ";
    is >> e.date;
    cout << "Entrez le lieu : ";
    is >> e.lieu;
    cout << "Entrez la description : ";
    is >> e.description;
    return is;
}

bool Evenement::operator==(const Evenement& autre) const {
    return (date == autre.date && lieu == autre.lieu && description == autre.description && resp.size() == autre.resp.size());
}
