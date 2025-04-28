#include "Formation.h"

// Constructeur par défaut
Formation::Formation() : Evenement(), theme(""), formateur(nullptr) {}

// Constructeur paramétré
Formation::Formation(const string& date, const string& lieu, const string& description, vector<unique_ptr<TravailleurSocialEvenementiel>> resp,
    const string& theme, std::unique_ptr<Personne> formateur)
    : Evenement(date, lieu, description, resp), theme(theme), formateur(std::move(formateur)) {}

// Destructeur
Formation::~Formation() {}

// Getters
string Formation::getTheme() const {
    return theme;
}

Utilisateur* Formation::getFormateur() const {
    return dynamic_cast<Utilisateur*>(formateur.get());
}

// Setters
void Formation::setTheme(const string& theme) {
    this->theme = theme;
}

void Formation::setFormateur(unique_ptr<Utilisateur> formateur) {
    this->formateur = std::move(formateur);
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


bool Formation::operator==(const Formation& other) const {
    return Evenement::operator==(other) && theme == other.theme && formateur == other.formateur;
}
