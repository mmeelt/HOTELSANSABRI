#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <memory> // For std::unique_ptr
#include "SansAbri.h"
#include "Chambre.h"
using namespace std;

class Reservation {
private:
    unique_ptr<SansAbri> client; // Client making the reservation
    unique_ptr<Chambre> chambre; // Room being reserved
    string dateArrivee; // Check-in date
    string dateDepart; // Check-out date

public:
    // Constructor
    Reservation(unique_ptr<SansAbri> client, unique_ptr<Chambre> chambre, const string& checkIn, const string& checkOut) 
        : client(move(client)), chambre(move(chambre)), dateArrivee(checkIn), dateDepart(checkOut) {};
    // Destructor
    ~Reservation() = default; // Default destructor as unique_ptr handles cleanup

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
    void changerChambre(unique_ptr<Chambre> nouvelleChambre);

    bool operator==(const Reservation& other) const {
        // Compare relevant fields of Reservation
        return (client.get() == other.client.get() &&
                chambre.get() == other.chambre.get() &&
                dateArrivee == other.dateArrivee &&
                dateDepart == other.dateDepart);
    }
};

#endif // RESERVATION_H