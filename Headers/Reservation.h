#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "SansAbri.h"
#include "Chambre.h"
using namespace std;

class Reservation {
private:
    SansAbri* client; // Client making the reservation
    Chambre* chambre; // Room being reserved
    string dateArrivee; // Check-in date
    string dateDepart; // Check-out date

public:
    // Constructor
    Reservation(SansAbri* client, Chambre* chambre, const string& checkIn, const string& checkOut) 
        : client(client), chambre(chambre), dateArrivee(checkIn), dateDepart(checkOut) {};
    // Destructor	
    ~Reservation();	
    // Getters
    int getReservationID() const;
    string getCustomerName() const;
    int getRoomNumber() const;
    string getCheckInDate() const;
    string getCheckOutDate() const;

    // Setters
    void setCustomerName(const std::string& name);
    void setRoomNumber(int room);
    void setCheckInDate(const std::string& checkIn);
    void setCheckOutDate(const std::string& checkOut);

    // Other methods
    void displayReservationDetails() const;
    void prolongerSejour(const string& newCheckOutDate);
    void annulerReservation();
    void changerChambre(Chambre* nouvelleChambre);

    bool operator==(const Reservation& other) const {
        // Compare relevant fields of Reservation
        return (client == other.client &&
                chambre == other.chambre &&
                dateArrivee == other.dateArrivee &&
                dateDepart == other.dateDepart);
    }
    
};

#endif // RESERVATION_H