#ifndef PERSONNE_H
#define PERSONNE_H

class Personne {
protected:
    char nom[50];
    char prenom[50];
    int age;

public:
    Personne();
    Personne(const char* n, const char* p, int a);
    virtual void saisirInfos();
    virtual void afficherInfos();
    virtual void modifierInfos(const char* nouveauNom, const char* nouveauPrenom, int nouvelAge);
};

#endif
