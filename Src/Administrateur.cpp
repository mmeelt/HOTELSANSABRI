#include <string>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <unordered_map>
#include <memory>
#include "../Headers/Administrateur.h"
#include "../Headers/RespBloc.h"
#include "../Headers/Receptioniste.h"
#include "../Headers/TravailleurSocial.h"
#include "../Headers/RespEvenementiel.h"
#include "../Headers/Gestionnaire.h"
#include "../Headers/TravailleurSocialEvenementiel.h"
#include "../Headers/Archive.h"

using namespace std;

void Administrateur::createUser(string nom, string prenom, int age, int id, string& username, string& password, string& role, Archive& archive) {
    if (archive.accessControlMap.find({username, password}) != archive.accessControlMap.end()) {
        cout << "User already exists in the archive." << endl;
        return;
    }

    unique_ptr<Utilisateur> user;
    if (role == "Administrateur") {
        Administrateur admin(nom, prenom, age, id, username, password);
    } else if (role == "RespBloc") {
        vector<Bloc*> blocs;
        cout << "Enter the number of blocs to add: ";
        int numBlocs;
        cin >> numBlocs;
        cin.ignore(); // Clear the input buffer

        for (int i = 0; i < numBlocs; ++i) {
            cout << "Enter the ID of bloc " << i + 1 << ": ";
            int blocId;
            cin >> blocId;
            cin.ignore(); // Clear the input buffer

            Bloc* bloc = archive.retrieveBlocFromArchive(blocId);
            if (bloc) {
                blocs.push_back(bloc);
                cout << "Bloc with ID " << blocId << " added successfully." << endl;
            } else {
                cout << "Bloc with ID " << blocId << " not found in the archive." << endl;
            }
        }

        cin.ignore(); // Clear the input buffer
        RespBloc respBloc(nom, prenom, age, id, username, password, blocs);
        respBloc.updateSaturationGlobale();
        respBloc.updateCapaciteGlobale();
    } else if (role == "Receptioniste") {
        // TODO: Initialize Receptioniste with appropriate parameters
    } else if (role == "TravailleurSocial") {
        // TODO: Initialize TravailleurSocial with appropriate parameters
    } else if (role == "RespEvenmentiel") {
        // TODO: Initialize RespEvenementiel with appropriate parameters
    } else if (role == "Gestionnaire") {
        vector<Bloc*> blocs;
        cout << "Enter the number of blocs to add: ";
        int numBlocs;
        cin >> numBlocs;
        cin.ignore(); // Clear the input buffer

        for (int i = 0; i < numBlocs; ++i) {
            cout << "Enter the ID of bloc " << i + 1 << ": ";
            int blocId;
            cin >> blocId;
            cin.ignore(); // Clear the input buffer

            Bloc* bloc = archive.retrieveBlocFromArchive(blocId);
            if (bloc) {
                blocs.push_back(bloc);
                cout << "Bloc with ID " << blocId << " added successfully." << endl;
            } else {
                cout << "Bloc with ID " << blocId << " not found in the archive." << endl;
            }
        }
        cin.ignore(); // Clear the input buffer
        Gestionnaire gestionnaire(nom, prenom, age, id, username, password, blocs);
        gestionnaire.updateSaturationGlobale();
        gestionnaire.updateCapaciteGlobale();
    } else if (role == "TravailleurSocialEvenmentiel") {
        // TODO: Initialize TravailleurSocialEvenementiel with appropriate parameters
    } else {
        cout << "Invalid role specified." << endl;
        return;
    }

    // Store the user in the database
    archive.ajouterUtilisateurDansDatabase(user.get()); // Use archive method to add the user
    archive.accessControlMap[{username, password}] = role; // Store the access control information
    cout << "User " << username << " with role " << role << " created successfully." << endl;
}

void Administrateur::readUser(string& username, Archive& archive) {
    Utilisateur* user = archive.trouverUtilisateurParNom(username); // Use archive method to find the user
    if (!user) {
        cout << "User not found." << endl;
        return;
    }
    cout << "User found: " << username << endl;
    cout << *user; // Assuming operator<< is overloaded for Utilisateur to display user details
    cout << "Role: " << archive.accessControlMap[{username, user->getMdp()}] << endl; // Display the role of the user
}

void Administrateur::updateUser(string& username, string& newPassword, Archive& archive) {
    Utilisateur* user = archive.trouverUtilisateurParNom(username); // Use archive method to find the user
    if (!user) {
        cout << "User not found." << endl;
        return;
    }
    user->setMdp(newPassword); // Update the password
    cout << "Password for user " << username << " updated successfully." << endl;
}

void Administrateur::deleteUser(string& username, Archive& archive) {
    Utilisateur* user = archive.trouverUtilisateurParNom(username); // Use archive method to find the user
    if (!user) {
        cout << "User not found." << endl;
        return;
    }
    archive.supprimerUtilisateurDeDatabase(user); // Use archive method to remove the user
    archive.accessControlMap.erase({username, user->getMdp()}); // Remove the access control information
    cout << "User " << username << " deleted successfully." << endl;
}
