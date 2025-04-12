#include <iostream>
#include <cstring>
#include "SansAbri.h"
#include "Utilisateur.h"
#include "Receptionniste.h"
#include "Reservation.h"
#include "EvenementFormation.h"
#include "TravailleurSocialEvenementiel.h"

using namespace std;

int main() {
    // --------- Create a SansAbri object ----------
    int id, age;
    char nom[50], prenom[50], situation[100];
    bool besoinSoins;

    cout << "\n--- Ajout d'un Sans-Abri ---" << endl;
    cout << "ID : ";
    cin >> id;
    cin.ignore(); // Clear newline
    cout << "Nom : ";
    cin.getline(nom, 50);
    cout << "Prenom : ";
    cin.getline(prenom, 50);
    cout << "Age : ";
    cin >> age;
    cin.ignore();
    cout << "Situation actuelle : ";
    cin.getline(situation, 100);
    cout << "A besoin de soins ? (1 = Oui, 0 = Non): ";
    cin >> besoinSoins;

    SansAbri sa(id, nom, prenom, age, situation, besoinSoins);
    sa.afficherInfos();

    // --------- Create a Reservation ----------
    int chambre, beneficiaire;
    char dateRes[20];
    cout << "\n--- Nouvelle Réservation ---" << endl;
    cout << "Numéro de chambre : ";
    cin >> chambre;
    cout << "ID du bénéficiaire : ";
    cin >> beneficiaire;
    cin.ignore();
    cout << "Date de réservation (jj/mm/aaaa) : ";
    cin.getline(dateRes, 20);

    Reservation r(chambre, beneficiaire, dateRes);
    r.afficherInfos();

    // --------- Create a Receptionniste ----------
    char role[20], idU[20], mdp[20];
    int numPoste;
    cout << "\n--- Création Réceptionniste ---" << endl;
    cout << "Nom : ";
    cin.getline(nom, 50);
    cout << "Prenom : ";
    cin.getline(prenom, 50);
    cout << "Age : ";
    cin >> age;
    cin.ignore();
    cout << "Role : ";
    cin.getline(role, 20);
    cout << "Identifiant : ";
    cin.getline(idU, 20);
    cout << "Mot de passe : ";
    cin.getline(mdp, 20);
    cout << "Numéro de poste : ";
    cin >> numPoste;
    cin.ignore();

    Receptionniste rec(nom, prenom, age, role, idU, mdp, numPoste);
    rec.afficherInfos();

    // --------- Create an EvenementFormation ----------
    char titre[50], lieu[50], description[100], formateur[50], dateEvt[20];
    cout << "\n--- Ajout Formation ---" << endl;
    cout << "Titre : ";
    cin.getline(titre, 50);
    cout << "Date : ";
    cin.getline(dateEvt, 20);
    cout << "Lieu : ";
    cin.getline(lieu, 50);
    cout << "Description : ";
    cin.getline(description, 100);
    cout << "Formateur : ";
    cin.getline(formateur, 50);

    EvenementFormation ef(titre, dateEvt, lieu, nullptr, formateur);
    ef.afficherInfo();

    // --------- Create a TravailleurSocialEvenementiel ----------
    char secteur[50], typeEvt[50];
    cout << "\n--- Ajout Travailleur Social Événementiel ---" << endl;
    cout << "Nom : ";
    cin.getline(nom, 50);
    cout << "Prenom : ";
    cin.getline(prenom, 50);
    cout << "Age : ";
    cin >> age;
    cin.ignore();
    cout << "Role : ";
    cin.getline(role, 20);
    cout << "Identifiant : ";
    cin.getline(idU, 20);
    cout << "Mot de passe : ";
    cin.getline(mdp, 20);
    cout << "Secteur : ";
    cin.getline(secteur, 50);
    cout << "Type d'événement : ";
    cin.getline(typeEvt, 50);

    TravailleurSocialEvenementiel tse(nom, prenom, age, role, idU, mdp, secteur, typeEvt);
    tse.afficherInfos();

    return 0;
}
