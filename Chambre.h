#ifndef CHAMBRE_H
#define CHAMBRE_H

class Chambre {
private:
    int numero;
    int blocId;
    bool estOccupee;

public:
    Chambre();
    Chambre(int numero, int blocId, bool occupee);

    void afficherInfos();
    int getNumero() const;
    int getBlocId() const;
    bool estLibre() const;
};

#endif
