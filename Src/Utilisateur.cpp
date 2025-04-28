#include "../Headers/Utilisateur.h"
#include <iostream>

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