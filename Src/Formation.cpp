#include "Formation.h"

// Constructeur par défaut
Formation::Formation() : Evenement(), theme(""), formateur(nullptr) {}

// Constructeur paramétré
Formation::Formation(const string& date, const string& lieu, const string& description, TravailleurSocialEvenementiel* resp,
                     const string& theme, Personne* formateur)
    : Evenement(date, lieu, description, resp), theme(theme), formateur(formateur) {}

// Constructeur par recopie
Formation::Formation(const Formation& other)
    : Evenement(other), theme(other.theme), formateur(other.formateur) {}

// Destructeur
Formation::~Formation() {}

// Getters
string Formation::getTheme() const {
    return theme;
}

Personne* Formation::getFormateur() const {
    return formateur;
}

// Setters
void Formation::setTheme(const string& theme) {
    this->theme = theme;
}

void Formation::setFormateur(Personne* formateur) {
    this->formateur = formateur;
}

// Méthodes
void Formation::afficherInfo() const {
    Evenement::afficherInfo();
    cout << "Theme : " << theme << endl;
    if (formateur)
        cout << "Formateur : [Présent]" << endl;
    else
        cout << "Formateur : [Aucun]" << endl;
}

// Surcharges
ostream& operator<<(ostream& out, const Formation& f) {
    out << (Evenement&)f << " " << f.theme;
    return out;
}

istream& operator>>(istream& in, Formation& f) {
    in >> (Evenement&)f;
    cout << "Theme: ";
    getline(in >> ws, f.theme);
    f.formateur = nullptr; // Pas de saisie de pointeur via clavier
    return in;
}
