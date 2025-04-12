#ifndef DOSSIERMEDICAL_H
#define DOSSIERMEDICAL_H

class DossierMedical {
private:
    int idDossier;
    char diagnostics[200];
    char traitements[200];
    char dateDerniereMaj[20];

public:
    DossierMedical();
    DossierMedical(int id, const char* diag, const char* trait, const char* dateMaj);

    void afficherDossier();
    void mettreAJour(const char* nouveauDiag, const char* nouveauTrait, const char* nouvelleDate);
    int getIdDossier();
};

#endif
