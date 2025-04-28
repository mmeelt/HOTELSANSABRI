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

void Administrateur::createUser(string nom, string prenom, int age, int id, string& username, string& password, string& role, unique_ptr<Archive>& archive) {
    if (archive->accessControlMap.find({username, password}) != archive->accessControlMap.end()) {
        cout << "User already exists in the archive." << endl;
        return;
    }

    unique_ptr<Utilisateur> user;
    if (role == "Administrateur") {
        user = make_unique<Administrateur>(nom, prenom, age, id, username, password);
    } else if (role == "RespBloc") {
        vector<unique_ptr<Bloc>> blocs;
        cout << "Enter the number of blocs to add: ";
        int numBlocs;
        cin >> numBlocs;
        cin.ignore(); // Clear the input buffer

        for (int i = 0; i < numBlocs; ++i) {
            cout << "Enter the ID of bloc " << i + 1 << ": ";
            int blocId;
            cin >> blocId;
            cin.ignore(); // Clear the input buffer

            unique_ptr<Bloc> bloc = archive->retrieveBlocFromArchive(blocId);
            if (bloc) {
                blocs.push_back(move(bloc));
                cout << "Bloc with ID " << blocId << " added successfully." << endl;
            } else {
                cout << "Bloc with ID " << blocId << " not found in the archive." << endl;
            }
        }

        user = make_unique<RespBloc>(nom, prenom, age, id, username, password, move(blocs));
        dynamic_cast<RespBloc*>(user.get())->updateSaturationGlobale();
        dynamic_cast<RespBloc*>(user.get())->updateCapaciteGlobale();
    } else if (role == "Receptioniste") {
        // TODO: Initialize Receptioniste with appropriate parameters
    } else if (role == "TravailleurSocial") {
        // TODO: Initialize TravailleurSocial with appropriate parameters
    } else if (role == "RespEvenmentiel") {
        // TODO: Initialize RespEvenementiel with appropriate parameters
    } else if (role == "Gestionnaire") {
        vector<unique_ptr<Bloc>> blocs;
        cout << "Enter the number of blocs to add: ";
        int numBlocs;
        cin >> numBlocs;
        cin.ignore(); // Clear the input buffer

        for (int i = 0; i < numBlocs; ++i) {
            cout << "Enter the ID of bloc " << i + 1 << ": ";
            int blocId;
            cin >> blocId;
            cin.ignore(); // Clear the input buffer

            unique_ptr<Bloc> bloc = archive->retrieveBlocFromArchive(blocId);
            if (bloc) {
                blocs.push_back(move(bloc));
                cout << "Bloc with ID " << blocId << " added successfully." << endl;
            } else {
                cout << "Bloc with ID " << blocId << " not found in the archive." << endl;
            }
        }

        user = make_unique<Gestionnaire>(nom, prenom, age, id, username, password, move(blocs));
        dynamic_cast<Gestionnaire*>(user.get())->updateSaturationGlobale();
        dynamic_cast<Gestionnaire*>(user.get())->updateCapaciteGlobale();
    } else if (role == "TravailleurSocialEvenmentiel") {
        // TODO: Initialize TravailleurSocialEvenementiel with appropriate parameters
    } else {
        cout << "Invalid role specified." << endl;
        return;
    }

    // Store the user in the database
    archive->ajouterUtilisateurDansDatabase(move(user)); // Use archive method to add the user
    archive->accessControlMap[{username, password}] = role; // Store the access control information
    cout << "User " << username << " with role " << role << " created successfully." << endl;
}

void Administrateur::readUser(string& username, unique_ptr<Archive>& archive) {
    unique_ptr<Utilisateur> user = archive->trouverUtilisateurParNom(username); // Wrap raw pointer in unique_ptr
    if (!user) {
        cout << "User not found." << endl;
        return;
    }
    cout << "User found: " << username << endl;
    cout << *user; // Assuming operator<< is overloaded for Utilisateur to display user details
    cout << "Role: " << archive->accessControlMap[{username, user->getMdp()}] << endl; // Display the role of the user
}

void Administrateur::updateUser(string& username, string& newPassword, unique_ptr<Archive>& archive) {
    unique_ptr<Utilisateur> user = archive->trouverUtilisateurParNom(username); // Wrap raw pointer in unique_ptr
    if (!user) {
        cout << "User not found." << endl;
        return;
    }
    user->setMdp(newPassword); // Update the password
    cout << "Password for user " << username << " updated successfully." << endl;
}

void Administrateur::deleteUser(string& username, unique_ptr<Archive>& archive) {
    unique_ptr<Utilisateur> user = archive->trouverUtilisateurParNom(username); // Wrap raw pointer in unique_ptr
    if (!user) {
        cout << "User not found." << endl;
        return;
    }
    archive->supprimerUtilisateurDeDatabase(move(user)); // Use archive method to remove the user
    archive->accessControlMap.erase({username, user->getMdp()}); // Remove the access control information
    cout << "User " << username << " deleted successfully." << endl;
}
