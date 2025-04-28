#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <string>
#include "SansAbri.h"

class Chambre {
private:
    int numero;
    bool estLibre;
    std::string etat;

public:
    Chambre(int numero, bool estLibre, const std::string& etat);
    ~Chambre();
    void attribuer(SansAbri* sansAbri);
    void liberer();
    string getEtat();
    int getRoomNumber();
    void setRoomNumber(int roomNumber);
};

#endif // CHAMBRE_H