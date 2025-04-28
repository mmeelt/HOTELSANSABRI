#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H

#include "Administrateur.h"
#include "RespBloc.h"
#include "Bloc.h"
#include "Chambre.h"
#include <vector>

class Gestionnaire : public Administrateur, public RespBloc
{
public:
    // Constructeur par défaut
    Gestionnaire(string nom, string prenom, int age, int id, string& username, string& mdp, vector<Bloc*> blocs = {}, float saturationGlobale = 0.0, int capaciteGlobale = 0)
        : Utilisateur(nom, prenom, age, id, username, mdp), Administrateur(nom, prenom, age, id, username, mdp), RespBloc(nom, prenom, age, id, username, mdp, blocs) {}

    // Destructeur
    ~Gestionnaire();

    // Ajouter un bloc
    void ajouterBloc(const Bloc &bloc);

    // Lire tous les blocs
    vector<Bloc*> lireBlocs() const;

    // Mettre à jour un bloc
    void mettreAJourBloc(int blocId, const Bloc &bloc);

    // Supprimer un bloc
    void supprimerBlocParId(int blocId);
    // Gérer un bloc
    void gererBloc(Bloc bloc);

    // Supprimer un bloc par son ID
    void supprimerBloc(int blocId);

    // Trouver un bloc par son ID
    Bloc trouverBlocParId(int blocId);

    // Ajouter une chambre dans un bloc
    void ajouterChambreDansBloc(int blocId, Chambre chambre);

    // Supprimer une chambre d'un bloc
    void supprimerChambreDansBloc(int blocId, int chambreNumero);

    // Afficher les chambres d'un bloc
    void afficherChambresBloc(int blocId);

    // Afficher les statistiques de l'hôtel
    void afficherStatistiquesHotel();
};

#endif // GESTIONNAIRE_H