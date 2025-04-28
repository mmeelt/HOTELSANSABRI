#ifndef CHAMBRE_H
#define CHAMBRE_H

#include <string>
#include <vector>
#include <memory> // For std::unique_ptr
#include "SansAbri.h"

class Chambre {
private:
    int numero;
    bool estLibre;
    std::string etat;
    std::vector<std::unique_ptr<SansAbri>> occupants; // Unique pointers to the occupants of the room
    int capacite; // Maximum capacity of the room
public:
    Chambre(int numero, bool estLibre, const std::string& etat);
    ~Chambre();
    void attribuer(unique_ptr<SansAbri> sansAbri); // Accept unique_ptr for assignment
    void liberer();
    std::string getEtat() const;
    int getRoomNumber() const;
    void setRoomNumber(int roomNumber);
    int getOccupants() const;
    int getCapacite() const;
    void setCapacite(int capacite);
    void afficherInfos() const; // Display room information
};

#endif // CHAMBRE_H