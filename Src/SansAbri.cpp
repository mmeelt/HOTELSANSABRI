#include "../Headers/SansAbri.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor
SansAbri::SansAbri(const string &nom, const string &prenom, int age, const string &situation,
    vector<string> historiqueSejour , std::unique_ptr<DossierMedical> dossierMedical )
    : Personne(nom, prenom, age), situation(situation), historiqueSejour(historiqueSejour), dossierMedical(std::move(dossierMedical)) {}

// Destructor
SansAbri::~SansAbri() {}

// Getters
int SansAbri::getId() const {
    return;
}

string SansAbri::getNom() const {
    return nom;
}

string SansAbri::getPrenom() const {
    return prenom;
}

int SansAbri::getAge() const {
    return age;
}

string SansAbri::getSituation() const {
    return situation;
}

vector<string> SansAbri::getHistoriqueSejour() const {
    return historiqueSejour;
}

const DossierMedical* SansAbri::getDossierMedical() const {
    return dossierMedical.get();
}

// Setters
void SansAbri::setNom(const string &nom) {
    this->nom = nom;
}

void SansAbri::setPrenom(const string &prenom) {
    this->prenom = prenom;
}

void SansAbri::setAge(int age) {
    this->age = age;
}

void SansAbri::setSituation(const string &situation) {
    this->situation = situation;
}

void SansAbri::addHistoriqueSejour(const string &sejour) {
    historiqueSejour.push_back(sejour);
}

void SansAbri::setDossierMedical(std::unique_ptr<DossierMedical> dossier) {
    dossierMedical = std::move(dossier);
}

// CRUD operations
void SansAbri::createHistoriqueSejour(const string &sejour) {
    historiqueSejour.push_back(sejour);
}

void SansAbri::readHistoriqueSejour() const {
    cout << "Historique des séjours:" << endl;
    for (size_t i = 0; i < historiqueSejour.size(); ++i) {
        cout << i + 1 << ". " << historiqueSejour[i] << endl;
    }
}

void SansAbri::updateHistoriqueSejour(int index, const string &sejour) {
    if (index < 0 || index >= static_cast<int>(historiqueSejour.size())) {
        throw out_of_range("Index invalide");
    }
    historiqueSejour[index] = sejour;
}

void SansAbri::deleteHistoriqueSejour(int index) {
    if (index < 0 || index >= static_cast<int>(historiqueSejour.size())) {
        throw out_of_range("Index invalide");
    }
    historiqueSejour.erase(historiqueSejour.begin() + index);
}

// Display information
void SansAbri::afficherProfil() const {
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Age: " << age << endl;
    cout << "Situation: " << situation << endl;
    readHistoriqueSejour();
    if (dossierMedical) {
        cout << "Dossier médical disponible." << endl;
    } else {
        cout << "Pas de dossier médical." << endl;
    }
}

// Modify information
void SansAbri::modifierInfo() {
    cout << "Modifier les informations de " << nom << " " << prenom << ":" << endl;
    cout << "Nom actuel: " << nom << ". Entrez le nouveau nom: ";
    cin >> nom;
    cout << "Prenom actuel: " << prenom << ". Entrez le nouveau prenom: ";
    cin >> prenom;
    cout << "Age actuel: " << age << ". Entrez le nouvel age: ";
    cin >> age;
    cout << "Situation actuelle: " << situation << ". Entrez la nouvelle situation: ";
    cin.ignore();
    getline(cin, situation);
}

// Consult medical record
void SansAbri::consulterDossierMedical() const {
    if (dossierMedical) {
        dossierMedical->displayDossier(); 
    } else {
        cout << "Pas de dossier médical disponible." << endl;
    }
}