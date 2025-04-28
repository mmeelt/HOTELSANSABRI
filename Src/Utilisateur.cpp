#include "../Headers/Utilisateur.h"
#include <iostream>
#include <fstream> 

using namespace std;

// Destructor
Utilisateur::~Utilisateur() {}

// Getters and Setters
int Utilisateur::getId() const {
    return id;
}

void Utilisateur::setId(int id) {
    this->id = id;
}

string Utilisateur::getUsername() const {
    return username;
}

void Utilisateur::setUsername(string &username) {
    this->username = username;
}

string Utilisateur::getMdp() const {
    return mdp;
}

void Utilisateur::setMdp(string &mdp) {
    this->mdp = mdp;
}

// Functional Methods
void Utilisateur::afficherProfil() const {
    cout << "Profil Utilisateur:" << endl;
    cout << "ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Age: " << age << endl;
    cout << "Username: " << username << endl;
}

bool Utilisateur::login(string &username, string &mdp) {
    return this->username == username && this->mdp == mdp;
}

void Utilisateur::logout() {
    cout << "Utilisateur " << username << " déconnecté." << endl;
}

bool Utilisateur::modifierMDP(string &ancienmdp, string &nouveaumdp) {
    if (this->mdp == ancienmdp) {
        this->mdp = nouveaumdp;
        return true;
    }
    return false;
}

// ======= FILE MANAGEMENT ========


void Utilisateur::ecrireDansFichier(std::ofstream& fichier) const {
    if (fichier.is_open()) {
        fichier << id << std::endl;
        fichier << username << std::endl;
        fichier << mdp << std::endl;
        fichier << nom << std::endl;
        fichier << prenom << std::endl;
        fichier << age << std::endl;
    } else {
        std::cerr << "Erreur : fichier non ouvert pour l'écriture." << std::endl;
    }
}

void Utilisateur::lireDepuisFichier(std::ifstream& fichier) {
    if (fichier.is_open()) {
        fichier >> id;
        fichier.ignore(); // ignore newline after id
        std::getline(fichier, username);
        std::getline(fichier, mdp);
        std::getline(fichier, nom);
        std::getline(fichier, prenom);
        fichier >> age;
        fichier.ignore(); // ignore newline after age
    } else {
        std::cerr << "Erreur : fichier non ouvert pour la lecture." << std::endl;
    }
}
