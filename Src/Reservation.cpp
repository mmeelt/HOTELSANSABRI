#include "../Headers/Reservation.h"
#include <iostream>
#include <string>
#include <memory> // For std::unique_ptr

using namespace std;

// Constructor
Reservation::Reservation(unique_ptr<SansAbri> client, unique_ptr<Chambre> chambre, const string& checkIn, const string& checkOut) 
        : client(move(client)), chambre(move(chambre)), dateArrivee(checkIn), dateDepart(checkOut) {}

// Getters
int Reservation::getReservationID() const {
    return client->getId();
}

string Reservation::getCustomerName() const {
    return client->getNom();
}

int Reservation::getRoomNumber() const {
    return chambre->getRoomNumber();
}

string Reservation::getCheckInDate() const {
    return dateArrivee;
}

string Reservation::getCheckOutDate() const {
    return dateDepart;
}

// Setters
void Reservation::setCustomerName(const std::string& name) {
    client->setNom(name);
}

void Reservation::setRoomNumber(int room) {
    chambre->setRoomNumber(room);
}

void Reservation::setCheckInDate(const std::string& checkIn) {
    dateArrivee = checkIn;
}

void Reservation::setCheckOutDate(const std::string& checkOut) {
    dateDepart = checkOut;
}

// Other methods
void Reservation::displayReservationDetails() const {
    cout << "Reservation Details:" << endl;
    cout << "Client ID: " << client->getId() << endl;
    cout << "Client Name: " << client->getNom() << endl;
    cout << "Room Number: " << chambre->getRoomNumber() << endl;
    cout << "Check-in Date: " << dateArrivee << endl;
    cout << "Check-out Date: " << dateDepart << endl;
}

void Reservation::prolongerSejour(const string& newCheckOutDate) {
    dateDepart = newCheckOutDate;
    cout << "Stay prolonged. New check-out date: " << dateDepart << endl;
}

void Reservation::annulerReservation() {
    cout << "Reservation for client " << client->getNom() << " has been canceled." << endl;
    client.reset();
    chambre.reset();
}

void Reservation::changerChambre(unique_ptr<Chambre> nouvelleChambre) {
    chambre = move(nouvelleChambre);
    cout << "Room changed successfully to room number: " << chambre->getRoomNumber() << endl;
}