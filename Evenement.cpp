#include "Evenement.h"
#include <iostream>
using namespace std;

Evenement::Evenement(const std::string& d, const std::string& l, const std::string& desc, TravailleurSocialEvenementiel* r)
    : date(d), lieu(l), description(desc), resp(r) {}

Evenement::Evenement() : date(""), lieu(""), description(""), resp(nullptr) {}

void Evenement::afficherInfo() const {
    std::cout << "Date: " << date << "\nLieu: " << lieu << "\nDescription: " << description << std::endl;
}

void Evenement::saisirInfos() {
    std::cout << "Entrez la date de l'événement : ";
    std::getline(std::cin >> std::ws, date); // use getline with whitespace trimming

    std::cout << "Entrez le lieu de l'événement : ";
    std::getline(std::cin >> std::ws, lieu);

    std::cout << "Entrez la description de l'événement : ";
    std::getline(std::cin >> std::ws, description);

    // You can later link this to an actual resp object by asking for ID or name
    resp = nullptr;
}
