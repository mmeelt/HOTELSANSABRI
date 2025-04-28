#include "TravailleurSocialEvenementiel.h"
#include <algorithm> // For std::remove_if
using namespace std;
// Constructor implementation
TravailleurSocialEvenementiel::TravailleurSocialEvenementiel(string nom, string prenom, int age, int id, string& username, string& mdp)
    : Utilisateur(nom, prenom, age, id, username, mdp),
      TravailleurSocial(nom, prenom, age, id, username, mdp),
      RespEvenementiel(nom, prenom, age, id, username, mdp)
{}

// CRUD methods
void TravailleurSocialEvenementiel::modifierTravailleurSocialEvenementiel(std::vector<TravailleurSocialEvenementiel>& list, int idRecherche) {
    for (auto& tse : list) {
        if (tse.getId() == idRecherche) {
            std::cout << "Entrez le nouveau nom : ";
            std::cin >> tse.nom;
            std::cout << "Entrez le nouveau prenom : ";
            std::cin >> tse.prenom;
            std::cout << "Entrez le nouvel age : ";
            std::cin >> tse.age;
            // etc. selon les attributs
            std::cout << "Modification réussie.\n";
            return;
        }
    }
    std::cout << "Aucun travailleur social événementiel trouvé avec l'ID donné.\n";
}

void TravailleurSocialEvenementiel::supprimerTravailleurSocialEvenementiel(std::vector<TravailleurSocialEvenementiel>& list, int idRecherche) {
    auto it = std::remove_if(list.begin(), list.end(), [idRecherche](const TravailleurSocialEvenementiel& tse) {
        return tse.getId() == idRecherche;
    });

    if (it != list.end()) {
        list.erase(it, list.end());
        std::cout << "Suppression réussie.\n";
    } else {
        std::cout << "Aucun travailleur social événementiel trouvé avec l'ID donné.\n";
    }
}

// Specific Methods
void TravailleurSocialEvenementiel::inscrireAUneFormation(SansAbri& s, Formation& f) {
    f.ajouterParticipant(std::make_unique<SansAbri>(s));
    std::cout << "Sans-abri inscrit à la formation.\n";
}

void TravailleurSocialEvenementiel::inscrireAUneAtelier(SansAbri& s, Atelier& a) {
    a.ajouterParticipant(std::make_unique<SansAbri>(s));
    std::cout << "Sans-abri inscrit à l'atelier.\n";
}

void TravailleurSocialEvenementiel::planifierEvenement(Evenement& evenement, const string& date, const string& lieu, const string& description, const vector<unique_ptr<TravailleurSocialEvenementiel>>& responsable) {
    vector<unique_ptr<SansAbri>> participants;  // Empty vector of participants
    evenement.planifier(date, lieu, description);
}

void TravailleurSocialEvenementiel::annulerEvenement(Evenement& evenement) {
    evenement.annuler();
}

void TravailleurSocialEvenementiel::modifierEvenement(Evenement& evenement) {
    string date, lieu, description;
    cout << "Entrez la nouvelle date: ";
    cin >> date;
    cout << "Entrez le nouveau lieu: ";
    cin >> lieu;
    cout << "Entrez la nouvelle description: ";
    cin >> description;
    evenement.modifier(date, lieu, description);
}

void TravailleurSocialEvenementiel::ajouterEvenement(Evenement& evenement) {
    evenement.ajouter();
}

void TravailleurSocialEvenementiel::supprimerEvenement(Evenement& evenement) {
    evenement.annuler();
}

// Operator Overloading
std::ostream& operator<<(std::ostream& os, const TravailleurSocialEvenementiel& tse) {
    os << "Nom: " << tse.nom << ", Prenom: " << tse.prenom << ", Age: " << tse.age << ", ID: " << tse.id;
    return os;
}

std::istream& operator>>(std::istream& is, TravailleurSocialEvenementiel& tse) {
    std::cout << "Nom: ";
    is >> tse.nom;
    std::cout << "Prenom: ";
    is >> tse.prenom;
    std::cout << "Age: ";
    is >> tse.age;
    std::cout << "ID: ";
    is >> tse.id;
    return is;
}

// Operator ==
bool TravailleurSocialEvenementiel::operator==(const TravailleurSocialEvenementiel& other) const {
    return id == other.id; // ou comparer d'autres champs si besoin
}
