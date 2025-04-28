#include "RespEvenementiel.h"
#include <algorithm> // Pour std::find_if, std::remove_if
#include <string>

RespEvenementiel::RespEvenementiel(string nom, string prenom, int age, int id, string& username, string& mdp, vector<unique_ptr<Evenement>> evenements)
    : Utilisateur(nom, prenom, age, id, username, mdp), evenements(std::move(evenements)) {}
// CRUD methods
void RespEvenementiel::modifierRespEvenementiel(vector<RespEvenementiel*>& respList, int idRecherche) {
    for (auto& resp : respList) {
        if (resp->getId() == idRecherche) {
            cout << "Modifier le nom : ";
            cin >> resp->nom;
            cout << "Modifier le prénom : ";
            cin >> resp->prenom;
            cout << "Modifier l'âge : ";
            cin >> resp->age;
            // etc. selon les champs que tu veux modifier
            cout << "Modification réussie.\n";
            return;
        }
    }
    cout << "Aucun responsable événementiel trouvé avec l'ID donné.\n";
}

void RespEvenementiel::supprimerRespEvenementiel(vector<RespEvenementiel*>& respList, int idRecherche) {
    auto it = std::remove_if(respList.begin(), respList.end(),
                             [idRecherche](RespEvenementiel* resp) { return resp->getId() == idRecherche; });

    if (it != respList.end()) {
        delete *it; // Supprimer l'objet pointé pour éviter une fuite mémoire
        respList.erase(it, respList.end());
        cout << "Suppression réussie.\n";
    } else {
        cout << "Aucun responsable événementiel trouvé avec l'ID donné.\n";
    }
}

// Specific Methods
void RespEvenementiel::inscrireAUneFormation(SansAbri s, Formation* f) {
    if (f) {
        f->ajouterParticipant(std::make_unique<SansAbri>(s)); // Assuming ajouterParticipant takes a unique_ptr
        cout << "Sans-abri inscrit à la formation.\n";
    } else {
        cout << "Formation invalide.\n";
    }
}

void RespEvenementiel::inscrireAUneAtelier(SansAbri s, Atelier* a) {
    if (a) {
        a->ajouterParticipant(std::make_unique<SansAbri>(s)); // Assuming ajouterParticipant takes a unique_ptr
        cout << "Sans-abri inscrit à l'atelier.\n";
    } else {
        cout << "Atelier invalide.\n";
    }
}

void RespEvenementiel::planifierEvenement(unique_ptr<Evenement> evenement) {
    if (evenement) {
        cout << "Planification de l'événement : " << endl;
        evenements.push_back(std::move(evenement));
    }
}

void RespEvenementiel::annulerEvenement(Evenement* evenement) {
    if (!evenement) return;

    auto it = std::find_if(evenements.begin(), evenements.end(),
                           [evenement](const unique_ptr<Evenement>& e) { return e.get() == evenement; });

    if (it != evenements.end()) {
        cout << "Événement annulé : " << endl;
        evenements.erase(it);
    } else {
        cout << "Événement non trouvé.\n";
    }
}

void RespEvenementiel::modifierEvenement(Evenement* evenement) {
    if (evenement) {
        cout << "Modification de l'événement : " << endl;
        evenement->modifier(evenement->getDate(), evenement->getLieu(), evenement->getDescription());
    }
}

void RespEvenementiel::ajouterEvenement(unique_ptr<Evenement> evenement) {
    if (evenement) {
        evenements.push_back(std::move(evenement));
        cout << "Événement ajouté.\n";
    }
}

void RespEvenementiel::supprimerEvenement(Evenement* evenement) {
    if (!evenement) return;

    auto it = std::find_if(evenements.begin(), evenements.end(),
                           [evenement](const unique_ptr<Evenement>& e) { return e.get() == evenement; });

    if (it != evenements.end()) {
        cout << "Suppression de l'événement : " << endl;
        evenements.erase(it);
    } else {
        cout << "Événement non trouvé.\n";
    }
}

// Getters and Setters
vector<Evenement*> RespEvenementiel::getEvenements() const {
    vector<Evenement*> rawPointers;
    for (const auto& e : evenements) {
        rawPointers.push_back(e.get());
    }
    return rawPointers;
}

void RespEvenementiel::setEvenements(vector<unique_ptr<Evenement>> nouveauxEvenements) {
    evenements = std::move(nouveauxEvenements);
}

// Operator Overloading
ostream& operator<<(ostream& os, const RespEvenementiel& resp) {
    os << "Nom: " << resp.nom << ", Prénom: " << resp.prenom << ", Âge: " << resp.age << ", ID: " << resp.id;
    return os;
}

istream& operator>>(istream& is, RespEvenementiel& resp) {
    cout << "Nom: ";
    is >> resp.nom;
    cout << "Prénom: ";
    is >> resp.prenom;
    cout << "Âge: ";
    is >> resp.age;
    cout << "ID: ";
    is >> resp.id;
    return is;
}
