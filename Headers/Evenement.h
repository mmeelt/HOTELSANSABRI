#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <string>
#include "TravailleurSocialEvenementiel.h" // Assuming TravailleurSocialEvenementiel is defined in this header file

class Evenement {
private:
    std::string date;
    std::string lieu;
    std::string description;
    TravailleurSocialEvenementiel* resp;

public:
    // Constructor
    Evenement(const std::string& date, const std::string& lieu, const std::string& description, TravailleurSocialEvenementiel* resp)
        : date(date), lieu(lieu), description(description), resp(resp) {}

    // Method to display event information
    void afficherInfo() const {
        std::cout << "Date: " << date << "\n"
                  << "Lieu: " << lieu << "\n"
                  << "Description: " << description << "\n"
                  << "Responsable: " << resp->nom << std::endl;
    }
};

#endif // EVENEMENT_H