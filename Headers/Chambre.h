#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <string>
#include "SansAbri.h"

class Chambre {
private:
    int numero;
    bool estLibre;
    std::string etat;
    vector<SansAbri*> occupants; // Pointer to the occupant of the room
    int capacite; // Maximum capacity of the room
public:
    Chambre(int numero, bool estLibre, const std::string& etat);
    ~Chambre();
    void attribuer(SansAbri* sansAbri);
    void liberer();
    string getEtat();
    int getRoomNumber();
    void setRoomNumber(int roomNumber);
    int getOccupants() const;
    int getCapacite() const;
    void setCapacite(int capacite);
    void afficherInfos() const; // Display room information
};

#endif // CHAMBRE_H